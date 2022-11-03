#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;

int main ()
{
	SetConsoleOutputCP(1252);
	b:
	wcout <<"   Program Criptat/Decriptat fisiere '.txt' folosind o parola     "<<(wchar_t)0xA9<< " Neleptcu Daniel-Andrei" <<endl<< endl;
	char fisier1[1000];
	cout<<"Introduceti numele sursei ( ex: 'sursa.txt') -> ";
	cin.get(fisier1,999);
	cin.get();
	ifstream textin(fisier1);
	ofstream textout;
	char fisier2[1000];
	cout<<endl<<"Introduceti numele destinatiei ( ex: 'destinatie.txt') -> ";
	cin.get(fisier2,999);
	cin.get();
	cout<<endl<<"Criptare/Decriptare: (c/d)?  ->";
	a:
	switch (getch())
	{
		case 'c':{
			char parola[101];
			cout<<endl<<endl<<"Parola -> ";
			char pen;
			int i=0;
			while (1)
			{
				pen=getch();
				if (pen=='\r')
				{
					break;
				}
				else 
				{
					parola[i]=pen;
					i++;
				}
			}
			char c;
			unsigned char x;
			i=0;
			textout.open(fisier2, std::ios_base::app);
			while(textin.get(c))
			{
				x=c;
				x=x+parola[(i++)%strlen(parola)];
				textout<<x;
			}
			cout<<endl<<endl<<"Done.";
			break;
			}
			case 'd':{
			char parola[101];
			cout<<endl<<endl<<"Parola -> ";
			char pen;
			int i=0;
			while (1)
			{
				pen=getch();
				if (pen=='\r')
				{
					break;
				}
				else 
				{
					parola[i]=pen;
					i++;
				}
			}
			char c;
			unsigned char x;
			i=0;
			textout.open(fisier2, std::ios_base::app);
			while(textin.get(c))
			{
				x=c;
				x=x-parola[(i++)%strlen(parola)];
				textout<<x;
			}
			cout<<endl<<endl<<"Done.";
			break;
			}
			default:{
				goto a;
				break;
			}
	}
	cout<<endl<<endl<<"  Apasa 'y' pentru a rula programul din nou sau orice altceva pentru a inchide."<<endl<<endl<<endl;
	fflush(stdin);
	char pen;
	cout<<"                                      ";
	pen=getch();
	if(pen=='y')
	{
		system("cls");
		goto b;
	}
	return 0;
}

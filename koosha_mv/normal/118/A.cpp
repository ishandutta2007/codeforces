#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int t;
	cin >> s;
	t=s.size();
	for(int i=0;i<t;i++)
	{
		if(s[i]!='a'  && s[i]!='A' && s[i]!='E' && s[i]!='e' && s[i]!='O' && s[i]!='o' && s[i]!='Y' && s[i]!='y' &&s[i]!='U' &&s[i]!='u' &&s[i]!='I' &&s[i]!='i')
		{
			if(s[i]=='b' || s[i]=='B')
				cout << '.' << 'b';
			if(s[i]=='c' || s[i]=='C')
				cout << '.' << 'c';
			if(s[i]=='d' || s[i]=='D')
				cout << '.' << 'd';
			if(s[i]=='f' || s[i]=='F')
				cout << '.' << 'f';
			if(s[i]=='g' || s[i]=='G')
				cout << '.' << 'g';
			if(s[i]=='h' || s[i]=='H')
				cout << '.' << 'h';
			if(s[i]=='j' || s[i]=='J')
				cout << '.' << 'j';
			if(s[i]=='k' || s[i]=='K')
				cout << '.' << 'k';
			if(s[i]=='l' || s[i]=='L')
				cout << '.' << 'l';
			if(s[i]=='m' || s[i]=='M')
				cout << '.' << 'm';
			if(s[i]=='n' || s[i]=='N')
				cout << '.' << 'n';
			if(s[i]=='p' || s[i]=='P')
				cout << '.' << 'p';
			if(s[i]=='q' || s[i]=='Q')
				cout << '.' << 'q';
			if(s[i]=='r' || s[i]=='R')
				cout << '.' << 'r';
			if(s[i]=='s' || s[i]=='S')
				cout << '.' << 's';
			if(s[i]=='t' || s[i]=='T')
				cout << '.' << 't';
			if(s[i]=='v' || s[i]=='V')
				cout << '.' << 'v';
			if(s[i]=='w' || s[i]=='W')
				cout << '.' << 'w';
			if(s[i]=='x' || s[i]=='X')
				cout << '.' << 'x';
			if(s[i]=='y' || s[i]=='Y')
				cout << '.' << 'y';
			if(s[i]=='z' || s[i]=='Z')
				cout << '.' << 'z';
		}
	}
}
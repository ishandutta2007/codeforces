#include<iostream>
using namespace std;
int main()
{
	int n,r=0,g=0,b=0;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R')
			r++;
		if(s[i]=='G')
			g++;
		if(s[i]=='B')
			b++;
	}
	if(r>0 && g>0 && b>0)
		cout<<"BGR";
	else
	{
		if(r>0 && g>0)
		{
			if(r==1 && g==1)
				cout<<"B";
			else
			{
				if(r==1)
					cout<<"BR";
				if(g==1)
					cout<<"BG";
				if(r!=1 && g!=1)
					cout<<"BGR";
			}
			return 0;
		}
		if(r>0 && b>0)
		{
			if(r==1 && b==1)
				cout<<"G";
			else
			{
				if(r==1)
					cout<<"GR";
				if(b==1)
					cout<<"BG";
				if(r!=1 && b!=1)
					cout<<"BGR";
			}
			return 0;
		}
		if(g>0 && b>0)
		{
			if(g==1 && b==1)
				cout<<"R";
			else
			{
				if(g==1)
					cout<<"GR";
				if(b==1)
					cout<<"BR";
				if(g!=1 && b!=1)
					cout<<"BGR";
			}
			return 0;
		}
		if(r>0)
			cout<<"R";
		if(g>0)
			cout<<"G";
		if(b>0)
			cout<<"B";
	}                 
}
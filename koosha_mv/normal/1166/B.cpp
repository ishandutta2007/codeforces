#include<iostream>
using namespace std;
string t(int x,int y)
{
	x=x%5;
	y=y%5;
	int t=x-y;
	if(t==-1 || t==4)
		return "e";
	if(t==0)
		return "a";
	if(t==-2 || t==3)
		return "o";
	if(t==-3 || t==2)
		return "i";
	return "u";
}
int main()
{
	int k;
	cin>>k;
	int sh=-1,sh2;
	for(int i=5;i<100;i++)
	{
		if(k%i==0 && k/i>=5)
		{
			sh=i;
			break;
		}
	}
	sh2=k/sh;
	if (sh==-1)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<sh;i++)
	{
		for(int j=0;j<sh2;j++)
		{
			cout<<t(i,j);
		}
	}
}
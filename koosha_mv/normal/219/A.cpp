#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	int k=0;
	string p;
	int a[28];
	memset(a, 0, sizeof(a));
	for(int i=0;i<s.size();i++)
	{
		a[int(s[i])-97]+=1;
	}
	int l=n;
	for(int i=0;i<28;i++)
	{
		if(a[i]%n!=0)
		{
			k=1;
			break;
		}
	}
	if(k==1)
	cout<<-1;
	else
	{
		for(int q=0;q<l;q++)
		{
		for(int i=0;i<28;i++)
		{
			if (n==0)
				break;
			
			for(int d=0;d<(a[i]/n);d++)
				cout<<char(i+97);
			a[i]-=(a[i]/n);
		}
		n-=1;
		}
	}
}
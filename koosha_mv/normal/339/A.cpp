#include<iostream>
#include<string>
using namespace std;
int a[100];
int n;
void bubble()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}	
	}
}	
int main()
{
	string s;
	int n,k;
	cin >> s;
	n=(s.size()+(s.size()%2))/2;
	int a[n],t=0;
	for(int i=0;i<s.size();i++)
	{
		if(i%2==0)
		{
			a[t]=s[i]-48;
			t=t+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}	
	}
	for(int i=n-1;i>-1;i--)
		if(i==n-1)
			cout << a[i];
		else
			cout << '+' << a[i];
}
#include<iostream>
using namespace std;
int a[201];
int main()
{
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.')
			a[j]=0;
		if(s[i]=='-')
		{
			if(s[i+1]=='.')
				a[j]=1;
			else
				a[j]=2;
			i++;
		}
		j++;
	}
	for(int i=0;i<j;i++)
		cout << a[i];
}
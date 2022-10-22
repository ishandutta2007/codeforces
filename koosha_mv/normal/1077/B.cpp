#include<iostream>
using namespace std;
int main()
{
	int t,a,p=0;
	cin >> t;
	int s[t];
	for(int i=0;i<t;i++)
	{
		cin >> s[i];	
	}
	for(int i=1;i<t-1;i++)
	{
		if(s[i-1]==1 && s[i]==0 && s[i+1]==1)
		{
		
			s[i+1]=0;
			p++; 
		}
	}
	cout << p;
}
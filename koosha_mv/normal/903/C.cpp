#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s[n];
	for(int i=0;i<n;i++)
		cin >> s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[j]>s[i])
				swap(s[i],s[j]);
		}
	}
	int k=s[0],k1=0,k2=0,k3;
	for(int i=0;i<n;i++)
	{
		if(s[i]==k)
			k1++;
		else
		{
			k1=1;
			k=s[i];
		}
		if(k1>k2)
			k2=k1;	
		
	}
	cout << k2;
}
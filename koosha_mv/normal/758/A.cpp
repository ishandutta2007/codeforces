#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s[n];
	for(int i=0;i<n;i++)
		cin >> s[i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[i]>s[j])
				swap(s[i],s[j]);
		}
	}
	int t=s[0],k=0;
	for(int i=0;i<n;i++)
	{
		k+=t-s[i];
	}
	cout<<k;
	
}
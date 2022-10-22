#include<iostream>
using namespace std;
int a[100001],t[200000]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ab,b=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int y=a[i]+a[j];
			t[y]++;
			if(t[a[i]+a[j]]>b)
				b=t[a[i]+a[j]];
		}
	}
	cout<<b;
}
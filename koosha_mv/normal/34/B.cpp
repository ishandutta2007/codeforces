#include<iostream>
using namespace std;
int main ()
{
	int n,n1,k=0,t=0;
	cin >> n >> n1;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]<0 && t<n1)
		{		
			k-=a[i];
			t++;
		}
	}
	cout << k;
}
#include<bits/stdc++.h>
using namespace std;
long long int a[59991];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
		for(int i=1;i<=n;i++)
		{
				if(a[i]%2==1)
				continue;
				else if(a[i]%2==0)
				a[i]--;
			}
	for(int i=1;i<=n-1;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<a[n];
}
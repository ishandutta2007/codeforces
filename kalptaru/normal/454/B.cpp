#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n],m=0;
	for(int i=0;i<n;i++)
	cin>>a[i];
	bool f=0;
	for(int i=1;i<n;i++)
	{
		if(f)
		{
			if(a[i]<a[i-1])
			{
				cout<<-1;
				return 0;
			}
		}
		else
		{
			if(a[i]<a[i-1])
			{
				m=i;
				f=1;
			}
		}
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	if(a[n-1]>a[0])
	{
		cout<<-1;
		return 0;
	}
	cout<<n-m;
	return 0;
}
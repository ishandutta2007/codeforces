#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,j=0;
	cin>>n>>q;
	ll a[n],m=0,t,y;
	vector<ll> k[2],o;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>m)
		{
			m=a[i];
			j=i;
		}
	}
	t=a[0];
	for(int i=j+1;i<n;i++)
	o.push_back(a[i]);
	for(int i=1;i<=j;i++)
	{
		k[0].push_back(t);
		k[1].push_back(a[i]);
		if(a[i]>t)
		{
			o.push_back(t);
			t=a[i];
		}
		else
		{
			o.push_back(a[i]);
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>y;
		if(y<=j)
		{
			cout<<k[0][y-1]<<' '<<k[1][y-1]<<"\n";
		}
		else
		{
			cout<<m<<' '<<o[(y-j-1)%(n-1)]<<"\n";
		}
	}
	return 0;
}
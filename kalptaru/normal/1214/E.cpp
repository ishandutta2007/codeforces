#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
int gcd(ll a,ll b)
{
	if(a%b==0)
	return b;
	else
	return(gcd(b,a%b));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		pair<int,int> d[n],k[n];
		FOR(i,0,n)
		{
			cin>>k[i].first;
			k[i].second=i;
		}
		vector<int> tree;
		sort(k,k+n);
		FOR(i,0,n)
		{
			d[i]=k[n-i-1];
			tree.push_back(2*d[i].second+1);
		}
		int l=n;
		FOR(i,0,n)
		{
			if(d[i].first+i==l)
			{
				tree.push_back(2*d[i].second+2);
				l++;
			}
			else
			{
				cout<<2*d[i].second+2<<' '<<tree[d[i].first+i-1]<<'\n';
			}
		}
		FOR(i,1,l)
		{
			cout<<tree[i]<<' '<<tree[i-1]<<'\n';
		}
	}
	return 0;
}
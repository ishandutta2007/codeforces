#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		int c=0;
		int m=0;
		int m2=0;
		int p=a[0];
		int o=1;
		FOR(i,0,n)
		{
			if(p==a[i])
			c++;
			else
			{
				o++;
				if(c>=m)
				{
					m2=m;
					m=c;
				}
				p=a[i];
				c=1;
			}
		}
		if(c>=m)
		{
			m2=m;
			m=c;
		}
		if(o==m)
		{
			cout<<o-1<<'\n';
		}
		else
		{
			cout<<min(o,m)<<'\n';
		}
	}
	return 0;
}
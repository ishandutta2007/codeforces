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
		ll n;
		cin>>n;
		int r=(n-1)%3;
		n=((n-1)/3);
		ll s=1;
		ll ans[3];
		while(n>=s)
		{
			n-=s;
			s*=4;
		}
		FOR(i,0,3)
		ans[i]=s*(1+i);
		s=1;
		while(n)
		{
			if(n%4!=0)
			{
				FOR(i,0,3)
				{
					ans[(i+1-(n%4)+3)%3]+=s*(1+i);
				}
			}
			s<<=2;
			n>>=2;
		}
		cout<<ans[r]<<'\n';
	}
	return 0;
}
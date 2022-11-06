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
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll mi3=499122177;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
	a=a%mod3;
	while(b>0)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod3;
		}
		a*=a;
		a%=mod3;
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
//	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		ll l[m];
		ll s=0;
		ll p[m];
		FOR(i,0,m)
		{
			cin>>l[i];
			s+=l[i];
		}
		if(s<n)
		{
			cout<<"-1";
			return 0;
		}
		ll ma=0;
		FOR(i,0,m)
		{
			s-=l[m-i-1];
			if(s<(n-ma))
			{
				ma=max(n-s,l[m-i-1]);
				
			}
			else
			{
				ma=max(ma+1,l[m-i-1]);
			}
			p[m-i-1]=n-ma+1;
			if(p[m-i-1]<1)
			{
				cout<<"-1";
				return 0;
			}
		}
		FOR(i,0,m)
		cout<<p[i]<<' ';
		
	}
	return 0;
}
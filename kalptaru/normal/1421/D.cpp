#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;

ll po(ll a,ll b)
{
	ll re=1;
	a%=mod;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	cin>>test;
	while(test--)
	{
		ll x,y;
		cin>>x>>y;
		ll c[6];
		FOR(i,0,6)
		{
			cin>>c[i];
		}
		FOR(i,0,6)
		{
			c[(i+1)%6]=min(c[(i+1)%6],c[i]+c[(i+2)%6]);
		}
		if(x>=y && y>=0)
		{
			cout<<y*c[0]+(x-y)*c[5]<<'\n';
		}
		else if(x>=y)
		{
			if(x>0)
			{
				cout<<abs(y)*c[4]+x*c[5]<<'\n';
			}
			else
			{
				cout<<(x-y)*c[4]+abs(x)*c[3]<<'\n';
			}
			
		}
		else if(x>=0)
		{
			cout<<x*c[0]+(y-x)*c[1]<<'\n';
		}
		else
		{
			if(y>0)
			{
				cout<<abs(x)*c[2]+y*c[1]<<'\n';
			}
			else
			{
				cout<<(y-x)*c[2]+abs(y)*c[3]<<'\n';
			}
		}
	}
	return 0;
}
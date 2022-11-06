#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
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
	ll re=1;
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
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		ll x;
		cin>>n>>x;
		ll d[n];
		FOR(i,0,n)
		cin>>d[i];
		ll ans=0;
		ll kis=0,p,q,r;
		int j=3*n-1;
		FORD(i,n,0)
		{
			while(x>0)
			{
				if(x>=d[j%n])
				{
					x-=d[j%n];
					kis+=((d[j%n]*(d[j%n]+1))/2);
					j--;
				}
				else
				{
					p=d[j%n];
					q=p-x;
					r=((p*(p+1))-(q*(q+1)))/2;
					break;
				}
			}
			if(x==0)
			{
				ans=max(ans,kis);
//				cout<<kis<<' ';
			}
			else
			{
				ans=max(ans,kis+r);
//				cout<<kis+r<<' ';
			}
			x+=d[i];
			kis-=((d[i]*(d[i]+1))/2);
		}
		cout<<ans;
	}
	return 0;
}
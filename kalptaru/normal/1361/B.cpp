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
	cin>>test;
	while(test--)
	{
		ll n,p;
		cin>>n>>p;
		ll k[n];
		FOR(i,0,n)
		cin>>k[i];
		sort(k,k+n,greater<ll>());
//		cout<<'s';
		int si[n];
		int pr=k[0];
		ll a=1,b=0;
		if(p==1)
		{
			if((n%2)==1)
			cout<<1<<'\n';
			else
			cout<<0<<'\n';
			continue;
		}
		int d=n;
		FOR(i,1,n)
		{
//			cout<<a<<' '<<b<<' '<<k[i];
			if(pr==k[i])
			{
				if(a<=b)
				{
					a++;
				}
				else
				{
					b++;
				}
//				cout<<'a'<<'\n';
			}
			else
			{
//				cout<<'d'<<'\n';
				if(a==b)
				{
					a=1;
					b=0;
					pr=k[i];
//					cout<<pr<<'l';
				}
				else
				{
					a-=b;
					b=1;
					while(pr>k[i])
					{
						a*=p;
						pr--;
						if(a>(n-i))
						{
							d=i;
							break;
						}
					}
					if(d!=n)
					break;
				}
			}
		}
		if(d==n)
		{
			a-=b;
		}
		a=((a*po(p,pr))%mod);
		FOR(i,d,n)
		{
			a=(a-po(p,k[i])+mod)%mod;
		}
		cout<<a<<'\n';
	}
	return 0;
}
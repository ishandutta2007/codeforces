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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
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
		int n,a,r,m;
		cin>>n>>a>>r>>m;
		ll h[n],s=0;
		FOR(i,0,n)
		{
			cin>>h[i];
			s+=h[i];
		}
		ll ans=INF,c,ad,re;
		sort(h,h+n);
		ll pre[n],suf[n];
		pre[0]=h[0];
		suf[n-1]=h[n-1];
		bool f=0;
		FOR(i,1,n)
		{
			pre[i]=h[i]+pre[i-1];
			suf[n-i-1]=h[n-i-1]+suf[n-i];
		}
		FOR(i,0,n)
		{
			ad=(i+1)*h[i]-pre[i];
			re=suf[i]-(n-i)*h[i];
			if(m<(a+r))
			{
				if(ad>re)
				{
					c=m*re+a*(ad-re);
					if(f==0)
					{
						ans=min(ans,c);
						f=1;
						ll hi=h[i],lo=h[i-1];
						ll mid;
						while(lo<hi)
						{
							mid=(lo+hi)/2;
//							cout<<mid<<' ';
							ad=(i)*mid-pre[i-1];
							re=suf[i]-(n-i)*mid;
							if(ad<re)
							{
								lo=mid+1;
								c=m*ad+r*(re-ad);
							}
							else
							{
								c=m*re+a*(ad-re);
								hi=mid;
							}
//							cout<<ad<<' '<<mid<<' '<<re<<'\n';
							ans=min(c,ans);
						}
					}
				}
				else
				{
					
					c=m*ad+r*(re-ad);
				}
			}
			else
			{
				c=a*ad+r*re;
			}
//			cout<<c<<' ';
			ans=min(ans,c);
//			cout<<ad<<' ';
		}		
		cout<<ans;
		
	}
	return 0;
}
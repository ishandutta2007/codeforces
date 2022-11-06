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
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		int ma=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		int cnt[ma+1]={0};
		FOR(i,0,n)
		{
			cnt[a[i]]++;
		}
		int u,v,x,y,l=1;
		FOR(i,1,ma+1)
		{
			if(cnt[i]!=(4*i))
			{
				l=i;
				break;
			}
		}
		int tcn[n]={0};
//		if(n==1000000)
//		cout<<l<<'\n';
		for(int i=1;(i*i)<=n;i++)
		{
			if(n%i==0)
			{
				u=i;
				v=n/i;
//				cout<<u<<' '<<v<<'\n';
				x=l;
				y=u+v-x-ma;
//				cout<<x<<' '<<y<<'\n';
				if(y>0 && y<=v)
				{
					FOR(j,1,u+1)
					{
						FOR(k,1,v+1)
						{
							tcn[abs(x-j)+abs(y-k)]++;
						}
					}
					bool f=1;
					FOR(j,0,ma+1)
					{
//						cout<<j<<' '<<tcn[j]<<' '<<cnt[j]<<'\n';
						if(tcn[j]!=cnt[j])
						{
							f=0;
							break;
						}
					}
					if(f)
					{
						cout<<u<<' '<<v<<'\n'<<x<<' '<<y;
						return 0;
					}
					memset(tcn,0,sizeof(tcn));
				}
				y=l;
				x=u+v-y-ma;
				if(x>0 && x<=u)
				{
					FOR(j,1,u+1)
					{
						FOR(k,1,v+1)
						{
							tcn[abs(x-j)+abs(y-k)]++;
						}
					}
					bool f=1;
					FOR(j,0,ma+1)
					{
						if(tcn[j]!=cnt[j])
						{
							f=0;
							break;
						}
					}
					if(f)
					{
						cout<<u<<' '<<v<<'\n'<<x<<' '<<y;
						return 0;
					}
					memset(tcn,0,sizeof(tcn));
				}
			}
		}
		cout<<-1;
		
		
	}
	return 0;
}
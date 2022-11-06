#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
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
int ri[2005][2005],le[2005][2005],up[2005][2005],dow[2005][2005];
char p[2005][2005];
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
		string s;
		FOR(i,1,n)
		{
			cin>>s;
			FOR(j,1,m)
			{
				p[i][j]=s[j-1];
			}
		}
		FOR(i,1,n)
		{
			FOR(j,1,m)
			{
				if(p[i][j]==p[i-1][j])
				{
					up[i][j]=up[i-1][j]+1;
				}
				else
				{
					up[i][j]=1;
				}
				if(p[i][j]==p[i][j-1])
				{
					le[i][j]=le[i][j-1]+1;
				}
				else
				{
					le[i][j]=1;
				}
				if(p[n+1-i][j]==p[n+2-i][j])
				{
					dow[n+1-i][j]=dow[n+2-i][j]+1;
				}
				else
				{
					dow[n+1-i][j]=1;
				}
				if(p[i][m+1-j]==p[i][m+2-j])
				{
					ri[i][m+1-j]=ri[i][m+2-j]+1;
				}
				else
				{
					ri[i][m+1-j]=1;
				}
			}
			
		}
		FOR(i,1,n)
		{
			FOR(j,1,m)
			{
				up[i][j]=min(min(up[i][j],dow[i][j]),min(ri[i][j],le[i][j]));
			}
		}
		FOR(i,1,n)
		{
			FOR(j,1,m)
			{
				up[i][j]=min(up[i][j],min(up[i-1][j]+1,up[i][j-1]+1));
			}
		}
		ll ans=0;
		FORD(i,n,1)
		{
			FORD(j,m,1)
			{
				up[i][j]=min(up[i][j],min(up[i+1][j]+1,up[i][j+1]+1));
				ans+=up[i][j];
			}
		}
		cout<<ans;
	}
	return 0;
}
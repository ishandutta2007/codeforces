#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return re;
}
vector<pair<int,int> > ver[200005],hor[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,q,c;
		cin>>n>>q>>c;
		c++;
		int brute[c][101][101];
		memset(brute,0,sizeof(brute));
		int x,y,s;
		FOR(i,0,n)
		{
			cin>>x>>y>>s;
			FOR(j,0,c)
			{
				brute[j][x][y]+=(s+j)%c;
			}
		}
		FOR(i,0,c)
		{
			FOR(j,0,101)
			{
				FOR(k,1,101)
				{
					brute[i][j][k]+=brute[i][j][k-1];
				}
			}
			FOR(j,0,101)
			{
				FOR(k,1,101)
				{
					brute[i][k][j]+=brute[i][k-1][j];
				}
			}
		}
		ll t;
		int x1,y1,x2,y2;
		FOR(i,0,q)
		{
			cin>>t>>x1>>y1>>x2>>y2;
			t%=c;
			cout<<brute[t][x2][y2]-brute[t][x2][y1-1]-brute[t][x1-1][y2]+brute[t][x1-1][y1-1]<<'\n';
		}
	}
	return 0;
}
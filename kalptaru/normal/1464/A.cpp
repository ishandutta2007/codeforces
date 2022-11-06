#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
const ll mod=1000000007;
ll INF=1e18;
ll po(ll a,ll b){
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
int c;
void dfs(int i,vector<int> gra[],bool vis[],bool cur[])
{
	if(vis[i]==1)
		return;
	vis[i]=1;
	cur[i]=1;
	// c++;
	FOR(j,0,gra[i].size())
	{
		if(cur[gra[i][j]]==1)
		{
			c+=2;
		}
		else
		{
			c++;
			dfs(gra[i][j],gra,vis,cur);
		}
	}
	cur[i]=0;
	return ;
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
	ll test=1;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> gra[n];
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			u--;
			v--;
			if(u==v)
				continue;
			gra[u].pb(v);
		}
		bool vis[n]={0},cur[n]={0};
		int ans=0;
		FOR(i,0,n)
		{
			c=0;
			if(vis[i]==0)
			{
				dfs(i,gra,vis,cur);
				ans+=c;
				// cout<<i<<' '<<c<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
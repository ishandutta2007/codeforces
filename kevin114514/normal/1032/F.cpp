#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll dp[300300][3];
vector<int> G[300300];
const ll mod=998244353;
void dfs(int u,int fa)
{
//	ll tmp=1;
	dp[u][0]=1;
	for(int i=0;i<sz(G[u]);i++)
		if(G[u][i]!=fa)
		{
			int v=G[u][i];
			dfs(v,u);
			ll tmp[3]={dp[u][0]*(dp[v][0]+dp[v][2])%mod,(dp[u][0]*dp[v][2]+dp[u][1]*(dp[v][0]+dp[v][2]*2))%mod,((dp[u][0]+dp[u][1])*(dp[v][0]+dp[v][1])+dp[u][2]*(dp[v][0]+dp[v][2]*2))%mod};
			memcpy(dp[u],tmp,sizeof(tmp));
		}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	cout<<(dp[1][0]+dp[1][2])%mod<<endl;
	return 0;
}
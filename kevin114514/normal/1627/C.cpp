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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<pii> G[100100];
int ans[100100];
void dfs(int u,int fa,int co)
{
	co=5-co;
	for(auto p:G[u]) if(p.first!=fa)
	{
		ans[p.second]=co;
		dfs(p.first,u,co);
		co=5-co;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].pb(mp(v,i));
			G[v].pb(mp(u,i));
		}
		bool flg=1;
		for(int i=1;i<=n;i++)
			if(sz(G[i])>2)
				flg=0;
		if(!flg)
		{
			puts("-1");
			continue;
		}
		dfs(1,0,2);
		for(int i=1;i<n;i++)
			cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}
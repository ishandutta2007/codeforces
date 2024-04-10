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
vector<int> G[500500];
int ans=0;
vector<int> depth;
void dfs(int u,int fa,int dep)
{
	if(u==1)
	{
		for(auto v:G[u]) if(v!=fa)
		{
			depth.clear();
			dfs(v,u,dep+1);
			srt(depth);
			int x=-1;
			for(auto y:depth)
				x=max(x+1,y);
			ans=max(ans,x);
		}
		return ;
	}
	else if(sz(G[u])==1)
	{
		depth.pb(dep);
		return ;
	}
	for(auto v:G[u]) if(v!=fa)
	{
		dfs(v,u,dep+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
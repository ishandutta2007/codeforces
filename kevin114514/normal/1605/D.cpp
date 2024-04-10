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
vector<int> G[200200];
vector<int> bl,wh;
void dfs(int u,int f,int cl)
{
	if(cl)
		bl.pb(u);
	else	wh.pb(u);
	for(auto v:G[u]) if(v!=f)
		dfs(v,u,cl^1);
}
int rk[200200];
bool used[200200];
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<=n;i++)
		used[i]=0;
	bl.clear();
	wh.clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0,0);
	if(sz(wh)>sz(bl))
		swap(wh,bl);
	int x=sz(wh);
	for(int i=0;i<20;i++)
		if(x>>i&1)
		{
			for(int j=(1<<i);j<(1<<(i+1));j++)
			{
				rk[wh.back()]=j;
				used[j]=1;
				wh.resize(sz(wh)-1);
			}
		}
	for(int i=1;i<=n;i++)
		if(!used[i])
		{
			rk[bl.back()]=i;
			bl.resize(sz(bl)-1);
		}
	for(int i=1;i<=n;i++)
		printf("%d ",rk[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}
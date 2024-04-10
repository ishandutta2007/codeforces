#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 5005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int col[maxn],vis[maxn],n,m,a,b,c,F,cnt,c1[maxn],c0[maxn],x0,x1,ans[maxn];
vector <int> mp[maxn],v0[maxn],v1[maxn];
bool dp[maxn][maxn];

inline void dfs(int u,int x,int fa)
{
	col[u]=x; vis[u]=1;
	if(col[u]==0) x0++,v0[cnt].pb(u);
	else x1++,v1[cnt].pb(u);
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(v==fa) continue;
		if(vis[v])
		{
			if(col[v]==col[u]) {F=1; return;}
			else continue;
		}
		dfs(v,x^1,u);
	}
}

int main()
{
	n=read(); m=read(); a=read(); b=read(); c=read();
	rep(i,1,m) {int u=read(),v=read(); mp[u].pb(v); mp[v].pb(u);}
	rep(i,1,n) if(!vis[i])
	{
		cnt++; x1=0; x0=0; dfs(i,0,0);
		c0[cnt]=x0; c1[cnt]=x1;
	}
	if(F==1) return puts("NO"),0; dp[0][0]=1;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(dp[i-1][j])
			{
				if(j+c0[i]<=b) dp[i][j+c0[i]]=1;
				if(j+c1[i]<=b) dp[i][j+c1[i]]=1;
			}
		}
	}
	if(!dp[cnt][b]) return puts("NO"),0; puts("YES");
	int nw=b;
	for(int i=cnt;i>=1;i--)
	{
		if(nw>=c0[i]&&dp[i-1][nw-c0[i]])
		{
			for(int j=0;j<v0[i].size();j++) ans[v0[i][j]]=2;
			for(int j=0;j<v1[i].size();j++) if(a) ans[v1[i][j]]=1,a--; else ans[v1[i][j]]=3;
			nw-=c0[i];
		}
		else
		{
			for(int j=0;j<v1[i].size();j++) ans[v1[i][j]]=2;
			for(int j=0;j<v0[i].size();j++) if(a) ans[v0[i][j]]=1,a--; else ans[v0[i][j]]=3;
			nw-=c1[i];
		}
	}
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
	return 0;
}
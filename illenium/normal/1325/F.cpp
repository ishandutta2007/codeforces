#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> mp[maxn],ans,vec[maxn];
int n,m,dep[maxn],q,fa[maxn],vis[maxn];

inline void dfs(int u)
{
	//cout<<u<<endl;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa[u]) continue;
		if(vis[v])
		{
			if(dep[u]-dep[v]+1>=q)
			{
				puts("2"); ans.push_back(v);
				while(u!=v) ans.push_back(u),u=fa[u];
				cout<<ans.size()<<endl;
				for(int j=0;j<ans.size();j++) printf("%d ",ans[j]); exit(0);
			}
		}
		else vis[v]=1,fa[v]=u,dep[v]=dep[u]+1,dfs(v);
	}
}

int main()
{
	n=read(); m=read();
	int p=sqrt(n); if(p*p==n) q=p; else q=p+1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v),mp[v].push_back(u);
	}
	vis[1]=1; dfs(1); puts("1");
	for(int i=1;i<=n;i++) vec[dep[i]%(q-1)].push_back(i);
	for(int i=0;i<q;i++)
	{
		if(vec[i].size()>=q)
		{
			for(int j=0,cnt=1;j<vec[i].size()&&cnt<=q;j++,cnt++) printf("%d ",vec[i][j]);
			return 0;
		}
	}
	return 0;
}
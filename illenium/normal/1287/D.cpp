#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
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

int n,rt,cnt,p[maxn],tmp[maxn],fl;
vector <int> mp[maxn],ans[maxn];

inline void dfs(int u)
{
	if(mp[u].size()==0)
	{
		ans[u].push_back(u);
		if(p[u]!=0) fl=1;
		return;
	}
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		dfs(v);
	}
	int cnt=0;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		for(int j=0;j<ans[v].size();j++)
		{
			if(cnt==p[u]) ans[u].push_back(u);
			ans[u].push_back(ans[v][j]);
			cnt++;
		}
		if(cnt==p[u]) ans[u].push_back(u),cnt++;
	}
	if(ans[u].size()<p[u]) fl=1;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(); p[i]=read();
		if(x==0) rt=i;
		else mp[x].push_back(i);
	}
	dfs(rt);
	for(int i=0;i<ans[rt].size();i++) tmp[ans[rt][i]]=i+1;
	if(fl==1) {puts("NO"); return 0;}
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d ",tmp[i]);
	return 0;
}
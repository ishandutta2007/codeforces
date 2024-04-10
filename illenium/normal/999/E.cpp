#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

vector <int> mp[maxn];
int n,m,S,dfn[maxn],low[maxn],cnt,belong[maxn],ind[maxn],scc,uu[maxn],vv[maxn],ans;
bool ins[maxn];
stack <int> s;

inline void tarjan(int u)
{
	dfn[u]=low[u]=++cnt; s.push(u); ins[u]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		++scc;
		int v;
		do
		{
			v=s.top(); s.pop(); ins[v]=0;
			belong[v]=scc;
		}while(u!=v);
	}
}

int main()
{
	n=read(); m=read(); S=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		uu[i]=u; vv[i]=v;
		mp[u].push_back(v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=m;i++)
	{
		if(belong[uu[i]]==belong[vv[i]]) continue;
		ind[belong[vv[i]]]++;
	}
	for(int i=1;i<=scc;i++) if(!ind[i]) ans++;
	if(!ind[belong[S]]) ans--;
	cout<<ans<<endl;
	return 0;
}
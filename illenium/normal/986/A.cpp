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
#define maxn 100005
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
vector <int> col[maxn];
int n,m,s,k,d[maxn][105],w[maxn];
bool vis[maxn];
queue <int> que;

inline void bfs(int x)
{
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(vis[v]) continue;
			d[v][x]=d[u][x]+1; vis[v]=1;
			que.push(v);
		}
	}
}

int main()
{
	n=read(); m=read(); s=read(); k=read();
	for(int i=1;i<=n;i++) w[i]=read(),col[w[i]].push_back(i);
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	for(int i=1;i<=s;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++) d[j][i]=inf;
		for(int j=0;j<col[i].size();j++) d[col[i][j]][i]=0,que.push(col[i][j]),vis[col[i][j]]=1;
		bfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		sort(d[i]+1,d[i]+s+1);
		int tmp=0;
		for(int j=1;j<=k;j++) tmp+=d[i][j];
		cout<<tmp<<" ";
	}
	return 0;
}
#pragma optimize GCC (2)
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
#define maxn 300005
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

int n,m,f[maxn][26],ind[maxn],d[maxn],cnt,ans;
char ch[maxn];
vector <int> mp[maxn];
queue <int> que;
bool vis[maxn][26];

inline int dfs(int u,int p)
{
	if(vis[u][p]) return f[u][p]; vis[u][p]=1;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		f[u][p]=max(f[u][p],dfs(v,p));
	}
	if(ch[u]-'a'==p) f[u][p]++;
	return f[u][p];
}

int main()
{
	n=read(); m=read(); scanf("%s",ch+1);
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(v); ind[v]++;
	}
	for(int i=1;i<=n;i++) d[i]=ind[i];
	for(int i=1;i<=n;i++) if(!ind[i]) que.push(i);
	while(!que.empty())
	{
		int u=que.front(); que.pop(); cnt++;
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(!(--ind[v])) que.push(v);
		}
	}
	if(n!=cnt) {puts("-1"); return 0;}
	for(int i=1;i<=n;i++) for(int j=0;j<=25;j++) if(!vis[i][j]) ans=max(ans,dfs(i,j));
	cout<<ans<<endl;
	return 0;
}
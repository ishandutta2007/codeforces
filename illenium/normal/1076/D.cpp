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
#define inf 1e18
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,k,cnt;
struct node{int v,w,id;};
struct node2{ll dis; int v;};
struct node3{int v,id;}pre[maxn];
ll dis[maxn];
vector <node> mp[maxn];

inline bool operator < (node2 a,node2 b){return a.dis>b.dis;}

priority_queue <node2> que;
bool vis[maxn],vis2[maxn];
vector <int> ans;
vector <node3> p[maxn];

inline void spfa()
{
	que.push((node2){0,1});
	while(!que.empty())
	{
		node2 u=que.top(); que.pop();
		if(vis[u.v]) continue; vis[u.v]=1;
		for(int i=0;i<mp[u.v].size();i++)
		{
			node v=mp[u.v][i];
			if(vis[v.v]) continue;
			if(dis[v.v]>dis[u.v]+v.w)
			{
				dis[v.v]=dis[u.v]+v.w; pre[v.v]=(node3){u.v,v.id};
				que.push((node2){dis[v.v],v.v});
			}
		}
	}
}

inline void dfs(int u)
{
	vis2[u]=1;
	for(int i=0;i<p[u].size();i++)
	{
		node3 v=p[u][i];
		if(vis2[v.v]) continue;
		ans.push_back(v.id); cnt++;
		if(cnt==min(n-1,k))
		{
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			exit(0);
		}
		dfs(v.v);
	}
}

int main()
{
	//freopen("t1.in","r",stdin);
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++) dis[i]=inf; dis[1]=0;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		mp[u].push_back((node){v,w,i});
		mp[v].push_back((node){u,w,i});
	}
	spfa();
	for(int i=2;i<=n;i++)
	{
		p[i].push_back(pre[i]);
		p[pre[i].v].push_back((node3){i,pre[i].id});
	}
	//for(int i=2;i<=n;i++) cout<<i<<" "<<pre[i].v<<" "<<pre[i].id<<endl;
	cout<<min(n-1,k)<<endl; dfs(1);
	return 0;
}
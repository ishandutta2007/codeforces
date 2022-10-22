#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

struct node{int a,b;};

inline bool operator < (node a,node b)
{
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}

map <node,int> p;
vector <int> mp[maxn],ans1,ans2;
int a[maxn],b[maxn],c[maxn],ind[maxn];
bool vis[maxn],vis2[maxn];
set <int> s[maxn];
queue <int> que;
set <int>::iterator it;

inline void dfs1(int u)
{
	vis[u]=1; ans1.push_back(u);
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(vis[v]) continue;
		dfs1(v);
	}
}

inline void bfs()
{
	while(!que.empty())
	{
		int u=que.front(); que.pop(); vis2[u]=1;
		it=s[u].begin(); int id=*it; ans2.push_back(id);
		ind[a[id]]-=2; ind[b[id]]-=2; ind[c[id]]-=2;
		s[a[id]].erase(id); s[b[id]].erase(id); s[c[id]].erase(id);
		if(ind[a[id]]==2) que.push(a[id]);
		if(ind[b[id]]==2) que.push(b[id]);
		if(ind[c[id]]==2) que.push(c[id]);
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n-2;i++)
		{
			a[i]=read(),b[i]=read(),c[i]=read();
			if(a[i]>b[i]) swap(a[i],b[i]);
			if(a[i]>c[i]) swap(a[i],c[i]);
			if(b[i]>c[i]) swap(b[i],c[i]);
			p[(node){a[i],b[i]}]++;
			p[(node){b[i],c[i]}]++;
			p[(node){a[i],c[i]}]++;
		}
		for(int i=1;i<=n-2;i++)
		{
			if(p[(node){a[i],b[i]}]==1) mp[a[i]].push_back(b[i]),mp[b[i]].push_back(a[i]);
			if(p[(node){b[i],c[i]}]==1) mp[b[i]].push_back(c[i]),mp[c[i]].push_back(b[i]);
			if(p[(node){a[i],c[i]}]==1) mp[a[i]].push_back(c[i]),mp[c[i]].push_back(a[i]);
		}
		for(int i=1;i<=n;i++) vis[i]=0; dfs1(1);
		for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]); puts("");
		
		for(int i=1;i<=n-2;i++)
		{
			ind[a[i]]+=2; ind[b[i]]+=2; ind[c[i]]+=2;
			s[a[i]].insert(i); s[b[i]].insert(i); s[c[i]].insert(i);
		}
		for(int i=1;i<=n;i++) if(ind[i]==2) que.push(i),vis2[i]=1;
		bfs();
		for(int i=0;i<n-2;i++) printf("%d ",ans2[i]); puts("");
		
		for(int i=1;i<=n;i++) mp[i].clear(); p.clear(); ans1.clear(); ans2.clear();
	}
	return 0;
}
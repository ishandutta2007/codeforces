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

struct node{int x,y;};
int n,m,s,t,disa[1005],disb[1005],ans;
vector <int> mp[1005];
queue <int> que;
bool vis1[1005],vis2[1005];
map <node,int> p;

inline bool operator<(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

inline void bfs1()
{
	que.push(s); vis1[s]=1;
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(!vis1[v])
			{
				disa[v]=disa[u]+1;
				que.push(v);
				vis1[v]=1;
			}
		}
	}
	return;
}

inline void bfs2()
{
	que.push(t); vis2[t]=1;
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			if(!vis2[v])
			{
				disb[v]=disb[u]+1;
				que.push(v);
				vis2[v]=1;
			}
		}
	}
	return;
}

int main()
{
	n=read(); m=read(); s=read(); t=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		p[(node){u,v}]=1;
		p[(node){v,u}]=1;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	for(int i=1;i<=n;i++) disa[i]=inf,disb[i]=inf;
	disa[s]=0; disb[t]=0;
	bfs1(); bfs2();
	int len=disb[s];
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(p[(node){i,j}]) continue;
			if(disa[i]+disb[j]+1>=disa[t]&&disb[i]+disa[j]+1>=disa[t]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
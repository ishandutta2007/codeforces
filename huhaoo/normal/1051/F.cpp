/****************************************************************
	File name: CF1051F.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/17/2018, 8:20:00 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 200010
#include<queue>
namespace run
{
	#define C 100
	#define B 100
	int begin[N],next[N<<1],to[N<<1],f[N][B+10],d[N],cnt,n,m,e,k[N],vis[N];
	long long w[N<<1],h[N],o[C][N];
	#define fo(i,a) for(int i=begin[a];i;i=next[i])
	void add(int u,int v,int ww)
	{
		e++;
		next[e]=begin[u];
		begin[u]=e;
		to[e]=v;
		w[e]=ww;
	}
	void dfs(int u)
	{
		int v;vis[u]=1;
		fo(i,u)if(!vis[v=to[i]])
		{
			f[v][0]=u;d[v]=d[u]+1;h[v]=h[u]+w[i];
			dfs(v);
		}
		else if(f[u][0]!=v)
		{
			k[++cnt]=u;
			k[++cnt]=v;
		}
	}
	#define inf 1<<29
	#define Inf (1ll<<60)
	struct node
	{
		int p;
		long long d;
		node(int P=0,long long D=0)
		{
			p=P;d=D;
		}
	};
	bool operator<(node a,node b){return a.d>b.d;}
	priority_queue<node>q;
	void dij(int x,long long* o)
	{
		fr(i,1,n)o[i]=Inf;o[x]=0;
		fr(i,1,n)vis[i]=0;
		while(!q.empty())q.pop();
		q.push({x,0});
		while(!q.empty())
		{
			int u=q.top().p,v;q.pop();
			if(vis[u])continue;vis[u]=1;
			fo(i,u)if(o[to[i]]>o[u]+w[i])
			{
				o[to[i]]=o[u]+w[i];
				q.push({to[i],o[to[i]]});
			}
		}
	}
	int lca(int u,int v)
	{
		if(d[u]<d[v])swap(u,v);
		fd(i,B,0)if(d[f[u][i]]>=d[v])u=f[u][i];
		fd(i,B,0)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
		return u==v?u:f[u][0];
	}
	int main()
	{
		n=read();m=read();
		fr(i,1,m)
		{
			int u=read(),v=read(),w=read();
			add(u,v,w);add(v,u,w);
		}
		d[1]=1;dfs(1);
		fr(i,1,B)fr(j,1,n)f[j][i]=f[f[j][i-1]][i-1];
		fr(i,1,cnt)dij(k[i],o[i]);
		int q=read();
		while(q--)
		{
			int u=read(),v=read();
			long long ans=h[u]+h[v]-2*h[lca(u,v)];
			fr(i,1,cnt)ans=min(ans,o[i][u]+o[i][v]);
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main(){return run::main();}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e5+20;

struct Edge {
	int x,y;
}E[maxn];

vector<int>ed[maxn];
int n,m;

int fa[maxn],dfn[maxn],low[maxn],times;

void dfs(int u)
{
	dfn[u]=++times;
	for(int v:ed[u])
	{
	 	if(v==fa[u] || dfn[v])continue;
	  	fa[v]=u;
     	dfs(v);
	}
	low[u]=times;
}

int cf[maxn];
vector<int>remroot;

void dfs1(int u)
{
	for(int v:ed[u])
		if(fa[v]==u)
			dfs1(v),cf[u]+=cf[v];
}

inline void init()
{
	n=read(); m=read();
	REP(i,1,m)
	{
		int x=read(),y=read();
		ed[x].push_back(y);
		ed[y].push_back(x);
		E[i]=(Edge){x,y};
	}
	REP(i,1,n)if(!dfn[i])remroot.push_back(i),dfs(i);
	REP(i,1,n)sort(ed[i].begin(),ed[i].end(),[](int a,int b){ return dfn[a]<dfn[b];});
	REP(u,1,n)
	{
		for(int v:ed[u])
			if(dfn[v]>=dfn[u])
			{
				if(fa[v]==u);
				else {
					cf[u]--; cf[v]++;
				}
			}
	}
	for(int rt:remroot)dfs1(rt);
	REP(i,1,m)if(dfn[E[i].x]>dfn[E[i].y])swap(E[i].x,E[i].y);
}

inline bool In(int u,int v){ return dfn[u]<=dfn[v] && dfn[v]<=low[u];}

inline int lca(int x,int y)
{
	while(!In(y,x))y=fa[y];
	return y;
}

inline vector<int> PATH(int u,int v)
{
	vector<int>ans;
	while(v!=u)ans.push_back(v),v=fa[v];
	ans.push_back(u);
	return ans;
}

inline void Out(int i,int j)
{
	int u1=E[i].x,v1=E[i].y,u2=E[j].x,v2=E[j].y;
	int A=lca(v1,v2),B=dfn[u1]>dfn[u2]?u1:u2;
	vector<int>path1=PATH(B,A),path2;
	printf("%d ",SZ(path1)); for(int x:path1)printf("%d ",x);puts("");
//A->B
	path1=PATH(A,v1); path2=PATH(u1,B); reverse(path1.begin(),path1.end()); reverse(path2.begin(),path2.end());
	printf("%d ",SZ(path1)+SZ(path2)); for(int x:path1)printf("%d ",x); for(int x:path2)printf("%d ",x); puts("");

	path1=PATH(A,v2); path2=PATH(u2,B); reverse(path1.begin(),path1.end()); reverse(path2.begin(),path2.end());
	printf("%d ",SZ(path1)+SZ(path2)); for(int x:path1)printf("%d ",x); for(int x:path2)printf("%d ",x); puts("");
}

inline void doing()
{
	REP(u,1,n)
	{
		if(cf[u]>=2)
		{
			int a=0,b=0;
			REP(i,1,m)if(fa[E[i].y]!=E[i].x)
			{
				if(In(u,E[i].y) && In(E[i].x,fa[u]))
				{
					if(!a)a=i;
					else if(!b)b=i;
				}
			}
			puts("YES");
			Out(a,b);
			exit(0);
		}
	}
	puts("NO");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cf.in","r",stdin);
	freopen("cf.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
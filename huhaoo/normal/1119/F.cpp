/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Wed 26 May 2021 10:59:20 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#include<vector>
#include<random>
#define pii std::pair<int,int>
#define F first
#define S second
const int N=500010;
std::mt19937 Rand(123456789);
struct tree
{
	struct node
	{
		int s[2];
		int v,c; i64 w; unsigned int R;
	} ;
	std::vector<node> a; int r;
	tree(){ a.resize(1); r=0; }
	void update(int u){ a[u].c=1+a[a[u].s[0]].c+a[a[u].s[1]].c; a[u].w=a[u].v+a[a[u].s[0]].w+a[a[u].s[1]].w; }
	int merge(int l,int r)
	{
		if(!l||!r) return l+r;
		if(a[l].R<a[r].R)
		{
			a[l].s[1]=merge(a[l].s[1],r); update(l);
			return l;
		}
		else
		{
			a[r].s[0]=merge(l,a[r].s[0]); update(r);
			return r;
		}
	}
	void split(int k,int v,int &l,int &r)
	{
		if(!k){ l=r=0; return ; }
		if(a[k].v<=v)
		{
			l=k; split(a[l].s[1],v,a[l].s[1],r); update(l);
		}
		else
		{
			r=k; split(a[r].s[0],v,l,a[r].s[0]); update(r);
		}
	}
	void Split(int k,int v,int &l,int &r)
	{
		if(!k){ l=r=0; return ; }
		if(a[a[k].s[0]].c+1<=v)
		{
			l=k; Split(a[l].s[1],v-a[a[k].s[0]].c-1,a[l].s[1],r); update(l);
		}
		else
		{
			r=k; Split(a[r].s[0],v,l,a[r].s[0]); update(r);
		}
	}
	void ins(int v)
	{
		a.push_back({0,0,v,1,v,(unsigned int)Rand()}); int R=a.size()-1,x,y;
		split(r,v,x,y); r=merge(merge(x,R),y);
//		printf("+ %d %d\n",v,a[r].c);
	}
	void erase(int v)
	{
		int x,y,z;
		split(r,v-1,x,y); split(y,v,y,z);
		r=merge(x,merge(merge(a[y].s[0],a[y].s[1]),z));
	}
	i64 query(int k){ int x,y; Split(r,k,x,y); i64 ans=a[x].w; r=merge(x,y); return ans; }
} r[N];
std::vector<pii> e[N],E[N];
std::vector<int> D[N];
int n;
int a[N],m,c,p[N],vis[N],d[N];
i64 ans[N];
i64 Ans;
i64 dfs(int u,int F)
{
	vis[u]=1; std::vector<i64> A;
	for(auto v:E[u]) if(p[v.F]&&!vis[v.F]) A.push_back(dfs(v.F,v.S));
	for(auto i:A) r[u].ins(i);
	i64 f1,f2;
	f1=F+r[u].query(d[u]-c-1);
	r[u].ins(F); f2=r[u].query(d[u]-c); r[u].erase(F);
	Ans+=f2;
	for(auto i:A) r[u].erase(i);
	assert(f1>=f2);
	return f1-f2;
}
i64 solve()
{
	Ans=0;
	fr(i,1,m) vis[a[i]]=0;
	fr(i,1,m) if(!vis[a[i]]) dfs(a[i],1e9);
	return Ans;
}
signed main()
{
	n=read();
	fr(i,1,n-1)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back({v,w}); e[v].push_back({u,w});
		r[u].ins(w); r[v].ins(w);
	}
	fr(i,1,n) D[d[i]=e[i].size()].push_back(i);
	fd(t,n-1,0)
	{
		for(auto i:D[t+1])
		{
			p[i]=1; a[++m]=i;
			for(auto j:e[i]) if(p[j.F])
			{
				E[i].push_back(j); E[j.F].push_back({i,j.S});
				r[i].erase(j.S); r[j.F].erase(j.S);
			}
		}
		c=t; ans[t]=solve();
//		fr(i,1,n) printf("%d%c",r[i].a[r[i].r].c,i==n?'\n':' ');
	}
	fr(i,0,n-1) printf("%lld%c",ans[i],i==n-1?'\n':' ');
	return 0;
}
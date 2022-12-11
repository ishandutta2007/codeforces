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
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=5e5+20;

struct Query {
	int op,a,b;
}qu[maxn];

int n,q;

struct UNION {
	int fa[maxn];
	inline void Init(int n=0){ REP(i,1,n)fa[i]=i;}
	int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
	inline void merge(int x,int y){ x=fin(x); y=fin(y); fa[y]=x;}
	inline int operator () (int x){ return fin(x);}
};

inline void GET_pretim()
{
	int tim[maxn]; REP(i,1,n)tim[i]=0;
	UNION B;
	vector<int>num[maxn];
	B.Init(n); REP(i,1,n)num[i].push_back(i);
	REP(i,1,q)
		if(qu[i].op==2)
		{
			int u=qu[i].a,v=qu[i].b;
			if(SZ(num[u])<SZ(num[v]))num[u].swap(num[v]);
			for(int x:num[v])num[u].push_back(x);
		}
		else if(qu[i].op==4)
		{
			int u=qu[i].a;
			REP(j,1,SZ(num[u])-1)B.merge(num[u][j-1],num[u][j]);
			num[u].resize(1);
			tim[B(u)]=i;
		}else if(qu[i].op==5)qu[i].b=tim[B(qu[i].a)];
}

struct ASK {
	int tim,x,id,op;
};
ASK ask[maxn<<1];
int asktot;

inline void GET_VALUE()
{
	int num=0;
	REP(i,1,q)
	{
		if(qu[i].op==5)
		{
			++num;
			if(qu[i].b)ask[++asktot]=(ASK){qu[i].b,qu[i].a,num,-1};
			ask[++asktot]=(ASK){i,qu[i].a,num,1};
		}
	}
	sort(ask+1,ask+asktot+1,[](ASK a,ASK b){ return a.tim<b.tim;});

	vector<int>g[maxn];
	ll ad[maxn],val[maxn],ans[maxn];
	REP(i,1,n)g[i].push_back(i),ad[i]=val[i]=ans[i]=0;
	UNION A; A.Init(n);
	
	int j=1;
	REP(i,1,q)
	{
		if(qu[i].op==1)
		{
			int u=qu[i].a,v=qu[i].b;
			A.merge(u,v);
			if(SZ(g[u])<SZ(g[v]))g[u].swap(g[v]),swap(ad[u],ad[v]);
			for(int x:g[v])
			{
				g[u].push_back(x);
				val[x]-=ad[u]; val[x]+=ad[v];
			}
		}
		else if(qu[i].op==3)
		{
			int u=qu[i].a;
			ad[u]+=SZ(g[u]);
		};
		while(j<=asktot && ask[j].tim<=i)
		{
			int u=ask[j].x;
			ans[ask[j].id]+=ask[j].op*(val[u]+ad[A(u)]);
			j++;
		}
	}
	REP(i,1,num)printf("%lld\n",ans[i]);
}

inline void init()
{
	n=read();q=read();
	REP(i,1,q)
	{
		char op; int opt,a=0,b=0;
		scanf("%c",&op);
		if(op=='U')opt=1,a=read(),b=read();
		else if(op=='M')opt=2,a=read(),b=read();
		else if(op=='A')opt=3,a=read();
		else if(op=='Z')opt=4,a=read();
		else if(op=='Q')opt=5,a=read();
		qu[i]=(Query){opt,a,b};
	}
	GET_pretim();
}

inline void doing()
{
	GET_VALUE();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF571D.in","r",stdin);
	freopen("CF571D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
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

struct node  {
	int fa,ch[26],len;
};
node t[maxn<<1];
int ttot=1;
vector<int>last[maxn];
int NOWSTRING;
char str[maxn];
int m,q;

inline void Add(int x,int pos)
{
	int np,p=last[NOWSTRING][pos-1];
	if(t[p].ch[x] && t[t[p].ch[x]].len==t[p].len+1)
	{
		last[NOWSTRING][pos]=np=t[p].ch[x];
		return;
	}else np=last[NOWSTRING][pos]=++ttot;
	t[np].len=t[p].len+1;
	while(p && !t[p].ch[x])t[p].ch[x]=np,p=t[p].fa;
	if(!p)t[np].fa=1;
	else {
		int q=t[p].ch[x];
		if(t[q].len==t[p].len+1)t[np].fa=q;
		else {
			int nq=++ttot; t[nq]=t[q];
			t[nq].len=t[p].len+1;
			t[np].fa=t[q].fa=nq;
			while(p && t[p].ch[x]==q)t[p].ch[x]=nq,p=t[p].fa;
		}
	}
	while(t[t[np].fa].len==t[np].len)np=t[np].fa;
	last[NOWSTRING][pos]=np;
}

vector<int>ed[maxn<<1];

#define pii pair<int,int>

inline bool operator <(pii a,pii b){ return a.fi==b.fi?a.se>b.se:a.fi<b.fi;}
inline bool operator >(pii a,pii b){ return b<a;}
inline pii max(pii a,pii b){ return a<b?b:a;}

struct Node {
	ll s; int ls,rs;
};

Node c[maxn*50];
int ctot,rt[maxn<<1];

inline int Merge(int x,int y,int l,int r)
{
	if(!x || !y)return x|y;
	int mid=l+r>>1;
	c[x].s+=c[y].s;
	c[x].ls=Merge(c[x].ls,c[y].ls,l,mid);
	c[x].rs=Merge(c[x].rs,c[y].rs,mid+1,r);
	//c[x].mx=max(c[c[x].ls].mx,c[c[x].rs].mx);
	return x;
}

void update(int x,int d,int &o,int l,int r)
{
	if(!o)o=++ctot,c[o].s=0;
	c[o].s+=d;
	if(l==r)return ;
	int mid=l+r>>1;
	if(x<=mid)update(x,d,c[o].ls,l,mid);
	else update(x,d,c[o].rs,mid+1,r);
	//c[o].mx=max(c[c[o].ls].mx,c[c[o].rs].mx);
}

inline void build()
{
	REP(i,1,ttot)ed[t[i].fa].push_back(i);
	REP(i,1,m)REP(j,1,SZ(last[i])-1)update(i,1,rt[last[i][j]],1,m);
}

struct Query {
	int u,l,r,id;
};
Query qu[500020];
vector<int>toq[maxn<<1];

inline void init()
{
	m=read(); q=read();
	REP(i,1,m)
	{
		static char S[maxn]; int len;
		NOWSTRING=i;
		scanf("%s",S+1); len=strlen(S+1);
		last[i].push_back(1); last[i].resize(len+1);
		REP(j,1,len)Add(S[j]-'a',j);
	}
	build();
	REP(i,1,q)
	{
		int l=read(),r=read(),k=read();
		int u=last[k].back();       
		qu[i]=(Query){u,l,r,i};
		toq[u].push_back(i);
	}
}

ll ans[500020];

ll query(int ql,int qr,int o,int l,int r)
{
	if(!o)return 0;
	if(ql<=l && r<=qr)return c[o].s;
	int mid=l+r>>1;
	if(qr<=mid)return query(ql,qr,c[o].ls,l,mid);
	else if(ql>mid)return query(ql,qr,c[o].rs,mid+1,r);
	else return query(ql,qr,c[o].ls,l,mid)+query(ql,qr,c[o].rs,mid+1,r);
}

void dfs(int u)
{
	for(int v:ed[u])dfs(v),rt[u]=Merge(rt[u],rt[v],1,m);
	for(int i:toq[u])
	{
		ll t=query(qu[i].l,qu[i].r,rt[u],1,m);
		ans[i]=t;		
	}
}

inline void doing()
{
	dfs(1);
	REP(i,1,q)printf("%lld\n",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF666E.in","r",stdin);
	freopen("CF666E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
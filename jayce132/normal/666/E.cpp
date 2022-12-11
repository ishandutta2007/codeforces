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

const int maxn=6e5+20;

struct node  {
	int fa,ch[26],len;
};
node t[maxn<<1];
int ttot=1;
vector<int>last[maxn];
int NOWSTRING;
char str[maxn];
int m,q;
int p[maxn<<1][21];

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
}

vector<int>ed[maxn<<1];

#define pii pair<int,int>

inline bool operator <(pii a,pii b){ return a.fi==b.fi?a.se>b.se:a.fi<b.fi;}
inline bool operator >(pii a,pii b){ return b<a;}
inline pii max(pii a,pii b){ return a<b?b:a;}

struct Node {
	pii mx; int ls,rs;
};

Node c[maxn<<5];
int ctot,rt[maxn<<1];

inline int Merge(int x,int y,int l,int r)
{
	if(!x || !y)return x|y;
	if(l==r)return c[x].mx.fi+=c[y].mx.fi,x;
	int mid=l+r>>1;
	c[x].ls=Merge(c[x].ls,c[y].ls,l,mid);
	c[x].rs=Merge(c[x].rs,c[y].rs,mid+1,r);
	c[x].mx=max(c[c[x].ls].mx,c[c[x].rs].mx);
	return x;
}

void update(int x,int d,int &o,int l,int r)
{
	if(!o)o=++ctot,c[o].mx.se=l;
	if(l==r)return c[o].mx.fi+=d,void();
	int mid=l+r>>1;
	if(x<=mid)update(x,d,c[o].ls,l,mid);
	else update(x,d,c[o].rs,mid+1,r);
	c[o].mx=max(c[c[o].ls].mx,c[c[o].rs].mx);
}

inline void build()
{
	REP(i,1,ttot)p[i][0]=t[i].fa,ed[t[i].fa].push_back(i);
	REP(j,1,20)REP(i,1,ttot)p[i][j]=p[p[i][j-1]][j-1];
	REP(i,1,m)REP(j,1,SZ(last[i])-1)update(i,1,rt[last[i][j]],1,m);
}

inline int DW(int l,int r)
{
	int x=last[0][r];
	DREP(i,20,0)if(t[p[x][i]].len>=r-l+1)x=p[x][i];
	return x;
}

struct Query {
	int u,l,r,id;
};
Query qu[maxn];
vector<int>toq[maxn<<1];

inline void init()
{
	scanf("%s",str+1); int len=strlen(str+1);
	last[0].push_back(1); last[0].resize(len+1);
	NOWSTRING=0; REP(i,1,len)Add(str[i]-'a',i);
	m=read();
	REP(i,1,m)
	{
		static char S[maxn]; int len;
		NOWSTRING=i;
		scanf("%s",S+1); len=strlen(S+1);
		last[i].push_back(1); last[i].resize(len+1);
		REP(j,1,len)Add(S[j]-'a',j);
	}
	build();
	q=read();
	REP(i,1,q)
	{
		int l=read(),r=read(),ql=read(),qr=read();
		int u=DW(ql,qr);       
		qu[i]=(Query){u,l,r,i};
		toq[u].push_back(i);
	}
}

pii ans[maxn];

pii query(int ql,int qr,int o,int l,int r)
{
	if(!o)return mkr(0,ql);
	if(ql<=l && r<=qr)return c[o].mx;
	int mid=l+r>>1;
	if(qr<=mid)return query(ql,qr,c[o].ls,l,mid);
	else if(ql>mid)return query(ql,qr,c[o].rs,mid+1,r);
	else return max(query(ql,qr,c[o].ls,l,mid),query(ql,qr,c[o].rs,mid+1,r));
}

void dfs(int u)
{
	for(int v:ed[u])dfs(v),rt[u]=Merge(rt[u],rt[v],1,m);
	for(int i:toq[u])
	{
		if(i==255)
			i=255;
		pii t=query(qu[i].l,qu[i].r,rt[u],1,m);
		/*if(i==139)
		{
			pii tmp=query(808,808,rt[u],1,m),tmp1=query(902,902,rt[u],1,m);
			tmp=max(tmp,tmp1);
			cerr<<tmp.fi<<" "<<tmp.se<<endl;
			}*/
		ans[i]=t;		
	}
}

inline void doing()
{
	dfs(1);
	REP(i,1,q)printf("%d %d\n",ans[i].se,ans[i].fi);
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
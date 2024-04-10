#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;

struct node {
	int ch[2],fa,sz;ll val,k,b;
};
node c[maxn];

int rt,tot;

#define lc (c[x].ch[0])
#define rc (c[x].ch[1])

inline void Merge(int x){ c[x].sz=c[lc].sz+c[rc].sz+1;}

inline void rotate(int x)
{
	int y=c[x].fa,z=c[y].fa,k=c[y].ch[1]==x;
	c[z].ch[c[z].ch[1]==y]=x; c[x].fa=z;
	c[y].ch[k]=c[x].ch[k^1]; c[c[y].ch[k]].fa=y;
	c[x].ch[k^1]=y; c[y].fa=x;
	Merge(y); Merge(x);
}

inline void Add(int x,ll k,ll b)
{
	c[x].val+=k*(c[lc].sz+1)+b;
	c[x].k+=k; c[x].b+=b;
}

inline void pushdown(int x)
{
	if(c[x].k || c[x].b)
	{
		if(lc)Add(lc,c[x].k,c[x].b);
		if(rc)Add(rc,c[x].k,c[x].b+c[x].k*(c[lc].sz+1));
		c[x].k=c[x].b=0;
	}
}

inline void Push(int x,int goal)
{
	static int st[maxn],top; top=0;
	while(x!=goal)st[++top]=x,x=c[x].fa;
	DREP(i,top,1)pushdown(st[i]);
}

inline void splay(int x,int goal)
{
	Push(x,goal);
	
	while(c[x].fa!=goal)
	{
		int y=c[x].fa,z=c[y].fa;
		if(c[y].fa!=goal)
			(c[y].ch[1]==x)^(c[z].ch[1]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(!goal)rt=x;
}

inline int ask(int k)
{
	int x=rt;
	while(1)
	{
		if(k<=c[lc].sz)x=lc;
		else if(k==c[lc].sz+1)return splay(x,0),x;
		else k-=c[lc].sz+1,x=rc;
	}
}

inline ll VAL(int k){ int x=ask(k);return c[x].val;}

int n;

inline void init()
{
	n=read();
	rt=1; tot=2; c[1].sz=2;
	c[1].ch[1]=2; c[2].fa=1;
	Merge(2); Merge(1);
	//cerr<<"!"<<endl;
	REP(i,1,n)
	{
		int val=read();
		int l=0,r=i-1;//l
		while(l<r)
		{
			int mid=l+r>>1;
			if(VAL(mid+1)+1ll*(mid+1)*val<VAL(mid+2))l=mid+1;
			else r=mid;
		}
		int x=ask(l+1),y=ask(l+2);
		//cerr<<l<<endl;
//cerr<<x<<" "<<y<<endl;
		splay(x,0); splay(y,x);
		//cerr<<"!"<<endl;
		c[y].ch[0]=++tot; c[tot].val=c[x].val; c[tot].sz=1; c[tot].fa=y; Merge(y); Merge(x);
		splay(tot,x);
		Add(tot,val,1ll*(c[lc].sz)*val);
		//REP(j,0,i)cerr<<VAL(j+1)<<" ";cerr<<endl;
	}
	ll ans=0;
	REP(i,1,n)chkmax(ans,VAL(i+1));
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("573E.in","r",stdin);
	freopen("573E.out","w",stdout);
#endif
	init();
	return 0;
}
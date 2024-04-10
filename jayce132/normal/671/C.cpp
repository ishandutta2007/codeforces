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

const int maxn=2e5+20;

int n;
vector<int>v[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int x=read();
		for(int j=1;j*j<=x;j++)
			if(x%j==0)
			{
				v[j].push_back(i);
				if(j!=x/j)v[x/j].push_back(i);
			}
	}
}

ll H[maxn];

struct node {
	int mn,mx,lz; ll s;
	inline void Merge(node lc,node rc ) {
		s=lc.s+rc.s;
		mn=min(lc.mn,rc.mn);
		mx=max(lc.mx,rc.mx);
	}
};
node c[(1<<19)+20];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void make_tree(int o,int l,int r)
{
	c[o].lz=-1;
	if(l==r)return c[o].mn=c[o].mx=c[o].s=l,void();
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
	c[o].Merge(c[lc],c[rc]);
}

ll ans;

inline void Set(int o,int l,int r,int d)
{
	c[o].lz=d;
	c[o].mn=c[o].mx=d;
	c[o].s=1ll*(r-l+1)*d; c[o].lz=d;
}

inline void pushdown(int o,int l,int r)
{
	int mid=l+r>>1;
	if(~c[o].lz)
	{
		Set(left,c[o].lz);
		Set(right,c[o].lz);
		c[o].lz=-1;
	}
}

void update(int ql,int qr,int d,int o,int l,int r)
{
	if(ql>qr)return;
	if(ql<=l && r<=qr)
	{
		if(c[o].mn>=d)return;
		if(c[o].mx<=d)return ans-=1ll*(r-l+1)*d-c[o].s,Set(o,l,r,d),void();
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	c[o].Merge(c[lc],c[rc]);
}

inline void doing()
{
	make_tree(1,1,n);
	ans=(ll)n*(n+1)/2;
	DREP(i,2e5,1)
	{
		H[i]=ans;
		if(SZ(v[i])>=2)
		{
			update(v[i][1]+1,n,n+1,1,1,n);
			update(v[i][0]+1,v[i][1],v[i].back(),1,1,n);
			update(1,v[i][0],*(----v[i].end()),1,1,n);
		}
	}
	H[0]=ans;
	DREP(i,2e5,1)H[i]-=H[i-1];
	ll Ans=0;
	REP(i,1,2e5)Ans+=H[i]*i;
	printf("%lld\n",Ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
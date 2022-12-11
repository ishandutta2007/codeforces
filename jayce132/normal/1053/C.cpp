#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;
const int mod=1e9+7;

inline void Mo(int &a){ if(a>=mod)a-=mod;}

struct node {
	int s1,s2;ll s3;
	inline void Merge(node lc,node rc) {
		s1=lc.s1+rc.s1; Mo(s1);
		s2=lc.s2+rc.s2; Mo(s2);
		s3=lc.s3+rc.s3;
	}
};
node c[maxn<<2];

#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

int n,q,A[maxn],w[maxn];

void make_tree(int o,int l,int r)
{
	if(l==r)return c[o].s1=(ll)(A[l]+l)*w[l]%mod,c[o].s2=(ll)(A[l]-l)*w[l]%mod,c[o].s3=w[l],void();
	int mid=(l+r)>>1;
	make_tree(left);
	make_tree(right);
	c[o].Merge(c[lc],c[rc]);
}

inline void init()
{
	n=read();q=read();
	REP(i,1,n)A[i]=read();
	REP(i,1,n)w[i]=read();
	make_tree(1,1,n);
}

void update(int x,int d,int o,int l,int r)
{
	if(l==r)return c[o].s1=(ll)(A[l]+l)*w[l]%mod,c[o].s2=(ll)(A[l]-l)*w[l]%mod,c[o].s3=w[l],void();
	int mid=(l+r)>>1;
	if(x<=mid)update(x,d,left);
	else update(x,d,right);
	c[o].Merge(c[lc],c[rc]);
}

ll sum;

int queryK(int ql,int qr,ll s,int o,int l,int r)
{
	if(ql<=l && r<=qr)
	{
		if(sum+c[o].s3<<1 <s)return sum+=c[o].s3,-1;
		if(l==r)return l;
	}
	int mid=(l+r)>>1,tmp;
	if(ql<=mid)if(~(tmp=queryK(ql,qr,s,left)))return tmp;
	if(qr>mid)if(~(tmp=queryK(ql,qr,s,right)))return tmp;
	return -1;
}

node query(int ql,int qr,int o,int l,int r)
{
	if(ql>qr)return (node){0,0,0};
	if(ql<=l && r<=qr)return c[o];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(ql,qr,left);
	else if(ql>mid)return query(ql,qr,right);
	else {
		node x;
		x.Merge(query(ql,qr,left),query(ql,qr,right));
		return x;
	}
}

inline void doing()
{
	REP(i,1,q)
	{
		int l=read(),r=read();
		if(l<0)
		{
			l=-l;
			w[l]=r;
			update(l,r,1,1,n);
		}else
		{
			ll s3=query(l,r,1,1,n).s3;
			sum=0;
			int t=queryK(l,r,s3,1,1,n),T=A[t];
			int ans=0;
			node a=query(l,t-1,1,1,n); a.s3%=mod;
			node b=query(t+1,r,1,1,n); b.s3%=mod;
			ans=(((ll)a.s3*(A[t]-t)-a.s2+mod)+((ll)b.s2-(ll)b.s3*(A[t]-t)%mod+mod))%mod;
			printf("%d\n",ans);
		}
		
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("putting.in","r",stdin);
	freopen("putting.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
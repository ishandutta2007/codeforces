/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Fri 12 Jun 2020 05:23:59 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#define i64 long long
#define pii std::pair<i64,i64>
#define F first
#define S second
const int N=400010;
const i64 inf=1ll<<50;
i64 n,k,a[N],b[N],f[N],g[N],m[N],M[N],c[N],T[N];
i64 s[N],t;
int ans;
void Tag(int k,i64 v){ M[k]+=v; T[k]+=v; c[k]-=v; }
void pushdown(int k){ Tag(k<<1,T[k]); Tag(k<<1|1,T[k]); T[k]=0; }
i64 calc(int k,int l,int r,i64 p)
{
	if(l==r){ return m[k]-p; }
	int mid=(l+r)>>1; pushdown(k);
	if(M[k<<1]>=p) return std::max(calc(k<<1,l,mid,p),c[k]);
	return std::max(m[k<<1]-p,calc(k<<1|1,mid+1,r,p));
}
void update(int k,int l,int r)
{
	int mid=(l+r)>>1;
	m[k]=std::max(m[k<<1],m[k<<1|1]); M[k]=std::max(M[k<<1],M[k<<1|1]);
	c[k]=calc(k<<1|1,mid+1,r,M[k<<1]);
}
void build(int k,int l,int r)
{
	if(l==r){ M[k]=g[l]; m[k]=g[l]+::k; c[k]=::k; return ; }
	int mid=(l+r)>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	update(k,l,r);
}
void modify(int k,int l,int r,int u,i64 v)
{
//	if(k==1) printf("M %d %lld\n",u,v);
	if(l>=u){ Tag(k,v); return ; }
	if(r<u) return ;
	int mid=(l+r)>>1; pushdown(k);
	modify(k<<1,l,mid,u,v); modify(k<<1|1,mid+1,r,u,v);
	update(k,l,r);
}
i64 Query(int k,int l,int r,i64 v)
{
	if(l==r) return l;
	int mid=(l+r)>>1; pushdown(k);
	if(calc(k<<1|1,mid+1,r,std::max(v,M[k<<1]))>=0) return Query(k<<1|1,mid+1,r,std::max(v,M[k<<1]));
	return Query(k<<1,l,mid,v);
}
pii query(int k,int l,int r,int L,int R,i64 v)
{
	if(l>R||L>r) return pii(-inf,-inf);
	if(L<=l&&r<=R) return calc(k,l,r,v)>=0?pii(Query(k,l,r,v),std::max(M[k],v)):pii(-inf,std::max(M[k],v));
	int mid=(l+r)>>1; pushdown(k);
	pii al=query(k<<1,l,mid,L,R,v),ar=query(k<<1|1,mid+1,r,L,R,std::max(v,al.S));
//	printf(" %d %d %d %d  %lld %lld\n",l,r,L,R,al.F,ar.F);
	return pii(std::max(al.F,ar.F),std::max(al.S,ar.S));
}
int main()
{
	n=read(); k=read();
	fr(i,1,n-1) a[i]=read();
	fr(i,1,n) b[i]=read();
	fr(i,2,n) f[i]=f[i-1]+b[i-1]-a[i-1];
	fr(i,2,n) g[i]=g[i-1]+b[i]-a[i-1];
	build(1,1,n); ans=1;
	fd(i,n,1)
	{
		while(t&&f[i]<=f[s[t]])
		{
			t--;
			if(t) modify(1,1,n,s[t]-1,-(f[s[t+1]]-f[s[t]]));
		}
		if(t) modify(1,1,n,s[t]-1,f[i]-f[s[t]]);
		s[++t]=i; int l=1,r=t,p=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(f[i]-f[s[mid]]>k){ l=mid+1; p=s[mid]-1; }
			else r=mid;
		}
		ans=std::max(ans,(int)query(1,1,n,i,p,-inf).F-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
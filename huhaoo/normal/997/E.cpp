/***************************************************************
	File name: 997E.cpp
	Author: huhao
	Create time: Mon 28 Oct 2019 07:16:53 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
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
const int N=480010;
int n,p[N],r[N],q,m[N],c[N],d[N];
i64 s[N],ans[N],t[N];
struct query
{
	int l,r,id;
	query(int L=0,int R=0,int I=0)
	{
		l=L;
		r=R;
		id=I;
	}
}Q[N];
int operator<(query a,query b)
{
	return a.r<b.r;
}
void Addans(int k,int v)
{
	s[k]+=v*c[k];
	t[k]+=v;
}
void Addval(int k,int v)
{
	m[k]+=v;
	d[k]+=v;
}
void pushdown(int k)
{
	Addval(k<<1,d[k]);
	Addval(k<<1|1,d[k]);
	if(m[k]==m[k<<1])
		Addans(k<<1,t[k]);
	if(m[k]==m[k<<1|1])
		Addans(k<<1|1,t[k]);
	t[k]=d[k]=0;
}
void update(int k)
{
	s[k]=s[k<<1]+s[k<<1|1];
	m[k]=min(m[k<<1],m[k<<1|1]);
	c[k]=0;
	if(m[k<<1]==m[k])
		c[k]+=c[k<<1];
	if(m[k<<1|1]==m[k])
		c[k]+=c[k<<1|1];
}
void modify(int k,int l,int r,int L,int R,int D)
{
	if(L<=l&&r<=R)
	{
		Addval(k,D);
		return;
	}
	pushdown(k);
	int mid=(l+r)>>1;
	if(L<=mid)
		modify(k<<1,l,mid,L,R,D);
	if(R>mid)
		modify(k<<1|1,mid+1,r,L,R,D);
	update(k);
}
i64 query(int k,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
		return s[k];
	pushdown(k);
	int mid=(l+r)>>1;
	i64 ans=0;
	if(L<=mid)
		ans+=query(k<<1,l,mid,L,R);
	if(R>mid)
		ans+=query(k<<1|1,mid+1,r,L,R);
	return ans;
}
void build(int k,int l,int r)
{
	c[k]=r-l+1;
	m[k]=n+1;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		p[i]=read();
		r[p[i]]=i;
	}
	q=read();
	fr(i,1,q)
	{
		Q[i].l=read();
		Q[i].r=read();
		Q[i].id=i;
	}
	sort(Q+1,Q+q+1);
	build(1,1,n);
	fr(i,1,q)
	{
		fr(j,Q[i-1].r+1,Q[i].r)
		{
			modify(1,1,n,j,j,-n-1);
			modify(1,1,n,1,j,1);
			if(p[j]>1&&r[p[j]-1]<j)
				modify(1,1,n,1,r[p[j]-1],-1);
			if(p[j]<n&&r[p[j]+1]<j)
				modify(1,1,n,1,r[p[j]+1],-1);
			Addans(1,1);
		}
		ans[Q[i].id]=query(1,1,n,Q[i].l,Q[i].r);
	}
	fr(i,1,q)
		printf("%I64d\n",ans[i]);
	return 0;
}
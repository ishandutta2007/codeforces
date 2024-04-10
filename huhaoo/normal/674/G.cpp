/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-01-29 20:07:59
****************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define pii std::pair<int,int>
const int N=600010,M=7;
int n,m,a[N],p[N],l[N],q;
struct info
{
	int n;
	pii a[M];
	info(){ n=0; }
	pii &operator[](int p){ return a[p];}
}t[N];
info operator+(info a,pii b)
{
	fr(i,1,a.n) if(a[i].first==b.first){ a[i].second+=b.second; return a; }
	if(a.n<m){ a[++a.n]=b; return a; }
	int mi=b.second;
	fr(i,1,m) mi=std::min(mi,a[i].second);
	b.second-=mi;
	fr(i,1,m) a[i].second-=mi;
	a.n=0;
	fr(i,1,m) if(a[i].second) a[++a.n]=a[i];
	if(b.second) a[++a.n]=b;
	return a;
}
info &operator+=(info &a,pii b){ return a=a+b; }
info operator+(info a,info b)
{
//	printf("  %d %d\n",a.n,b.n);
//	fr(i,1,a.n) printf("%d%c",a[i].first,i==a.n?'\n':' ');
//	fr(i,1,b.n) printf("%d%c",b[i].first,i==b.n?'\n':' ');
	fr(i,1,b.n) a+=b[i];
//	fr(i,1,a.n) printf("%d%c",a[i].first,i==a.n?'\n':' ');
//	putchar(10);
	return a;
}
info &operator+=(info &a,info b){ return a=a+b; }
void Tag(int k,int v){ p[k]=v; t[k].n=1; t[k][1]=pii(v,l[k]); }
void update(int k){ t[k]=t[k<<1]+t[k<<1|1]; }
void pushdown(int k){ if(p[k]){ Tag(k<<1,p[k]); Tag(k<<1|1,p[k]); p[k]=0; } }
void build(int k,int l,int r)
{
//	printf(" %d %d %d\n",k,l,r);
	::l[k]=r-l+1;
	if(l==r){ Tag(k,a[l]); return ; }
	int mid=(l+r)>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	update(k);
}
void modify(int k,int l,int r,int L,int R,int v)
{
	if(l>R||L>r) return ;
	if(L<=l&&r<=R){ Tag(k,v); return ; }
	pushdown(k);
	int mid=(l+r)>>1;
	modify(k<<1,l,mid,L,R,v); modify(k<<1|1,mid+1,r,L,R,v);
	update(k);
}
info query(int k,int l,int r,int L,int R)
{
//	printf("%d %d %d %d\n",l,r,L,R);
	if(L<=l&&r<=R) return t[k];
	int mid=(l+r)>>1;
	pushdown(k);
	if(R<=mid) return query(k<<1,l,mid,L,R);
	else if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	else return query(k<<1,l,mid,L,R)+query(k<<1|1,mid+1,r,L,R);
}
int main()
{
	n=read(); q=read(); m=100/read();
	fr(i,1,n) a[i]=read();
	build(1,1,n);
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read(),r=read(),id=read();
			modify(1,1,n,l,r,id);
		}
		else if(opt==2)
		{
			int l=read(),r=read();
//			printf("%d %d\n",l,r);
			info ans=query(1,1,n,l,r);
			printf("%d ",ans.n);
			fr(i,1,ans.n) printf("%d%c",ans[i].first,i==end_i?'\n':' ');
		}
		else return 0;
	}
	return 0;
}
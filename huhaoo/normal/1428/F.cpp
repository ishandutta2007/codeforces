/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-09-17 09:59:39
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
#define i64 long long
const int N=1<<21|10;
i64 n,ans,s[N][2],lst,w[N],l[N];
i64 t[N],mi[N],mx[N];
char c[N];
void build(int k,int l,int r)
{
	::l[k]=r-l+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
}
void Tag(int k,i64 v){ w[k]+=v*l[k]; t[k]+=v; mi[k]+=v; mx[k]+=v; }
void pushdown(int k)
{
	if(t[k]){ Tag(k<<1,t[k]); Tag(k<<1|1,t[k]); t[k]=0; }
}
void Modify(int k,int l,int r,int v)
{
	if(l>r||mi[k]>=v) return ;
//	printf("%d  %d %d %d\n",k,l,r,v);
	if(mx[k]<v){ Tag(k,1); return ; }
	int mid=(l+r)>>1; pushdown(k);
	Modify(k<<1,l,mid,v); Modify(k<<1|1,mid+1,r,v);
	w[k]=w[k<<1]+w[k<<1|1]; mi[k]=std::min(mi[k<<1],mi[k<<1|1]); mx[k]=std::max(mx[k<<1],mx[k<<1|1]);
}
void modify(int k,int l,int r,int L,int R,int v,int op)
{
	if(L>r||l>R) return ;
	if(L<=l&&r<=R){ if(op==1) Tag(k,v); else Modify(k,l,r,v); return ; }
	int mid=(l+r)>>1; pushdown(k);
	modify(k<<1,l,mid,L,R,v,op); modify(k<<1|1,mid+1,r,L,R,v,op);
	w[k]=w[k<<1]+w[k<<1|1]; mi[k]=std::min(mi[k<<1],mi[k<<1|1]); mx[k]=std::max(mx[k<<1],mx[k<<1|1]);
}
int main()
{
	n=read();
	scanf("%s",c+1);
	fr(i,1,n) c[i]-=48;
	lst=n;
	build(1,1,n);
	fd(i,n,1)
	{
		if(c[i]==0) lst=i-1;
		else
		{
			modify(1,1,n,i,lst,1,1);
			modify(1,1,n,lst+1,n,lst-i+1,2);
		}
		ans+=w[1];
//		printf("%d %I64d\n",i,w[1]);
	}
	printf("%I64d\n",ans);
	return 0;
}
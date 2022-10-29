/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-07 16:10:05
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
const int N=400010;
i64 n,q,t1[N],t2[N],m[N];
const i64 p[10]={1,42,1764,74088,3111696,130691232,5489031744,230539333248,9682651996416,406671383849472};
i64 query(i64 a)
{
	return (a<=p[4]?(a<=p[2]?(a<=p[1]?(a<=p[0]?p[0]:p[1]):p[2]):(a<=p[3]?p[3]:p[4])):(a<=p[6]?(a<=p[5]?p[5]:p[6]):(a<=p[8]?(a<=p[7]?p[7]:p[8]):p[9])))-a;
}
void Tag(int k,i64 x){ t1[k]=x; t2[k]=0; m[k]=query(x); }
void tag(int k,i64 x){ if(t1[k]) t1[k]+=x; else t2[k]+=x; m[k]-=x; }
void pushdown(int k)
{
	if(t1[k])
	{
		Tag(k<<1,t1[k]); Tag(k<<1|1,t1[k]); t1[k]=0;
	}
	if(t2[k])
	{
		tag(k<<1,t2[k]); tag(k<<1|1,t2[k]); t2[k]=0;
	}
}
void update(int k){ m[k]=std::min(m[k<<1],m[k<<1|1]); }
void modify(int k,int l,int r,int L,int R,i64 x)
{
	if(l>R||L>r) return ;
	if(L<=l&&r<=R){ Tag(k,x); return ; }
	pushdown(k);
	int mid=(l+r)>>1;
	modify(k<<1,l,mid,L,R,x); modify(k<<1|1,mid+1,r,L,R,x);
	update(k);
}
int modify(int k,int l,int r,i64 x)
{
//	printf("%d %d %d %I64d\n",k,l,r,x);
	if(t1[k])
	{
		t1[k]+=x; m[k]=query(t1[k]);
		return m[k]==0;
	}
	if(m[k]>x){ tag(k,x); return 0; }
	pushdown(k);
	int mid=(l+r)>>1;
	modify(k<<1,l,mid,x); modify(k<<1|1,mid+1,r,x);
	update(k);
	return m[k]==0;
}
int Modify(int k,int l,int r,int L,int R,i64 x)
{
	if(l>R||L>r) return 0;
	if(L<=l&&r<=R) return modify(k,l,r,x);
	pushdown(k);
	int mid=(l+r)>>1;
	int ans=Modify(k<<1,l,mid,L,R,x)+Modify(k<<1|1,mid+1,r,L,R,x);
	update(k);
	return ans!=0;
}
i64 query(int k,int l,int r,int p)
{
	if(t1[k]) return t1[k];
	int mid=(l+r)>>1;
	if(p<=mid) return t2[k]+query(k<<1,l,mid,p);
	else return t2[k]+query(k<<1|1,mid+1,r,p);
}
int main()
{
	n=read(); q=read();
	fr(i,1,n) modify(1,1,n,i,i,read());
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int p=read();
			printf("%I64d\n",query(1,1,n,p));
		}
		else if(opt==2)
		{
			int l=read(),r=read(); i64 x=read();
//			printf("S %d %d %I64d\n",l,r,x);
			modify(1,1,n,l,r,x);
		}
		else
		{
			int l=read(),r=read(); i64 x=read();
//			printf("M %d %d %I64d\n",l,r,x);
			while(Modify(1,1,n,l,r,x)) ; //printf("M %d %d %I64d\n",l,r,x);
		}
	}
	return 0;
}
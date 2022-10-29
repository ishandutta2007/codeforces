/****************************************************************
	File name: F.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/13/2019, 11:44:04 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
#define N 1000010
#define B 25
#include<stdlib.h>
int n,q,ans[N],v[N],b=20,lx[N][B],rx[N][B],ax[N];
void insert(int *x,int v)
{
		fd(i,b,0)
			if(v>=(1<<i))
			{
				if(!x[i])
				{
					x[i]=v;
					break;
				}
				else
					v^=x[i];
			}
}
void merge(int *x,int *y)
{
	if(rand()&1)
		swap(x,y);
	fr(i,0,b)
		ax[i]=x[i];
	fd(i,b,0)
		if(y[i])
			insert(ax,y[i]);
}
struct query
{
	int l,r,p;
}a[N],_a[N];
void calc(int l,int r,int ll,int rr)
{
	if(ll>rr)
		return;
	int mid=(l+r)>>1,p1,p2,p3;
	fr(i,ll,rr)
		_a[i]=a[i];
	p1=ll-1;
	fr(i,ll,rr)
		if(_a[i].r<mid)
			a[++p1]=_a[i];
	p2=p1;
	fr(i,ll,rr)
		if(_a[i].r>=mid&&_a[i].l<=mid)
			a[++p2]=_a[i];
	p3=p2;
	fr(i,ll,rr)
		if(_a[i].l>mid)
			a[++p3]=_a[i];
	if(p1!=p2)
	{
		fr(i,0,b)
			lx[mid][i]=rx[mid][i]=0;
		insert(lx[mid],v[mid]);
		fd(i,mid-1,l)
		{
			fr(j,0,b)
				lx[i][j]=lx[i+1][j];
			insert(lx[i],v[i]);
		}
		fr(i,mid+1,r)
		{
			fr(j,0,b)
				rx[i][j]=rx[i-1][j];
			insert(rx[i],v[i]);
		}
		fr(i,p1+1,p2)
		{
			merge(lx[a[i].l],rx[a[i].r]);
			fd(j,b,0)
				if((ans[a[i].p]^ax[j])>ans[a[i].p])
					ans[a[i].p]^=ax[j];
		}
	}
	calc(l,mid-1,ll,p1);
	calc(mid+1,r,p2+1,rr);
}
int main()
{
	srand((unsigned long long)new char);
	n=read();
	fr(i,1,n)
		v[i]=read();
	q=read();
	fr(i,1,q)
	{
		a[i].l=read();
		a[i].r=read();
		a[i].p=i;
	}
	calc(1,n,1,q);
	fr(i,1,q)
		printf("%d\n",ans[i]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
int n,m,i,j,k,a[MAXN],t[MAXN<<2];
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
void build(int R,int l,int r)
{
	if(l==r)
	{
		t[R]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(R<<1,l,mid);
	build(R<<1|1,mid+1,r);
	t[R]=gcd(t[R<<1],t[R<<1|1]);
}
void fix(int R,int l,int r,int x,int d)
{
	if(l==r)
	{
		t[R]=d;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)fix(R<<1,l,mid,x,d);
	else fix(R<<1|1,mid+1,r,x,d);
	t[R]=gcd(t[R<<1],t[R<<1|1]);
}
int ask(int R,int l,int r,int l1,int r1,int x)
{
	int mid=l+r>>1;
	if(l1<=l&&r<=r1)
	{
		if(t[R]%x==0)return 0;
		if(l==r)return 1;
		if(t[R<<1]%x==0)return ask(R<<1|1,mid+1,r,l1,r1,x);
		if(t[R<<1|1]%x==0)return ask(R<<1,l,mid,l1,r1,x);
		return 2;
	}
	int s=0;
	if(l1<=mid)s+=ask(R<<1,l,mid,l1,r1,x);
	if(r1>mid)s+=ask(R<<1|1,mid+1,r,l1,r1,x);
	return s;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)
		{
			scanf("%d",&i);
			if(ask(1,1,n,j,k,i)>1)puts("NO");
			else puts("YES");
		}
		else fix(1,1,n,j,k);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1048576
struct node
{
	int n,a[5],b[5];
	void ins(int x,int y)
	{
		if(!y)return;
		int i,j;
		for(i=0;i<n;i++)if(a[i]==x)
		{
			b[i]+=y;
			return;
		}
		for(j=y,i=0;i<n;i++)j=min(j,b[i]);
		for(i=0;i<n;i++)b[i]-=j;
		y-=j;
		for(i=0;i<n;i++)if(!b[i])
		{
			a[i]=x;
			b[i]=y;
			return;
		}
	}
	node operator+(const node& y)
	{
		node t=y;
		int i;
		for(i=0;i<n;i++)t.ins(a[i],b[i]);
		return t;
	}
}t[MAXN][4],ans;
int n,m,A,i,j,k,l,N,root[MAXN],a[MAXN],lc[MAXN*7],rc[MAXN*7],s[MAXN*7];
void build(int R,int l,int r)
{
	int mid=l+r>>1,i;
	if(l==r)
	{
		for(i=0;i<4;i++)
		{
			t[R][i].n=i+1;
			t[R][i].a[0]=a[l];
			t[R][i].b[0]=1;
		}
		return;
	}
	build(R<<1,l,mid);
	build(R<<1|1,mid+1,r);
	for(i=0;i<4;i++)t[R][i]=t[R<<1][i]+t[R<<1|1][i];
}
void fix(int &R,int R1,int l,int r,int x)
{
	R=++N;
	s[R]=s[R1]+1;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)
	{
		fix(lc[R],lc[R1],l,mid,x);
		rc[R]=rc[R1];
	}
	else
	{
		fix(rc[R],rc[R1],mid+1,r,x);
		lc[R]=lc[R1];
	}
}
node ask(int R,int l,int r,int l1,int r1,int x)
{
	if(l==l1&&r==r1)return t[R][x];
	int mid=l+r>>1;
	if(r1<=mid)return ask(R<<1,l,mid,l1,r1,x);
	if(l1>mid)return ask(R<<1|1,mid+1,r,l1,r1,x);
	return ask(R<<1,l,mid,l1,mid,x)+ask(R<<1|1,mid+1,r,mid+1,r1,x);
}
int ask(int R,int R1,int l,int r,int x)
{
	if(l==r)return s[R]-s[R1];
	int mid=l+r>>1;
	if(x<=mid)return ask(lc[R],lc[R1],l,mid,x);
	return ask(rc[R],rc[R1],mid+1,r,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	build(1,1,n);
	for(i=1;i<=n;i++)fix(root[i],root[i-1],1,n,a[i]);
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		ans=ask(1,1,n,i,j,k-2);
		for(A=n+1,l=0;l+1<k;l++)if(ans.a[l]&&ask(root[j],root[i-1],1,n,ans.a[l])*k>j-i+1)A=min(A,ans.a[l]);
		if(A>n)A=-1;
		printf("%d\n",A);
	}
	return 0;
}
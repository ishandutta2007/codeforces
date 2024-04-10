#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MAXM 20000005
int lc[MAXM],rc[MAXM],d[MAXM],n,m,N=500000,M,i,j,a[MAXN],root[MAXN];
void fix(int &R,int R1,int l,int r,int l1,int r1,int x)
{
	R=++M;
	d[R]=d[R1];
	lc[R]=lc[R1];
	rc[R]=rc[R1];
	if(l1<=l&&r<=r1)
	{
		d[R]+=x;
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(lc[R],lc[R1],l,mid,l1,r1,x);
	if(r1>mid)fix(rc[R],rc[R1],mid+1,r,l1,r1,x);
}
int ask(int R,int l,int r,int x)
{
	if(!R)return 0;
	if(l==r)return d[R];
	int mid=l+r>>1;
	if(x<=mid)return d[R]+ask(lc[R],l,mid,x);
	return d[R]+ask(rc[R],mid+1,r,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=N;i++)a[i]=i;
	while(n--)
	{
		scanf("%d%d",&i,&j);
		a[i]=max(a[i],j);
	}
	for(i=1;i<=N;i++)a[i]=max(a[i],a[i-1]);
	for(i=N-1;~i;i--)if(a[i]<=i)fix(root[i],0,0,N,i+1,N,-N-1);
	else if(a[i]<a[i+1])fix(root[i],root[a[i]],0,N,i+1,N,1);
	else fix(root[i],root[i+1],0,N,i+1,i+1,1);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		i=ask(root[i],0,N,j);
		if(i<0)i=-1;
		printf("%d\n",i);
	}
	return 0;
}
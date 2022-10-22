#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
#define MAXN 100005
#define mp make_pair
#define pb push_back
int n,m,q,i,j,k,l,N,M,X,root[MAXN],t[MAXN<<4],f[MAXN<<4],l1[MAXN<<4],r1[MAXN<<4],lc[MAXN<<4],rc[MAXN<<4],s[MAXN<<4],a[MAXN<<4];
bool b[MAXN<<4];
void build(int &R,int l,int r)
{
	s[R=++N]=r-l+1;
	if(l==r)return;
	int mid=l+r>>1;
	build(lc[R],l,mid);
	build(rc[R],mid+1,r);
}
void build1(int &R,int l,int r)
{
	R=++M;
	if(l==r)
	{
		f[R]=X;
		return;
	}
	int mid=l+r>>1;
	build1(l1[R],l,mid);
	build1(r1[R],mid+1,r);
}
void up(int R)
{
	a[R]=a[lc[R]]+a[rc[R]];
	if(b[R])a[R]=s[R]-a[R];
}
void FIX(int &R,int R1,int l,int r,int x,int d)
{
	R=++M;
	if(l==r)
	{
		t[R]=a[f[R]=d];
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
	{
		FIX(l1[R],l1[R1],l,mid,x,d);
		r1[R]=r1[R1];
	}
	else
	{
		FIX(r1[R],r1[R1],mid+1,r,x,d);
		l1[R]=l1[R1];
	}
	t[R]=t[l1[R]]+t[r1[R]];
}
void fix(int &R,int R1,int l,int r,int l1,int r1)
{
	R=++N;
	s[R]=s[R1];
	b[R]=b[R1];
	lc[R]=lc[R1];
	rc[R]=rc[R1];
	if(l1<=l&&r<=r1)
	{
		b[R]=!b[R];
		a[R]=s[R1]-a[R1];
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(lc[R],lc[R1],l,mid,l1,r1);
	if(r1>mid)fix(rc[R],rc[R1],mid+1,r,l1,r1);
	up(R);
}
void Fix(int &R,int R1,int l,int r,int d,bool x)
{
	R=++N;
	s[R]=s[R1];
	b[R]=b[R1];
	if(b[R])x=!x;
	if(l==r)
	{
		a[R]=x^b[R];
		return;
	}
	int mid=l+r>>1;
	if(d<=mid)
	{
		Fix(lc[R],lc[R1],l,mid,d,x);
		rc[R]=rc[R1];
	}
	else
	{
		Fix(rc[R],rc[R1],mid+1,r,d,x);
		lc[R]=lc[R1];
	}
	up(R);
}
int ask(int R,int l,int r,int x)
{
	if(l==r)return f[R];
	int mid=l+r>>1;
	if(x<=mid)return ask(l1[R],l,mid,x);
	return ask(r1[R],mid+1,r,x);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	build(X,1,m);
	build1(root[0],1,n);
	for(l=1;l<=q;l++)
	{
		scanf("%d%d",&i,&j);
		if(i==4)root[l]=root[j];
		else
		{
			X=ask(root[l-1],1,n,j);
			if(i<3)
			{
				scanf("%d",&k);
				Fix(X,X,1,m,k,i&1);
			}
			else fix(X,X,1,m,1,m);
			FIX(root[l],root[l-1],1,n,j,X);
		}
		printf("%d\n",t[root[l]]);
	}
	return 0;
}
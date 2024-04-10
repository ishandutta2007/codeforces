#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 20000005
ll s[MAXN],f[MAXN],ans;
int n,m,N,i,j,k,u,v,l[MAXN],r[MAXN],d[MAXN],root,lc[MAXM],rc[MAXM],t[MAXM];
void fix(int &R,int l,int r,int l1,int r1,int d)
{
	if(!R)R=++N;
	if(l1<=l&&r<=r1)
	{
		t[R]=d;
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(lc[R],l,mid,l1,r1,d);
	if(r1>mid)fix(rc[R],mid+1,r,l1,r1,d);
}
int ask(int R,int l,int r,int x)
{
	if(!R)return n+1;
	int mid=l+r>>1,s;
	if(x<=mid)s=ask(lc[R],l,mid,x);
	else s=ask(rc[R],mid+1,r,x);
	if(t[R]&&t[R]<s)s=t[R];
	return s;
}
void fix(int x,int l,int r)
{
	if(l<r)fix(root,0,m-1,l,r-1,x);
	else
	{
		if(r)fix(root,0,m-1,0,r-1,x);
		fix(root,0,m-1,l,m-1,x);
	}
}
void check(int x,int i)
{
	if(i==n+1)ans=0;
	else ans=min(ans,f[i]+(l[i]+s[i]-x+m)%m);
}
void work(int R,int l,int r,int d)
{
	if(!R)
	{
		check(r,d);
		return;
	}
	if(t[R]&&t[R]<d)d=t[R];
	int mid=l+r>>1;
	work(lc[R],l,mid,d);
	work(rc[R],mid+1,r,d);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",r+i,l+i);
		l[i]=(m-l[i])%m;
		r[i]+=l[i];
		if(r[i]>=m)r[i]-=m;
	}
	for(i=1;i<n;i++)scanf("%d",d+i);
	for(i=n;i;i--)
	{
		s[i]=s[i+1]+d[i];
		u=(l[i]+s[i])%m;
		v=(r[i]+s[i])%m;
		fix(i,v,u);
		if(i==n)f[i]=0;
		else
		{
			j=ask(root,0,m-1,u);
			if(j>n)f[i]=0;
			else f[i]=f[j]+(l[j]-u+s[j]+m)%m;
		}
	}
	ans=1LL<<60;
	work(root,0,m-1,n+1);
	cout<<ans+s[1]<<endl;
	return 0;
}
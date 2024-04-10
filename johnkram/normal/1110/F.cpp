#include<bits/stdc++.h>
using namespace std;
#define MAXN 1048576
#define ll long long
ll t[MAXN],d[MAXN],ans[MAXN],m[MAXN];
int n,q,i,f[MAXN],a[MAXN],h1[MAXN],ne1[MAXN],v[MAXN],h[MAXN],ne[MAXN],u[MAXN],l[MAXN],r[MAXN];
inline void up(int R)
{
	t[R]=min(t[R<<1],t[R<<1|1])+m[R];
}
void build(int R,int l,int r)
{
	if(l==r)
	{
		t[R]=d[l];
		return;
	}
	int mid=l+r>>1;
	build(R<<1,l,mid);
	build(R<<1|1,mid+1,r);
	up(R);
}
void fix(int R,int l,int r,int l1,int r1,int d)
{
	if(l1<=l&&r<=r1)
	{
		t[R]+=d;
		m[R]+=d;
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1,d);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,d);
	up(R);
}
ll ask(int R,int l,int r,int l1,int r1)
{
	if(l1<=l&&r<=r1)return t[R];
	int mid=l+r>>1;
	ll s=1LL<<60;
	if(l1<=mid)s=min(s,ask(R<<1,l,mid,l1,r1));
	if(r1>mid)s=min(s,ask(R<<1|1,mid+1,r,l1,r1));
	return s+m[R];
}
void fix(int x,int d)
{
	fix(1,1,n,1,n,d);
	fix(1,1,n,x,v[x],-(d<<1));
}
void dfs(int x)
{
	fix(x,a[x]);
	int i;
	for(i=h1[x];i;i=ne1[i])ans[i]=ask(1,1,n,l[i],r[i]);
	for(i=h[x];i;i=ne[i])dfs(i);
	fix(x,-a[x]);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(i=2;i<=n;i++)
	{
		scanf("%d%d",f+i,a+i);
		d[i]=d[f[i]]+a[i];
		ne[i]=h[f[i]];
		h[f[i]]=i;
	}
	for(i=n;i;i--)if(h[i])
	{
		v[i]=v[h[i]];
		d[i]=1LL<<60;
	}
	else v[i]=i;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",u+i,l+i,r+i);
		ne1[i]=h1[u[i]];
		h1[u[i]]=i;
	}
	build(1,1,n);
	dfs(1);
	for(i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}
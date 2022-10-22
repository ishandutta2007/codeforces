#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,i,j,k,t[1200005],a[300005],d[1000005];
ll s[1200005];
void up(int R)
{
	s[R]=s[R<<1]+s[R<<1|1];
	t[R]=max(t[R<<1],t[R<<1|1]);
}
void build(int R,int l,int r)
{
	if(l==r)
	{
		s[R]=t[R]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(R<<1,l,mid);
	build(R<<1|1,mid+1,r);
	up(R);
}
ll ask(int R,int l,int r,int l1,int r1)
{
	if(l1<=l&&r<=r1)return s[R];
	int mid=l+r>>1;
	ll s=0;
	if(l1<=mid)s+=ask(R<<1,l,mid,l1,r1);
	if(r1>mid)s+=ask(R<<1|1,mid+1,r,l1,r1);
	return s;
}
void fix(int R,int l,int r,int l1,int r1)
{
	if(t[R]<3)return;
	if(l==r)
	{
		s[R]=t[R]=d[t[R]];
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1);
	up(R);
}
int main()
{
	for(i=1;i<=1000000;i++)for(j=i;j<=1000000;j+=i)d[j]++;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	build(1,1,n);
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)fix(1,1,n,j,k);
		else cout<<ask(1,1,n,j,k)<<endl;
	}
	return 0;
}
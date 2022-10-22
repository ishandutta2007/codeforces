#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 2000005
bool f;
ll t[MAXN],d[MAXN],s[MAXN];
int n,i,j,k,ans,a[MAXN],b[MAXN],m[MAXN];
void build(int R,int l,int r)
{
	m[R]=0;
	if(l==r)
	{
		t[R]=d[l];
		return;
	}
	int mid=l+r>>1;
	build(R<<1,l,mid);
	build(R<<1|1,mid+1,r);
	t[R]=max(t[R<<1],t[R<<1|1]);
}
void get(int R,int x)
{
	t[R]+=x;
	m[R]+=x;
}
void down(int R)
{
	if(m[R])
	{
		get(R<<1,m[R]);
		get(R<<1|1,m[R]);
		m[R]=0;
	}
}
void fix(int R,int l,int r,int l1,int r1,int x)
{
	if(l1<=l&&r<=r1)
	{
		get(R,x);
		return;
	}
	down(R);
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1,x);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,x);
	t[R]=max(t[R<<1],t[R<<1|1]);
}
void fix(int x)
{
	fix(1,1,n,x,n,-1);
	if(a[x]<x)fix(1,1,n,a[x],x-1,1);
	a[x]--;
}
void work()
{
	int i,j;
	for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(i=1,j=n;i<=n;i++)
	{
		d[i]=s[i];
		d[i]-=(ll)i*(i-1);
		for(;j&&a[j]<i;j--);
		d[i]-=(ll)(max(j,i)-i)*i+s[n]-s[max(j,i)];
	}
	build(1,1,n);
}
void ask()
{
	if(t[1]<=0)
	{
		printf("%d ",ans);
		f=1;
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	for(i=1;i<=n;i=j)
	{
		for(j=i+1;j<=n&&a[i]==a[j];j++);
		for(k=i;k<j;k++)b[k]=i+j-k-1;
	}
	work();
	for(i=1;i<=n;i++)ans^=a[i]&1;
	if(ans)fix(b[1]);
	ask();
	for(i=ans+1;i<=n;i+=2)if(i<n)
	{
		fix(b[i]);
		fix(b[i+1]);
		ans+=2;
		ask();
	}
	if(!f)puts("-1");
	return 0;
}
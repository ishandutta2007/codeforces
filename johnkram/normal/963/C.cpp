#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll gcd(ll x,ll y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
	if(!x||!y)return x|y;
	return x/gcd(x,y)*y;
}
struct node
{
	ll x,y,z;
	bool operator<(const node& b)const
	{
		if(x==b.x)return y<b.y;
		return x<b.x;
	}
}a[MAXN];
int n,X,Y,ans,i,j;
ll x[MAXN],y[MAXN],z[MAXN],w,w1,u;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&a[i].x,&a[i].y,&a[i].z);
		x[i]=a[i].x;
		y[i]=a[i].y;
	}
	sort(x,x+n);
	sort(y,y+n);
	X=unique(x,x+n)-x;
	Y=unique(y,y+n)-y;
	if((ll)X*Y!=n)
	{
		puts("0");
		return 0;
	}
	sort(a,a+n);
	for(i=0;i<n;i++)if(a[i].x!=x[i/Y]||a[i].y!=y[i%Y])break;
	if(i<n)
	{
		puts("0");
		return 0;
	}
	for(i=0;i<n;i++)z[i]=a[i].z;
	for(i=0;i<X;i++)
	{
		for(j=w=0;j<Y;j++)w=gcd(w,z[i*Y+j]);
		for(j=0;j<Y;j++)z[i*Y+j]/=w;
	}
	for(i=Y;i<n;i++)if(z[i]!=z[i-Y])break;
	if(i<n)
	{
		puts("0");
		return 0;
	}
	for(i=w=0;i<Y;i++)w=gcd(w,a[i].z);
	for(i=w1=1;i<X;i++)w1=lcm(w1,a[0].z/gcd(a[0].z,a[i*Y].z));
	if(w%w1!=0)
	{
		puts("0");
		return 0;
	}
	w/=w1;
	for(u=1;u*u<=w;u++)if(w%u==0)
	{
		ans++;
		if(u*u!=w)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
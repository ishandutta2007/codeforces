#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
#define int long long
using namespace std;

int n,cnt;
struct pnt
{
	int x,y;
}a[200005],b[200005],c[200005],d[200005],r[200005];
pnt operator -(pnt x,pnt y)
{
	return (pnt){x.x-y.x,x.y-y.y};
}
int crs(pnt x,pnt y)
{
	return x.x*y.y-x.y*y.x;
}
bool cmp(pnt x,pnt y)
{
	return crs(x,y)<0;
}

signed main()
{
	int i,j,k;
	scanf("%lld",&n);
	rep(i,n)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		r[i].x=-a[i].x;r[i].y=-a[i].y;
	}
	int t1=1,t2=1;
	rep(i,n)
	{
		if (a[i].x<a[t1].x||a[i].x==a[t1].x&&a[i].y<a[t1].y) t1=i;
		if (r[i].x<r[t2].x||r[i].x==r[t2].x&&r[i].y<r[t2].y) t2=i;
	}
	
	a[0]=a[n];
	r[0]=r[n];
	rep(i,n)
	{
		b[i]=a[(t1+i)%n]-a[(t1+i-1)%n];
		c[i]=r[(t2+i)%n]-r[(t2+i-1)%n];
	}
	
	rep(i,n)
	{
		if (b[i].x!=c[i].x||b[i].y!=c[i].y)
		{
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	return 0;
}
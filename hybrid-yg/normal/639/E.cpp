#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,k;
long long s[N];
long double l,r;
struct str{
	long long a,t,l,r;
}a[N];
bool cmp(str a,str b)
{
	return a.a*b.t>b.a*a.t;
}
bool cmp2(str a,str b)
{
	return a.a<b.a;
}
bool check(long double m)
{
	int i,j;
	long double mx=-1;
	for(i=1;i<=n;)
	{
		long double p=-1;
		for(j=i;j<=n&&a[i].a==a[j].a;++j)
		{
			if(a[j].a*(1-m*a[j].r/s[n])<mx)
				return false;
			p=max(p,a[j].a*(1-m*a[j].l/s[n]));
		}
		i=j;
		mx=max(mx,p);
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i].a);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i].t);
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i)
		s[i]=s[i-1]+a[i].t;
	for(i=1;i<=n;)
	{
		for(j=i;j<=n&&a[i].a*a[j].t==a[j].a*a[i].t;++j);
		for(k=i;k<j;++k)
			a[k].l=s[i-1]+a[k].t,a[k].r=s[j-1];
		i=j;
	}
	sort(a+1,a+1+n,cmp2);
	l=0,r=1;
	while(r-l>0.000000001)
	{
		double mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%.12LF",l);
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=500005;

int a[MAXN];

int main()
{
	int n,k;
	LL sum=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a,a+n);
	int lim=sum/n,rp=n-sum%n;
	LL ns=0;
	for (int i=0;i<rp&&a[i]<lim;i++)
		ns+=lim-a[i];
	lim++;
	for (int i=rp;i<n&&a[i]<lim;i++)
		ns+=lim-a[i];
	if (ns<=k)
	{
		printf("%d",rp==n?0:1);
		return 0;
	}
	int p,r;
	LL now=0;
	for (int i=1;i<n;i++)
	{
		now+=(LL)(a[i]-a[i-1])*i;
		if (now>k)
		{
			now-=(LL)(a[i]-a[i-1])*i;
			p=a[i-1]+(k-now)/i;
			break;
		}
	}
	now=0;
	for (int i=n-1;i>0;i--)
	{
		now+=(LL)(a[i]-a[i-1])*(n-i);
		if (now>k)
		{
			now-=(LL)(a[i]-a[i-1])*(n-i);
			r=a[i]-(k-now)/(n-i);
			break;
		}
	}
	printf("%d",r-p);
	return 0;
}
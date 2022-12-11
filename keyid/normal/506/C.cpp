#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int n,m,k,p,h[MAXN],a[MAXN],c[MAXN];
LL fn[MAXN];

bool check(LL x)
{
	LL sum=0;
	for (int i=0;i<n;i++)
		if (fn[i]>x)
			sum+=(fn[i]-x-1)/p+1;
	if (sum>m*k) return false;
	fill(c,c+m,0);
	for (int i=0;i<n;i++)
		if (fn[i]>x)
		{
			LL d=fn[i]-x;
			for (LL now=(d-1)%p+1;now<=d;now+=p)
				if (now<=h[i])
					c[0]++;
				else
					c[(now-h[i]-1)/a[i]+1]++;
		}
	int wt=0;
	for (int i=0;i<m;i++)
	{
		wt+=c[i];
		wt=max(0,wt-k);
	}
	return wt==0;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	LL l=0,r=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&h[i],&a[i]);
		fn[i]=(LL)a[i]*m+h[i];
		if (a[i]>l)
			l=a[i];
		r=max(r,fn[i]);
	}
	while (l<=r)
	{
		LL m=l+r>>1;
		if (check(m)) r=m-1;
		else l=m+1;
	}
	printf("%lld",l);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int n,d,b,mid,a[MAXN],sum[MAXN],mn1[MAXN],mn2[MAXN];

bool check(int x)
{
	return mn1[x+1]+x*b>=0&&mn2[n-x]+x*b>=0;
}

int main()
{
	scanf("%d%d%d",&n,&d,&b);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	mid=(n+1)/2;
	for (int i=1;i<=mid;i++)
		mn1[i]=sum[min((LL)i*(d+1),(LL)n)]-i*b;
	for (int i=mid-1;i>=1;i--)
		mn1[i]=min(mn1[i],mn1[i+1]);
	for (int i=mid+1;i<=n;i++)
		mn2[i]=sum[n]-sum[max(0LL,i-(LL)(n-i+1)*d-1)]-(n-i+1)*b;
	for (int i=mid+2;i<=n;i++)
		mn2[i]=min(mn2[i],mn2[i-1]);
	for (int i=0;;i++)
		if (check(i))
		{
			printf("%d",i);
			break;
		}
	return 0;
}
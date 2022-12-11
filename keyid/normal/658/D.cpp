#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

LL a[MAXN],b[MAXN];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		b[i]=a[i];
	}
	for (int i=0;i<n;i++)
	{
		b[i+1]+=b[i]/2;
		b[i]%=2;
	}
	int ans=0,l=0;
	while (b[l]==0) l++;
	LL cnt=0;
	for (int i=n;i>l;i--)
	{
		cnt=cnt*2+b[i];
		if (abs(cnt)>k*2)
		{
			printf("0");
			return 0;
		}
	}
	for (int i=l;i>=0;i--)
	{
		cnt=cnt*2+b[i];
		if (abs(cnt)>k*2)
		{
			printf("%d",ans);
			return 0;
		}
		if (i==n&&a[i]==cnt) continue;
		if (abs(a[i]-cnt)<=k) ans++;
	}
	printf("%d",ans);
	return 0;
}
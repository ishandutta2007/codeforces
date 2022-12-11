#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int t[MAXN],a[MAXN];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int lst=-1,cnt=0,cnt2=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		if (t[i]<0)
		{
			if (--k<0)
			{
				printf("-1");
				return 0;
			}
			if (lst>0&&lst<i-1)
				a[cnt++]=i-lst-1;
			if (lst<i-1)
				cnt2+=2;
			lst=i;
		}
	}
	sort(a,a+cnt);
	int ans=cnt2,tk=k;
	if (lst==n) ans--;
	for (int i=0;i<cnt&&tk>=a[i];i++)
	{
		ans-=2;
		tk-=a[i];
	}
	int ans2=cnt2;
	if (lst==n) ans2--;
	else if (k>=n-lst)
	{
		ans2--;
		k-=n-lst;
		for (int i=0;i<cnt&&k>=a[i];i++)
		{
			ans2-=2;
			k-=a[i];
		}
	}
	printf("%d",min(ans,ans2));
	return 0;
}
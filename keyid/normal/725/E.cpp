#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int n,c,maxbit,a[MAXN];
LL sum[MAXN];

bool check(int x)
{
	int pos=1,now=c,k=lower_bound(a+1,a+n+1,x,greater<int>())-a;
	while (pos<k)
	{
		for (int i=maxbit;i>=0;i--)
			if (pos+(1<<i)<=k&&sum[pos+(1<<i)-1]-sum[pos-1]<=now)
			{
				now-=sum[pos+(1<<i)-1]-sum[pos-1];
				pos+=1<<i;
			}
		pos=lower_bound(a+pos,a+n+1,now,greater<int>())-a;
	}
	if (now<=x)
		return false;
	now-=x;
	pos=lower_bound(a+1,a+n+1,now,greater<int>())-a;
	while (pos<=n)
	{
		for (int i=maxbit;i>=0;i--)
			if (pos+(1<<i)-1<=n&&sum[pos+(1<<i)-1]-sum[pos-1]<=now)
			{
				now-=sum[pos+(1<<i)-1]-sum[pos-1];
				pos+=1<<i;
			}
		pos=lower_bound(a+pos,a+n+1,now,greater<int>())-a;
	}
	return now!=0;
}

int main()
{
	scanf("%d%d",&c,&n);
	while ((1<<maxbit)<=n) maxbit++;maxbit--;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<LL>());
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=c;i++)
		if (check(i))
		{
			printf("%d",i);
			return 0;
		}
	printf("Greed is good");
	return 0;
}
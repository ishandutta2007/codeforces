#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int a[MAXN],d[5][MAXN];
priority_queue <LL> q;

int main()
{
	int n,k,b,c;
	scanf("%d%d%d%d",&n,&k,&b,&c);
	b=min(b,5*c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		for (int j=0;j<5;j++)
			d[((a[i]+j)%5+5)%5][i]=a[i]+j;
	LL ans=LLONG_MAX;
	for (int j=0;j<5;j++)
	{
		LL sum=0;
		for (int i=1;i<=k;i++)
		{
			LL t=c*(d[j][i]-a[i])+(LL)b*(d[j][k]-d[j][i])/5;
			q.push(t);
			sum+=t;
		}
		ans=min(ans,sum);
		for (int i=k+1;i<=n;i++)
		{
			LL t=c*(d[j][i]-a[i])-(LL)b*(d[j][i]-d[j][k])/5;
			q.push(t);
			sum+=t-q.top();
			q.pop();
			ans=min(ans,sum+(LL)k*b*(d[j][i]-d[j][k])/5);
		}
		while (!q.empty()) q.pop();
	}
	printf("%I64d",ans);
	return 0;
}
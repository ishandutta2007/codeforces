#include <cstdio>

typedef long long LL;

const int MAXN=1000005;

int d[MAXN];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int a,b;m--;)
	{
		scanf("%d%d",&a,&b);
		d[a]++;
		d[b]++;
	}
	LL cnt=0;
	for (int i=1;i<=n;i++) cnt+=(LL)d[i]*(n-1-d[i]);
	printf("%I64d",(LL)n*(n-1)*(n-2)/6-cnt/2);
	return 0;
}
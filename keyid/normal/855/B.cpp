#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

LL f[MAXN][3];

int main()
{
	int n,p,q,r;
	scanf("%d%d%d%d",&n,&p,&q,&r);
	f[0][0]=f[0][1]=f[0][2]=LLONG_MIN/2;
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		f[i][0]=max(f[i-1][0],(LL)p*a);
		f[i][1]=max(f[i-1][1],max(f[i-1][0]+(LL)q*a,(LL)(p+q)*a));
		f[i][2]=max(f[i-1][2],max(f[i-1][1]+(LL)r*a,max(f[i-1][0]+(LL)(q+r)*a,((LL)p+q+r)*a)));
	}
	printf("%lld",f[n][2]);
	return 0;
}
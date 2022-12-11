#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	//freopen("read.txt","r",stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	LL s=2LL*n*m;
	if (s%k)
		printf("NO");
	else
	{
		s/=k;
		if (s/__gcd(s,(LL)m)<=n)
		{
			puts("YES");
			puts("0 0");
			printf("0 %lld\n",__gcd(s,(LL)m));
			s/=__gcd(s,(LL)m);
			printf("%lld 0",s);	
		}
		else if (s/__gcd(s,(LL)n)<=m)
		{
			puts("YES");
			puts("0 0");
			printf("%lld 0\n",__gcd(s,(LL)n));
			s/=__gcd(s,(LL)n);
			printf("0 %lld",s);	
		}
		else
			printf("NO");
	}
	return 0;
}
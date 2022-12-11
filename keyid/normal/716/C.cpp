#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	int n;
	scanf("%d",&n);
	puts("2");
	for (int i=2;i<=n;i++)
		printf("%lld\n",(LL)i*(i+2)*i+1);
	return 0;
}
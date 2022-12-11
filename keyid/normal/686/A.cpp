#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	int n;
	LL x;
	scanf("%d%lld",&n,&x);
	char op[5];
	int cnt=0;
	while (n--)
	{
		LL d;
		scanf("%s%lld",op,&d);
		if (op[0]=='+') x+=d;
		else if (x>=d) x-=d;
		else cnt++;
	}
	printf("%lld %d",x,cnt);
	return 0;
}
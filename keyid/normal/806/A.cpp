#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
	int x,y,p,q;
	scanf("%d%d%d%d",&x,&y,&p,&q);
	int d=q-p;
	if (p==0)
	{
		if (x) puts("-1");
		else puts("0");
		return;
	}
	if (d)
	{
		int k=(y-x+d-1)/d;
		k=max(k,(y+q-1)/q);
		k=max(k,(x+p-1)/p);
		printf("%lld\n",(LL)k*q-y);
	}
	else if (x==y)
		puts("0");
	else puts("-1");
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	k=min(k,n/2);
	LL ans=0;
	for (int i=1;i<=k;i++)
	{
		ans+=n-1<<1;
		ans--;
		n-=2;
	}
	printf("%I64d",ans);
	return 0;
}
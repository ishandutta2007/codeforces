#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	k=240-k;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		k-=5*i;
		if (k<0) break;
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}
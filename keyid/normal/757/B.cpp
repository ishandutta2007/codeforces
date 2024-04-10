#include <bits/stdc++.h>
using namespace std;

const int MAXS=100005;

int cnt[MAXS];

int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int s;
		scanf("%d",&s);
		int m=sqrt(s+0.5);
		for (int i=1;i<=m;i++)
			if (s%i==0)
			{
				cnt[i]++;
				if (i*i!=s)
					cnt[s/i]++;
			}
	}
	int ans=1;
	for (int i=2;i<=100000;i++)
		ans=max(ans,cnt[i]);
	printf("%d",ans);
	return 0;
}
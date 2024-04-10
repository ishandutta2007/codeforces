#include <bits/stdc++.h>
using namespace std;

int occ[20];
int n, k;

void yer()
{
	printf("YES\n");
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
	{
		int z = 0;
		for (int j = 0;j < k;j++)
		{
			int x; scanf("%d", &x);
			z |= x<<j;
		}
		occ[z]++;
	}
	if (occ[0]) yer();
	for (int i = 0;i < (1<<k);i++) for (int j = 0;j < (1<<k);j++) if (occ[i] && occ[j] && !(i&j))
		yer();
	printf("NO\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int on[128];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	while (n--)
	{
		int k; scanf("%d", &k);
		while (k--)
		{
			int x; scanf("%d", &x);
			on[--x] = 1;
		}
	}
	for (int i = 0;i < m;i++) if (!on[i])
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}
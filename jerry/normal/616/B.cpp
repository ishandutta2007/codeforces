#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		c = 1<<30;
		for (int j = 0;j < m;j++) scanf("%d", &d), c = min(c, d);
		b = max(b, c);
	}
	printf("%d\n", b); return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, d, h;

int main()
{
	scanf("%d%d%d", &n, &d, &h);
	if (n == 2)
	{
		printf("1 2\n");
		return 0;
	}
	if (h*2 < d || (d == 1 && n > 2))
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0;i < h;i++) printf("%d %d\n", 1+i, 2+i);
	for (int i = 0;i < d-h;i++) printf("%d %d\n", i?h+1+i:1, h+2+i);
	for (int i = d+2;i <= n;i++) printf("%d %d\n", h, i);
	return 0;
}
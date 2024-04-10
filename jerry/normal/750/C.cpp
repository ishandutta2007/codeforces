#include <bits/stdc++.h>
using namespace std;

int lo = -1000000000, hi = 1000000000;
int n;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		int c, d; scanf("%d%d", &c, &d);
		if (d == 1) lo = max(lo, 1900);
		else hi = min(hi, 1899);
		lo += c;
		hi += c;
	}
	if (lo > hi) printf("Impossible\n");
	else if (hi >= 500000000) printf("Infinity\n");
	else printf("%d\n", hi);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int occ[1000005];
int n, x;
int best = -1;

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		occ[x]++;
		if (occ[x] > occ[best])
			best = x;
	}
	printf("%d\n", best);
	return 0;
}
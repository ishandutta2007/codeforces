#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, t, x;

int main()
{
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	t = a+b+c+d;
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a+b+c+d > t) x++;
	}
	printf("%d\n", ++x);
	return 0;
}
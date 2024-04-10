#include <bits/stdc++.h>
using namespace std;

int a, l, n, x, y;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a);
		if (a <= l) x = 1;
		else y = max(y, ++x);
		l = a;
	}
	printf("%d\n", y);
	return 0;
}
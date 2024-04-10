#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	a--;
	a += b;
	while (a < 0)
		a += n;
	a %= n;
	a++;
	printf("%d\n", a);
}
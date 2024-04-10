#include <bits/stdc++.h>
using namespace std;

int f(int a)
{
	while (!(a&1)) a >>= 1;
	while (a%3==0) a /= 3;
	return a;
}

int main()
{
	int n, k, a, t;
	scanf("%d%d", &n, &a);
	k = f(a);
	while (--n)
	{
		scanf("%d", &a);
		t = f(a);
		if (k != t)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
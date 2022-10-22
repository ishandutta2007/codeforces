#include <bits/stdc++.h>

using namespace std;

namespace CF
{
	int gcd(int a, int b)
	{
		while (a)
		{
			int t = b % a;
			b = a;
			a = t;
		}
		return b;
	}

	void work()
	{
		int kase;
		scanf("%d", &kase);
		while (kase--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			puts(gcd(a, b) == 1 ? "Finite" : "Infinite");
		}
	}
}

int main()
{
	CF::work();
	return 0;
}
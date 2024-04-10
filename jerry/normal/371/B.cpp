#include <cstdio>
#include <queue>

using namespace std;

int ans;

int gcd(int a, int b)
{
	while (a != 0 && b != 0 && a != b)
	{
		if (a > b) a %= b;
		else       b %= a;
	}
	if (a == 0)
		return b;
	return a;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c = gcd(a, b);
	while ((a/c)%2 == 0)
	{
		ans++;
		a /= 2;
	}
	while ((a/c)%3 == 0)
	{
		ans++;
		a /= 3;
	}
	while ((a/c)%5 == 0)
	{
		ans++;
		a /= 5;
	}
	while ((b/c)%2 == 0)
	{
		ans++;
		b /= 2;
	}
	while ((b/c)%3 == 0)
	{
		ans++;
		b /= 3;
	}
	while ((b/c)%5 == 0)
	{
		ans++;
		b /= 5;
	}
	if (a != c || b != c)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
#include <cstdio>

int sqrt[1000001], a, b;

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	return gcd(y%x, x);
}

int main()
{
	for (int i = 0;i < 1001;i++)
		sqrt[i*i] = i;
	scanf("%d%d", &a, &b);
	for (int x = 1;x < a;x++)
	{
		int y = sqrt[a*a-x*x];
		if (y == 0)
			continue;
		int g = gcd(x, y);
		int X = -y / g;
		int Y = x / g;
		int l = X*X+Y*Y;
		if (sqrt[l] == 0)
			continue;
		if (b%sqrt[l] != 0)
			continue;
		X = X * b / sqrt[l];
		Y = Y * b / sqrt[l];
		if (X == x || Y == y)
			continue;
		printf("YES\n%d %d\n%d %d\n0 0\n", x, y, X, Y);
		return 0;
	}
	printf("NO\n");
	return 0;
}
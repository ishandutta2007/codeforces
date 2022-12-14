#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int M = 1000000007;
const int I2 = M + 1 >> 1;

inline int get(int n, int m, int k, int &cnt, int d = 0)
{
	if (!m || k <= 0)
		return 0;
	int l = min(n, k);
	int ret = (s64)m * l % M * (l + 1) % M * I2 % M;
	cnt = (cnt + (s64)m * l) % M;
	return (ret + (s64)d * l % M * m) % M;
}

int solve(int x, int y, int l, int k, int &cnt)
{
	if (k <= 0 || x <= 0 || y <= 0)
		return cnt = 0;
	if (l == 0)
		return cnt = k >= 1;

	int half = 1 << l - 1, ret = 0;
	if (x <= half && y <= half)
		return solve(x, y, l - 1, k, cnt);
	else if (x <= half && y > half)
	{
		ret = (ret + solve(x, y - half, l - 1, k - half, cnt)) % M;
		ret = (ret + (s64)cnt * half) % M;
		ret = (ret + get(half, x, k, cnt)) % M;
		return ret;
	}
	else if (x > half && y <= half)
	{
		ret = (ret + solve(x - half, y, l - 1, k - half, cnt)) % M;
		ret = (ret + (s64)cnt * half) % M;
		ret = (ret + get(half, y, k, cnt)) % M;
		return ret;
	}
	else
	{
		ret = (ret + solve(x - half, y - half, l - 1, k, cnt)) % M;
		ret = (ret + get(half, x - half, k - half, cnt, half)) % M;
		ret = (ret + get(half, y - half, k - half, cnt, half)) % M;
		ret = (ret + get(half, half, k, cnt)) % M;
		return ret;
	}
}

int main()
{
	int q = getint();
	while (q--)
	{
		int x1 = getint(), y1 = getint();
		int x2 = getint(), y2 = getint();
		int k = getint(), res = 0, cnt;
		res = (res + solve(x2, y2, 30, k, cnt)) % M;
		res = (res + solve(x1 - 1, y1 - 1, 30, k, cnt)) % M;
		res = (res - solve(x1 - 1, y2, 30, k, cnt) + M) % M;
		res = (res - solve(x2, y1 - 1, 30, k, cnt) + M) % M;
		printf("%d\n", res);
	}

	return 0;
}
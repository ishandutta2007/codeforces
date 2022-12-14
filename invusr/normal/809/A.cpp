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

const int MaxN = 300005;
const int M = 1000000007;

int n, a[MaxN];
int pow2[MaxN];

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	sort(a + 1, a + n + 1);

	pow2[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		pow2[i] = pow2[i - 1] << 1;
		if (pow2[i] >= M)
			pow2[i] -= M;
	}

	int res = 0;
	for (int i = 1; i < n; ++i)
	{
		int delta = a[i + 1] - a[i];
		int l = pow2[i - 0] - 1;
		int r = pow2[n - i] - 1;
		res = (res + (s64)delta * l % M * r) % M;
	}

	cout << (res + M) % M << endl;

	return 0;
}
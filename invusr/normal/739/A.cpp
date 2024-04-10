#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100005;
const int INF = 1000000000;

int n, m, len = INF;

int main()
{
	n = getint(), m = getint();
	for (int i = 0; i < m; ++i)
	{
		int l = getint(), r = getint();
		len = min(len, r - l + 1);
	}

	printf("%d\n", len);
	for (int i = 0; i < n; ++i)
		printf("%d ", i % len);

	return 0;
}
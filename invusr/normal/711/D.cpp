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

const int MaxN = 200005;
const int M = 1000000007;

int n, to[MaxN];

int book[MaxN];
int length[MaxN];

int pow2[MaxN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		to[i] = getint();

	pow2[0] = 1;
	for (int i = 1; i <= n; ++i)
		pow2[i] = pow2[i - 1] * 2 % M;

	int total = 1, rest = n;
	for (int u = 1; u <= n; ++u)
	{
		if (book[u])
			continue;

		int now = u;
		while (true)
		{
			book[now] = u;

			int v = to[now];
			if (!book[v])
				length[v] = length[now] + 1, now = v;
			else if (book[v] < u)
				break;
			else
			{
				int cir_len = length[now] - length[v] + 1;
				total = (s64)total * (pow2[cir_len] - 2 + M) % M;
				rest -= cir_len;
				break;
			}
		}
	}

	total = (s64)total * pow2[rest] % M;

	cout << total;

	return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

const int MaxN = 2005;
const int MaxTN = MaxN * MaxN;
const int M = 1073741823;

int a, b, c, n;

bool book[MaxTN];
int pri_n = 0, pri[MaxTN];
int mu[MaxTN];

int f[MaxTN];

inline bool init_sieve()
{
	mu[1] = 1;
	for (int i = 2; i <= n * n; ++i)
	{
		if (!book[i])
			pri[pri_n++] = i, mu[i] = -1;

		for (int j = 0; j < pri_n; ++j)
		{
			int prod = i * pri[j];
			if (prod > n * n)
				break;
			book[prod] = true;

			if (i % pri[j])
				mu[prod] = -mu[i];
			else
			{
				mu[prod] = 0;
				break;
			}
		}
	}

	for (int d = 1; d <= n * n; ++d)
	{
		int sum = 0, up = c / d;
		for (int k = 1; k <= up; ++k)
			sum += up / k;
		for (int i = d; i <= n * n; i += d)
			f[i] += mu[d] * sum;
	}
}

int gcd[MaxN][MaxN];

inline void init_gcd()
{
	for (int i = 1; i <= n; ++i)
		gcd[i][0] = gcd[0][i] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			gcd[i][j] = gcd[j][i] = gcd[j][i % j];
}

int main()
{
	cin >> a >> b >> c;
	n = max(max(a, b), c);

	init_sieve();
	init_gcd();

	int res = 0;
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			if (gcd[i][j] == 1)
				res += (a / i) * (b / j) * f[i * j];

	cout << (res & M);
	cout << endl;

	return 0;
}
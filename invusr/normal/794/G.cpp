#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 300005;
const int MaxTN = 200005;
const int R = 9000000;
const int M = 1000000007;

inline int add(int a, const int &b)
{
	a += b;
	return a >= M ? a - M : a;
}
inline int dec(int a, const int &b)
{
	a -= b;
	return a < 0 ? a + M : a;
}

inline int gcd(int a, int b)
{
	while (b > 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

inline int modpow(int a, const s64 &n)
{
	int res = 1;
	for (s64 i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

s64 n;
int len1, len2;
char s1[MaxN], s2[MaxN];

int fact[MaxN * 2], rfact[MaxN * 2];

int tn, sq;
s64 val[MaxTN];
int pref[MaxTN];

int pow2[MaxTN];

int pri_n = 0, pri[R / 5];
bool book[R + 1];

int inv[R + 1];
int mu[R + 1], f[R + 1];

inline int pos(s64 x)
{
	return x <= sq ? x : tn - n / x + 1;
}

inline int binom(int n, int m)
{
	if (m < 0 || m > n)
		return 0;
	return (s64)fact[n] * rfact[m] % M * rfact[n - m] % M;
}

inline void init(int m)
{
	mu[1] = f[1] = inv[1] = 1;
	for (int i = 2; i <= R; ++i)
	{
		inv[i] = (s64)(M - M / i) * inv[M % i] % M;

		if (!book[i])
		{
			pri[pri_n++] = i;
			mu[i] = M - 1;
			f[i] = (1 + M - inv[i]) % M;
		}

		for (int j = 0; j < pri_n; ++j)
		{
			int d = i * pri[j];
			if (d > R)
				break;
			book[d] = true;

			f[d] = f[i];
			if (i % pri[j] == 0)
				break;
			f[d] = (s64)f[d] * f[pri[j]] % M;
			mu[d] = M - mu[i];
		}
	}

	for (int i = 2; i <= R; ++i)
	{
		f[i] = (s64)i * (f[i] << 1) % M;
		f[i] = add(f[i], f[i - 1]);
		mu[i] = add(mu[i], mu[i - 1]);
	}

	fact[0] = 1;
	for (int i = 1; i <= m; ++i)
		fact[i] = (s64)fact[i - 1] * i % M;
	rfact[m] = modpow(fact[m], M - 2);
	for (int i = m; i >= 1; --i)
		rfact[i - 1] = (s64)rfact[i] * i % M;

	sq = sqrt(n) + 0.5;
	for (int i = 1; i <= sq; ++i)
		val[++tn] = i;
	for (int i = sq - (n / sq == sq); i; --i)
		val[++tn] = n / i;

	for (int i = 1; i <= tn; ++i)
	{
		s64 x = val[i];
		if (x <= R)
		{
			pref[i] = mu[x];
			continue;
		}

		pref[i] = 1;
		for (s64 j = 2, k; j <= x; j = k + 1)
		{
			k = x / (x / j);
			pref[i] = dec(pref[i], (s64)(k - j + 1) * pref[pos(x / j)] % M);
		}
	}

	for (int i = 0; i <= tn; ++i)
		pow2[i] = modpow(2, val[i] + 1);
}

inline int query(s64 n)
{
	if (n <= R)
		return f[n];

	int res = 0, last = 0;
	for (s64 i = 1, j; i <= n; i = j + 1)
	{
		j = n / (n / i);
		int u = dec(pref[pos(j)], pref[last]);
		int v = (s64)(n / i) % M * ((n / i) % M) % M;
		res = add(res, (s64)u * v % M);
		last = pos(j);
	}
	return res;
}

int main()
{
//	freopen("problem.in", "r", stdin);
//	freopen("problem.out", "w", stdout);

	scanf("%s%s%lld", s1, s2, &n);
	len1 = strlen(s1);
	len2 = strlen(s2);

	init(len1 + len2);

	int d1 = 0, q1 = 0;
	int d2 = 0, q2 = 0;
	for (int i = 0; i < len1; ++i)
		s1[i] == 'A' ? ++d1 : (s1[i] == 'B' ? --d2 : ++q1);
	for (int i = 0; i < len2; ++i)
		s2[i] == 'A' ? --d1 : (s2[i] == 'B' ? ++d2 : ++q2);

	int cop = 0, res = 0;
	for (s64 i = 1, j; i <= n; i = j + 1)
	{
		j = n / (n / i);
		int u = modpow(2, j + 1);
		int v = modpow(2, i);
		cop = add(cop, (s64)dec(u, v) * query(n / i) % M);
	}

	if (len1 == len2)
	{
		int total = 0;
		for (int i = 0; i < len1 && ~total; ++i)
		{
			if (s1[i] + s2[i] == 'A' + 'B')
				total = -1;
			if (s1[i] + s2[i] == '?' + '?')
				++total;
		}

		if (~total)
		{
			int any = (modpow(2, n + 1) + M - 2) % M;
			any = (s64)any * any % M;
			res = (s64)modpow(2, total) * (any + M - cop) % M;
		}
	}

	d2 += q2 - q1;
	for (int d = -q2; d <= q1; ++d)
	{
		int new_d1 = d1 + d;
		int new_d2 = d2 + d;
		int ways = binom(q1 + q2, q2 + d);

		if (!new_d1 && !new_d2)
			res = add(res, (s64)cop * ways % M);
		else
		{
			int u = new_d1, v = new_d2;
			if (u < 0)
				u = -u, v = -v;
			if (v < 0)
				u = -u, v = -v;
			if (u > 0 && v > 0)
			{
				int g = gcd(u, v);
				s64 k = n / (max(u, v) / g);
				res = add(res, (s64)ways * (pow2[pos(k)] + M - 2) % M);
			}
		}
	}

	printf("%d\n", res);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
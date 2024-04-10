#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef unsigned u32;
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

const int MaxN = 50005;
const int M = 1000000007;
const int L = 31;
const int MaxTN = MaxN * L;

int n;
u32 m;
int val[MaxN];

int tn = 1;
int next[MaxTN][2];
int book[MaxTN];
int occur[MaxTN][L];
int sum = 0;
u32 cnt = 0;

inline int get_bit(int x, int l)
{
	return (x >> l & 1) ^ 1;
}

inline void trie_insert(const int &x)
{
	int now = 1;
	for (int l = 29; l >= 0; --l)
	{
		int d = x >> l & 1;
		if (next[now][d] == 0)
			next[now][d] = ++tn;
		++book[now];
		now = next[now][d];
	}
	++book[now];
	for (int l = 0; l < 30; ++l)
		occur[now][l] += x >> l & 1;
}

inline int trie_query(u32 k)
{
	static int cur[MaxN];
	static int bit[MaxN];
	for (int i = 1; i <= n; ++i)
		cur[i] = 1;

	int now = 0;
	for (int l = 29; l >= 0; --l)
	{
		u32 num = 0;
		for (int i = 1; i <= n; ++i)
			num += book[next[cur[i]][bit[i] = get_bit(val[i], l)]];

		if (num >= k)
			now |= 1 << l;
		else
		{
			k -= num;
			for (int i = 1; i <= n; ++i)
				bit[i] = !bit[i];
		}

		for (int i = 1; i <= n; ++i)
			cur[i] = next[cur[i]][bit[i]];
	}

	return now;
}

inline void add(int v, int u)
{
	cnt += book[u];
	for (int i = 0; i < 30; ++i)
	{
		int b = v >> i & 1;
		int s = b ? book[u] - occur[u][i] : occur[u][i];
		sum += ((s64)s << i) % M;
		sum %= M;
	}
}

inline void trie_count(int x, int v)
{
	int now = 1;
	for (int l = 29; l >= 0; --l)
	{
		int d = x >> l & 1;
		int k = v >> l & 1, u = next[now][!k];
		if (d == 1)
			now = u;
		else
		{
			add(v, u);
			now = next[now][k];
		}
	}
	add(v, now);
}

int main()
{
	n = getint(), m = getint();
	for (int i = 1; i <= n; ++i)
	{
		val[i] = getint();
		trie_insert(val[i]);
	}

	for (int x = tn; x; --x)
	{
		int l = next[x][0];
		int r = next[x][1];
		for (int i = 0; i < 30; ++i)
			occur[x][i] += occur[l][i] + occur[r][i];
	}

	int res = trie_query((u32)m * 2);
	for (int i = 1; i <= n; ++i)
		trie_count(res, val[i]);

//	cout << cnt << endl;

	sum -= (s64)res * ((u32)cnt - m - m) % M;
	cout << (s64)(sum + M) * (M + 1 >> 1) % M;
	cout << endl;

	return 0;
}
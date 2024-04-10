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

const int MaxN = 1005;
const int N = 8;

int n, a[MaxN];
int cnt[N];

int f[1 << N][MaxN];

int last[N];
int next[MaxN][N];

int go[MaxN][N][2];

inline int solve(const int &l)
{
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < N; ++j)
		{
			int now = i;
			for (int k = 1; k < l; ++k)
				now = next[now][j];
			go[i][j][0] = now;
			go[i][j][1] = next[now][j];
		}

	int all = 1 << N;
	for (int s = 0; s < all; ++s)
		fill(f[s], f[s] + n + 1, 0);
	for (int s = 0; s < all; ++s)
	{
		int bits = 0;
		for (int i = 0; i < N; ++i)
			bits += s >> i & 1;

		for (int i = 0; i <= n; ++i)
		{
			if (f[s][i] < bits * (l - 1))
				continue;
			for (int j = 0; j < N; ++j)
			{
				if (s >> j & 1)
					continue;
				int news = s | 1 << j;
				int kl = go[i][j][0];
				int kr = go[i][j][1];
				f[news][kl] = max(f[news][kl], f[s][i] + l - 1);
				f[news][kr] = max(f[news][kr], f[s][i] + l - 0);
			}
		}
	}

	return *max_element(f[all - 1], f[all - 1] + n + 1);
}

inline bool check(const int &l)
{
	return solve(l) >= (l - 1) * N;
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		++cnt[a[i] = getint() - 1];

	for (int i = 0; i < N; ++i)
		last[i] = next[n + 1][i] = n + 1;
	for (int i = n; i >= 0; --i)
	{
		for (int k = 0; k < N; ++k)
			next[i][k] = last[k];
		last[a[i]] = i;
	}

	int l = 1;
	int r = *max_element(cnt, cnt + N);
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << solve(r) << endl;

	return 0;
}
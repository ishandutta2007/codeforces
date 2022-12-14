#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int MaxN = 100000;
const int MaxM = MaxN * 4 + 2;
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

inline int modpow(int a, const int &n)
{
	int res = 1;
	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

int k, n, m;
int la[MaxN], ra[MaxN];
int lb[MaxN], rb[MaxN];

int limit[2][MaxM];

vector<int> all;

inline int get(int x)
{
	return lower_bound(all.begin(), all.end(), x) - all.begin();
}

int f[2][MaxM];
int g[2], h[2];

inline void add(int x, int y, int d)
{
	f[x][y] = add(f[x][y], d);
	g[x] = add(g[x], d);
}

int main()
{
	cin >> k >> n >> m;

	all = {-1, 0, k};
	for (int i = 0; i < n; ++i)
	{
		cin >> la[i] >> ra[i];
		all.push_back(--la[i]);
		all.push_back(ra[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> lb[i] >> rb[i];
		all.push_back(--lb[i]);
		all.push_back(rb[i]);
	}

	sort(all.begin(), all.end());
	auto iter = unique(all.begin(), all.end());
	all.resize(iter - all.begin());

	for (int i = 0; i < n; ++i)
	{
		int &x = limit[0][get(ra[i])];
		x = max(x, get(la[i]));
	}
	for (int i = 0; i < m; ++i)
	{
		int &x = limit[1][get(rb[i])];
		x = max(x, get(lb[i]));
	}

	add(0, 0, 1);

	int l = all.size();
	for (int i = 1; i < l - 1; ++i)
	{
		int s[2] = {g[0], g[1]};
		int v = dec(modpow(2, all[i + 1] - all[i]), 2);

		v = (s64)v * (s[0] + s[1]) % M;

		add(0, i, v);

		for (int j = 0; j < 2; ++j)
		{
			add(j, i - 1, s[!j]);
			while (h[j] < limit[!j][i + 1])
				g[j] = dec(g[j], f[j][h[j]++]);
		}
	}

	cout << add(g[0], g[1]) << endl;

	return 0;
}
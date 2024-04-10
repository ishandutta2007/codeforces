#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int MaxN = 8;
const int MaxM = 25;
const int MaxLogN = 30;
const int N = 70;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int x, k, n, m;
int cost[MaxN + 1];

struct object
{
	int x, v;
	object() {}
	object(const int &_x, const int &_v)
		: x(_x), v(_v) {}

	friend inline bool operator<(const object &lhs, const object &rhs)
	{
		return lhs.x < rhs.x;
	}
};
object a[MaxM];

struct matrix
{
	int n, m;
	s64 a[N][N];

	friend inline matrix operator*(const matrix &lhs, const matrix &rhs)
	{
		matrix res;
		res.n = lhs.n;
		res.m = rhs.m;

		for (int i = 0; i < lhs.n; ++i)
			for (int j = 0; j < rhs.m; ++j)
			{
				s64 w = INF;
				for (int k = 0; k < lhs.m; ++k)
					w = min(w, lhs.a[i][k] + rhs.a[k][j]);
				res.a[i][j] = w;
			}

		return res;
	}
};
matrix prePow[MaxLogN + 1];

inline void transfer(matrix &a, int n)
{
	for (int i = 0; i <= MaxLogN; ++i)
		if (n >> i & 1)
			a = a * prePow[i];
}

int bit[1 << MaxN];

int sta_n = 0;
int sta[N], pos[1 << MaxN];

int trans[N][MaxN + 1];

matrix res;

inline string orz(int s)
{
	string t = "";
	for (int i = 0; i < k; ++i)
		t += '0' + (s & 1), s >>= 1;
	return t;
}

int main()
{
	cin >> x >> k >> n >> m;
	for (int i = 1; i <= k; ++i)
		cin >> cost[i];
	for (int i = 0; i < m; ++i)
		cin >> a[i].x >> a[i].v;

	sort(a, a + m);

	int all = 1 << k;
	for (int s = 0; s < all; ++s)
		pos[s] = -1;
	for (int s = 1; s < all; ++s)
	{
		bit[s] = bit[s >> 1] + (s & 1);
		if (bit[s] == x)
			pos[sta[sta_n] = s] = sta_n, ++sta_n;
	}

	int start = 0;
	for (int i = 0; i < x; ++i)
		start |= 1 << (k - i - 1);

	prePow[0].n = sta_n;
	prePow[0].m = sta_n;
	for (int i = 0; i < sta_n; ++i)
		for (int j = 0; j < sta_n; ++j)
			prePow[0].a[i][j] = INF;

	res.n = 1;
	res.m = sta_n;
	for (int i = 0; i < sta_n; ++i)
	{
		int s = sta[i];
		res.a[0][i] = s == start ? 0 : INF;

		int t = trans[i][0] = (~s & 1) ? pos[s >> 1] : -1;
		if (t != -1)
			prePow[0].a[i][t] = 0;

		for (int j = 1; j <= k; ++j)
		{
			int u = k - 1;
			int v = k - j;
			int d = ((s ^ (1 << v)) >> 1) | (1 << u);

			t = trans[i][j] = ((~s & 1) || !v) && (s >> v & 1) ? pos[d] : -1;
			if (t != -1)
				prePow[0].a[i][t] = cost[j];
		}
	}

	for (int i = 0; i < MaxLogN; ++i)
		prePow[i + 1] = prePow[i] * prePow[i];

	int l = x;
	for (int p = 0; p < m; ++p)
	{
		int k = a[p].x;
		int w = a[p].v;
		transfer(res, k - l - 1);

		s64 cur[N];
		for (int i = 0; i < sta_n; ++i)
			cur[i] = INF;

		for (int i = 0; i < sta_n; ++i)
			for (int j = 0; j <= ::k; ++j)
			{
				int v = trans[i][j];
				if (v != -1)
					cur[v] = min(cur[v], res.a[0][i] + cost[j] + (j ? w : 0));
			}

		for (int i = 0; i < sta_n; ++i)
			res.a[0][i] = cur[i];

		l = k;
	}

	transfer(res, n - l);

	cout << res.a[0][pos[start]] << endl;

	return 0;
}
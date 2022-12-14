#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int MaxN = 100;
const int M = 1000000007;

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

int n;
bool mat[MaxN + 1][MaxN + 1];

int a[MaxN + 1][MaxN + 1];

inline int calc_det(int n)
{
	int res = 1;
	for (int i = 1; i <= n; ++i)
	{
		int r = i;
		while (r <= n && !a[r][i])
			++r;

		if (r != i)
		{
			res = (M - res) % M;
			for (int j = i; j <= n; ++j)
				swap(a[r][j], a[i][j]);
		}

		res = (s64)res * a[i][i] % M;

		int inv = (M - modpow(a[i][i], M - 2)) % M;
		for (int j = i + 1; j <= n; ++j)
		{
			int d = (s64)a[j][i] * inv % M;
			for (int k = i; k <= n; ++k)
				a[j][k] = (a[j][k] + (s64)d * a[i][k]) % M;
		}
	}

	return res;
}

int f[MaxN + 1];

int coef[MaxN + 1];
int temp[MaxN + 1];

inline void lagrange()
{
	for (int i = 1; i <= n; ++i)
	{
		temp[0] = 1;
		for (int j = 1; j < n; ++j)
			temp[j] = 0;

		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;

			int d = (i - j + M) % M;
			int a = modpow(d, M - 2);
			int b = (M - (s64)a * j % M) % M;
			// ax + b

			for (int k = n - 1; k >= 0; --k)
			{
				int u = temp[k], v = temp[k - 1];
				temp[k] = 0;
				temp[k] = (temp[k] + (s64)u * b) % M;
				temp[k] = (temp[k] + (s64)v * a) % M;
			}
		}

		for (int j = 0; j < n; ++j)
			coef[j] = (coef[j] + (s64)f[i] * temp[j]) % M;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;

		mat[u][v] = mat[v][u] = true;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int u = 1; u <= n; ++u)
			for (int v = 1; v <= n; ++v)
				a[u][v] = 0;
		for (int u = 1; u <= n; ++u)
			for (int v = u + 1; v <= n; ++v)
			{
				int w = mat[u][v] ? k : 1;
				a[u][v] -= w, a[u][u] += w;
				a[v][u] -= w, a[v][v] += w;
			}
		for (int u = 1; u <= n; ++u)
			for (int v = 1; v <= n; ++v)
				a[u][v] = (a[u][v] + M) % M;

		f[k] = calc_det(n - 1);
	}

	lagrange();

	for (int i = 0; i < n; ++i)
		cout << coef[i] << ' ';
	cout << endl;

	return 0;
}
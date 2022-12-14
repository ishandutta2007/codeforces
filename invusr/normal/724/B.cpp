#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 23;
const int MaxM = 23;

int n, m;
int a[MaxN][MaxM], b[MaxN][MaxM];
int p[MaxN][MaxM];

inline bool is_increasing(int *a)
{
	for (int i = 1; i <= m; ++i)
		if (a[i] != i)
			return false;
	return true;
}

inline bool check(int fc, int sc)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			b[i][j] = a[i][j];
	for (int i = 1; i <= n; ++i)
	{
		swap(b[i][fc], b[i][sc]);
		for (int j = 1; j <= m; ++j)
			p[i][b[i][j]] = j;
	}

	for (int i = 1; i <= n; ++i)
	{
		bool ok = false;
		for (int j = 1; !ok && j <= m; ++j)
		{
			int k = p[i][j];
			swap(b[i][j], b[i][k]);
			if (is_increasing(b[i]))
				ok = true;
			swap(b[i][j], b[i][k]);
		}
		if (!ok)
			return false;
	}
	return true;
}

inline bool solve()
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			if (check(i, j))
				return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	cout << (solve() ? "YES" : "NO");
	cout << "\n";

	return 0;
}
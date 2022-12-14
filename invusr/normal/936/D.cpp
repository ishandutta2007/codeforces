#include <bits/stdc++.h>
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

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}

const int MaxM = 1000000;
const int MaxN = MaxM * 2 + 2;
const int INF = 0x3f3f3f3f;

int n, nL, nR, t, m;
int posL[MaxM + 1], posR[MaxM + 1];
int pos[MaxN + 1];

bool book[MaxN + 1][2];

int f[MaxN + 1][2];
int g[MaxN + 1][2];

inline void transfer(int i, int j, int v, int k)
{
	if (relax(f[i][j], v))
		g[i][j] = k;
}

int main()
{
	cin >> n >> nL >> nR >> t;
	for (int i = 1; i <= nL; ++i)
	{
		posL[i] = getint();
		pos[++m] = posL[i] + 0;
		pos[++m] = posL[i] + 1;
	}
	for (int i = 1; i <= nR; ++i)
	{
		posR[i] = getint();
		pos[++m] = posR[i] + 0;
		pos[++m] = posR[i] + 1;
	}

	sort(pos + 1, pos + m + 1);
	m = unique(pos + 1, pos + m + 1) - pos - 1;

	for (int i = 1; i <= nL; ++i)
		book[lower_bound(pos, pos + m + 1, posL[i]) - pos][0] = true;
	for (int i = 1; i <= nR; ++i)
		book[lower_bound(pos, pos + m + 1, posR[i]) - pos][1] = true;

	f[0][0] = f[0][1] = 0;
	g[0][1] = 1;
	for (int i = 1; i <= m; ++i)
		f[i][0] = f[i][1] = -1;

	for (int i = 0; i < m; ++i)
	{
		for (int k = 0; k < 2; ++k)
			if (~f[i][k] && !book[i][!k])
				transfer(i, !k, min(f[i][k], t), 1);

		for (int k = 0; k < 2; ++k)
		{
			if (!~f[i][k])
				continue;

			int d = pos[i + 1] - pos[i];
			int v = book[i + 1][k] ? t : 0;
			if (f[i][k] + d > v)
				transfer(i + 1, k, f[i][k] + d - v, 0);
		}
	}

	int k = ~f[m][0] ? 0 : 1;
	if (!~f[m][k])
		printf("No\n");
	else
	{
		printf("Yes\n");

		vector<int> vA;
		vector<pair<int, int>> vB;

		int cur = m, last = INF;
		while (cur || k)
		{
			if (g[cur][k])
				vA.push_back(pos[cur]), k = !k;
			else
			{
				if (book[cur][k])
				{
					last -= t;
					last = min(last, pos[cur] - 1);
					vB.emplace_back(last, k + 1);
				}

				--cur;
			}
		}

		reverse(vA.begin(), vA.end());
		reverse(vB.begin(), vB.end());

		printf("%d\n", vA.size());
		for (int i : vA)
			printf("%d ", i);
		printf("\n");

		printf("%d\n", vB.size());
		for (auto [i, j] : vB)
			printf("%d %d\n", i, j);
	}

	return 0;
}
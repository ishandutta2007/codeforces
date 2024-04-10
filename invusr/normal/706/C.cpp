#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int MaxN = 100005;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n;
s64 cost[MaxN];

string str[MaxN][2];

s64 f[MaxN][2];

inline bool is_less(const string &a, const string &b)
{
	int l = min(a.size(), b.size());
	for (int i = 0; i < l; ++i)
		if (a[i] != b[i])
			return a[i] < b[i];
	return a.size() <= b.size();
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> cost[i];
	for (int i = 1; i <= n; ++i)
	{
		cin >> str[i][0];
		str[i][1] = str[i][0];
		reverse(str[i][1].begin(), str[i][1].end());
	}

	f[1][0] = 0, f[1][1] = cost[1];
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
		{
			f[i][j] = INF;
			for (int k = 0; k < 2; ++k)
				if (is_less(str[i - 1][k], str[i][j]))
				{
					int w = j ? cost[i] : 0;
					f[i][j] = min(f[i][j], f[i - 1][k] + w);
				}
		}

	s64 d = min(f[n][0], f[n][1]);
	cout << (d >= INF ? -1 : d);

	return 0;
}
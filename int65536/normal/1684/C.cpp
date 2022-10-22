#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int all_sorted = 1;
	vector<pair<int, int>> ccds;
	for (int i = 0; i < n; i++)
	{
		const auto& b = a[i];
		int sorted = 1;
		int j = 1;
		for (; j < m; j++)
			if (b[j] < b[j - 1])
			{
				sorted = 0;
				break;
			}
		if (sorted) continue;
		all_sorted = 0;
		{
			int last = j;
			for (int k = j; k < m; ++k) {
				if (b[k] < b[j - 1]) {
					last = k;
				}
			}
			ccds.push_back({ j - 1, last });
			if (last + 1 < m)
				ccds.push_back({ j - 1, last + 1 });
		}
		{
			int first = j - 1;
			for (int k = j - 1; k >= 0; --k) {
				if (b[k] > b[j]) {
					first = k;
				}
			}
			ccds.push_back({ first, j });
			if (first - 1 >= 0) {
				ccds.push_back({ first - 1, j });
			}
		}
		break;
	}
	if (all_sorted)
		return { 0, 0 };
	for (auto ccd : ccds) {
		for (int i = 0; i < n; i++)
		{
			swap(a[i][ccd.first], a[i][ccd.second]);
		}
		int all_sorted = 1;
		for (int i = 0; i < n; i++)
		{
			int sorted = 1;
			int j = 1;
			for (; j < m; j++)
				if (a[i][j] < a[i][j - 1])
				{
					sorted = 0;
					break;
				}
			if (!sorted)
				all_sorted = 0;
		}
		if (all_sorted)
			return ccd;
		for (int i = 0; i < n; i++)
		{
			swap(a[i][ccd.first], a[i][ccd.second]);
		}
	}
	return { -1, -1 };
}
int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; case_id++)
	{
		pair<int, int> ret = solve();
		if (ret.first < 0) {
			printf("-1\n");
		}
		else {
			printf("%d %d\n", ret.first + 1, ret.second + 1);
		}
	}
	return 0;
}
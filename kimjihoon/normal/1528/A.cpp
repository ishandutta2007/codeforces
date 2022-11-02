#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int p[100009][2];
long long d[100009][2];
vector<int> v[100009];

void dfs(int n, int pr)
{
	d[n][0] = d[n][1] = 0LL;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == pr) continue;
		dfs(tn, n);
		for (int j = 0; j < 2; j++)
			d[n][j] += max(d[tn][0] + 1LL * abs(p[n][j] - p[tn][0]), d[tn][1] + 1LL * abs(p[n][j] - p[tn][1]));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i][0] >> p[i][1];
			v[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		dfs(1, 0);
		cout << max(d[1][0], d[1][1]) << '\n';
	}
	return 0;
}
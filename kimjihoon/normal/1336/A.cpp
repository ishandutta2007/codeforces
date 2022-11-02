#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<int> v[200009];
pair<int, int> p[200009];

int dfs(int n, int pr, int d)
{
	int s = 0;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == pr) continue;
		s += dfs(tn, n, d + 1);
	}
	p[n] = make_pair(d - s, n);
	return s + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	dfs(1, -1, 0);
	sort(p + 1, p + n + 1); reverse(p + 1, p + n + 1);
	long long ans = 0;
	for (int i = 1; i <= k; i++)
		ans += p[i].first;
	cout << ans << '\n';
	return 0;
}
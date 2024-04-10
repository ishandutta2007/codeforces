#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> a[109][109];
vector<int> ans, v;
bool vs[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[j][i].first;
			a[j][i].second = i + 1;
		}
		for (int j = 0; j < n - 1; j++)
			a[j][i].first -= a[n - 1][i].first;
	}
	for (int i = 0; i < n - 1; i++) {
		sort(a[i], a[i] + m); reverse(a[i], a[i] + m);
		v.clear();
		int c = 0;
		for (int j = 0; j < m; j++) {
			c += a[i][j].first;
			if (c < 0) break;
			v.push_back(a[i][j].second);
		}
		if (ans.size() < v.size()) ans = v;
	}
	for (int i = 0; i < ans.size(); i++)
		vs[ans[i]] = true;
	ans.clear();
	for (int i = 1; i <= m; i++)
		if (!vs[i])
			ans.push_back(i);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}
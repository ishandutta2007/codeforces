#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<int> v[500009], ans;
pair<int, int> p[500009];
int r[500009], vs[500009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		p[i].first = r[i];
		p[i].second = i;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++) {
		int hn = p[i].second, c = 0, mx = 0;
		for (int j = 0; j < v[hn].size(); j++) {
			int tn = v[hn][j];
			if (vs[r[tn]] != i && r[tn] <= p[i].first) {
				vs[r[tn]] = i;
				mx = max(mx, r[tn]);
				c++;
			}
		}
		if (mx == p[i].first || c != p[i].first - 1) {
			cout << -1 << '\n';
			return 0;
		}
		ans.push_back(hn);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}
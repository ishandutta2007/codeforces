#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n[4], r[4][150009];
bool f[4][150009];
vector<int> v[4][150009];
pair<int, int> a[4][150009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++)
		cin >> n[i];
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < n[i]; j++) {
			cin >> a[i][j].first;
			a[i][j].second = j;
		}
	sort(a[0], a[0] + n[0]);
	for (int i = 0; i < n[0]; i++)
		r[0][a[0][i].second] = i;
	for (int i = 0; i < 3; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x, y; cin >> x >> y;
			v[i + 1][y - 1].push_back(x - 1);
		}
	}
	int inf = 500000009;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n[i + 1]; j++) {
			if (v[i + 1][j].size() >= n[i]) {
				a[i + 1][j].first = inf;
				continue;
			}
			for (int k = 0; k < v[i + 1][j].size(); k++) {
				int tn = v[i + 1][j][k];
				tn = r[i][tn];
				f[i][tn] = true;
			}
			for (int k = 0; k < n[i]; k++)
				if (!f[i][k]) {
					a[i + 1][j].first += a[i][k].first;
					break;
				}
			for (int k = 0; k < v[i + 1][j].size(); k++) {
				int tn = v[i + 1][j][k];
				tn = r[i][tn];
				f[i][tn] = false;
			}
		}
		sort(a[i + 1], a[i + 1] + n[i + 1]);
		for (int j = 0; j < n[i + 1]; j++)
			r[i + 1][a[i + 1][j].second] = j;
	}
	int ans = inf;
	for (int i = 0; i < n[3]; i++)
		ans = min(ans, a[3][i].first);
	if (ans == inf) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}
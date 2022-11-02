#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int> > > v;
bool vs[109][109];
int ans[109][109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		v.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int a; cin >> a;
				v.push_back(make_pair(a, make_pair(i, j)));
				vs[i][j] = false;
			}
		sort(v.begin(), v.end());
		for (int i = 0; i < m; i++) {
			int a = v[i].first, pi = v[i].second.first;
			ans[pi][i] = a;
			vs[pi][i] = true;
		}
		for (int i = m; i < v.size(); i++) {
			int a = v[i].first, pi = v[i].second.first;
			for (int j = 0; j < m; j++)
				if (!vs[pi][j]) {
					ans[pi][j] = a;
					vs[pi][j] = true;
					break;
				}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[i][j] << " ";
			cout << '\n';
		}
	}
	return 0;
}
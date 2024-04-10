#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[2];
int a[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		v[0].clear(); v[1].clear();
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			int b; cin >> b;
			ans += b;
			v[a[i]].push_back(b);
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		if (v[0].size() == v[1].size()) cout << ans * 2 - 1LL * min(v[0][0], v[1][0]) << '\n';
		else {
			reverse(v[0].begin(), v[0].end());
			reverse(v[1].begin(), v[1].end());
			int t = min(v[0].size(), v[1].size());
			for (int i = 0; i < t; i++)
				ans += v[0][i] + v[1][i];
			cout << ans << '\n';
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100009], b[100009], c[100009], ans[100009];
vector<int> v[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < m; i++) {
			cin >> c[i];
			ans[i] = 0;
		}
		for (int i = 1; i <= n; i++) 
			v[i].clear();
		for (int i = 0; i < n; i++)
			if (a[i] == b[i]) 
				v[b[i]].push_back(i + 1);
		for (int i = 0; i < n; i++)
			if (a[i] != b[i]) 
				v[b[i]].push_back(i + 1);
		int pi = -1;
		for (int i = 0; i < n; i++)
			if (b[i] == c[m - 1]) {
				pi = i;
				break;
			}
		if (pi == -1) {
			cout << "NO" << '\n';
			continue;
		}
		for (int i = 0; i < m; i++) {
			if (v[c[i]].empty()) 
				ans[i] = -1;
			else {
				ans[i] = v[c[i]].back();
				a[ans[i] - 1] = c[i];
				if (v[c[i]].size() > 1)
					v[c[i]].pop_back();
			}
		}
		bool f = true;
		for (int i = 0; i < n; i++)
			if (a[i] != b[i]) {
				f = false;
				break;
			}
		if (!f) cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			for (int i = 0; i < m; i++) {
				if (ans[i] == -1) cout << ans[m - 1] << " ";
				else cout << ans[i] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}
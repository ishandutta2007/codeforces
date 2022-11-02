#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200009];
int ans = 0;

bool dfs(int n, int p, bool tf)
{
	bool f = false;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		if (v[n].size() <= 2) f = (f | dfs(tn, n, tf));
		else f = (f | dfs(tn, n, false));
	}
	if (v[n].size() > 2 && (f || tf)) ans--;
	if (v[n].size() == 1 || (f && v[n].size() == 2)) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		int rt = 1, mx = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, (int)v[i].size());
			if (v[i].size() == 1) {
				ans++;
				rt = i;
			}
		}
		if (mx <= 2) {
			cout << 1 << '\n';
			continue;
		}
		dfs(rt, 0, true);
		cout << ans << '\n';
	}
	return 0;
}
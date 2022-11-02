#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[100009], ans;
int k;

void dfs(int n, int t)
{
	if (t) k = max(k, n);
	int pn = -1;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (v[tn].empty()) {
			ans.push_back(tn);
			dfs(tn, 1 - t);
		}
		else pn = tn;
	}
	if (pn != -1) {
		ans.push_back(pn);
		dfs(pn, 1 - t);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i <= n + 1; i++)
			v[i].clear();
		ans.clear(); k = 0;
		for (int i = 1; i <= n; i++) {
			int p; cin >> p;
			v[p].push_back(i);
		}
		if (!v[0].empty()) dfs(0, 1);
		else dfs(n + 1, 0);
		cout << k << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}
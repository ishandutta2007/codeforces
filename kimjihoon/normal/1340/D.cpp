#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<int> v[100009];
vector<pair<int, int> > ans;
int k = 0;

void dfs(int n, int p, int t)
{
	ans.push_back(make_pair(n, t));
	int rt = t;
	int c = 0, sz = v[n].size();
	if (n != 1) sz--;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		if (rt == k) {
			rt = t - (sz - c) - 1;
			ans.push_back(make_pair(n, rt));
		}
		dfs(tn, n, rt + 1);
		rt++;
		ans.push_back(make_pair(n, rt));
		c++;
	}
	if (n != 1 && rt != t - 1)
		ans.push_back(make_pair(n, t - 1));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		k = max(k, (int)v[i].size());
	dfs(1, -1, 0);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
	return 0;
}
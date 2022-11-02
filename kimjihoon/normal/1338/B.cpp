#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[100009];
int c = 0, ec = 0, ans;

void dfs(int n, int p, int d)
{
	if (v[n].size() == 1) {
		c++;
		if (d % 2 == 0) ec++;
		return;
	}
	bool f = false;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		dfs(tn, n, d + 1);
		if (v[tn].size() == 1) {
			if (f) ans--;
			f = true;
		}
	}
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
	int rt = 1;
	for (int i = 1; i <= n; i++)
		if (v[i].size() != 1) {
			rt = i;
			break;
		}
	ans = n - 1;
	dfs(rt, -1, 0);
	if (c == ec || ec == 0) cout << 1 << " ";
	else cout << 3 << " ";
	cout << ans << '\n';
	return 0;
}
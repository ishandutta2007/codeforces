#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

vector< vector<int> > g;
vector<int> val;

const int INF = 1000 * 1000 * 1000 + 11;
map<int, bool> can;

void dfs(int v, int mn, int mx) {
	if (v == -2)
		return;
	if (!(mn <= val[v] || mx >= val[v]))
		can[val[v]] = 1;
	dfs(g[v][0], min(mn, val[v]), mx); dfs(g[v][1], mn, max(mx, val[v]));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	val.resize(n);
	g.resize(n);
	vector<bool> to(n);
	for (int i = 0; i < n; i++) {
		int v, l, r;
		cin >> v >> l >> r;
		l--; r--;
		val[i] = v;
		g[i] = { l, r };
		if (l != -2)
			to[l] = 1;
		if (r != -2)
			to[r] = 1;
	}
	int st = -1;
	for (int i = 0; i < n; i++)
		if (!to[i])
			st = i;
	dfs(st, INF, -11);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!can[val[i]])
			ans++;
	cout << ans;
	return 0;
}
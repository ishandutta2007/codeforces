#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

struct point {
	int x, y;
};

int binpow(int x, int p) {
	if (p == 0) return 1;
	if (p & 1) return binpow(x, p - 1) * x % mod;
	return binpow(x * x % mod, p >> 1);
}

int n;
vector<point> pt;
vector< pair<int, int> > vertical[maxn];
vector< pair<int, int> > horizontal[maxn];
vector<int> graph[maxn];
char used[maxn];
set<int> different_x, different_y;
int component_size, sum_of_degree;

void dfs(int v) {
	used[v] = true;
	++component_size;
	sum_of_degree += graph[v].size();
	different_x.insert(pt[v].x);
	different_y.insert(pt[v].y);
	for (auto to: graph[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	pt.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> pt[i].x >> pt[i].y;
	}
	vector<int> x, y;
	for (int i = 0; i < n; ++i) {
		x.push_back(pt[i].x);
		y.push_back(pt[i].y);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < n; ++i) {
		pt[i].x = lower_bound(x.begin(), x.end(), pt[i].x) - x.begin();
		pt[i].y = lower_bound(y.begin(), y.end(), pt[i].y) - y.begin();
	}
	for (int i = 0; i < n; ++i) {
		vertical[pt[i].x].emplace_back(pt[i].y, i);
		horizontal[pt[i].y].emplace_back(pt[i].x, i);
	}
	for (int x = 0; x < n; ++x) {
		sort(vertical[x].begin(), vertical[x].end());
		for (int i = 1; i < vertical[x].size(); ++i) {
			int a = vertical[x][i].second;
			int b = vertical[x][i - 1].second;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	for (int y = 0; y < n; ++y) {
		sort(horizontal[y].begin(), horizontal[y].end());
		for (int i = 1; i < horizontal[y].size(); ++i) {
			int a = horizontal[y][i].second;
			int b = horizontal[y][i - 1].second;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
			int k = binpow(2, different_x.size() + different_y.size());
			if (sum_of_degree / 2 == component_size - 1) --k;
			ans = ans * k % mod;
			different_x.clear();
			different_y.clear();
			sum_of_degree = 0;
			component_size = 0;
		}
	}
	cout << ans << '\n';
}
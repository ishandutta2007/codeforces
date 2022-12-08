#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
double eps = 1e-12;

vector<vector<int>> edge;
vector<vector<int>> n_ed;
vector<char> q;
vector<int> cols;
vector<char> used;
vector<pair<int, int>> as;
set<pair<int, int>> bad;
vector<char> good_boi;
int color = 0;

int dfs(int v) {
	used[v] = true;
	cols[v] = color;
	int ans = q[v];
	for (int u : edge[v]) {
		if (used[u]) continue;
		as.push_back({ v + 1, u + 1});
		n_ed[v].push_back(u);
		n_ed[u].push_back(v);
		ans += dfs(u);
	}
	return ans;
}

void dfs2(int v, int p) {
	for (int u : n_ed[v]) {
		if (u == p || u == 0) continue;
		if (good_boi[u]) {
			bad.insert({ u + 1, v + 1 });
			bad.insert({ v + 1, u + 1 });
			continue;
		}
		dfs2(u, v);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m, d;
	int t1, t2;
	cin >> n >> m >> d;
	edge.resize(n);
	q.resize(n);
	n_ed.resize(n);
	cols.resize(n);
	used.resize(n);
	int c = 0;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		if (!t1 || !t2) c++;
		if (t1 == 0) q[t2] = true;
		else if (t2 == 0) q[t1] = true;
		else {
			edge[t1].push_back(t2);
			edge[t2].push_back(t1);
		}
	}
	if (c < d) {
		cout << "NO\n";
		return 0;
	}
	vector<int> cnt;
	used[0] = 1;
	good_boi.resize(n);
	for (int i = 1; i < n; i++) {
		if (q[i] && !used[i]) {
			good_boi[i] = true;
			as.push_back({ 1, i + 1 });
			cnt.push_back(dfs(i));
			//cout << cnt[color] << endl;
			color++;
		}
	}
	if (color > d) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		int last = d - color;
		for (int i = 0; i < n; i++) {
			if (last == 0) break;
			if (q[i] && !good_boi[i] && cnt[cols[i]] > 1) {
				dfs2(i, 0);
				cnt[cols[i]]--;
				last--;
				good_boi[i] = true;
				as.push_back({ 1, i + 1 });
			}
		}
		for (auto ed : as) {
			if (bad.find(ed) != bad.end()) continue;
			cout << ed.first << " " << ed.second << endl;
		}
	}
	//system("pause");
	return 0;
}
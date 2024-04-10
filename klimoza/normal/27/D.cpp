#pragma optimise("O3");
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;

bool intersect(pair<int, int> l, pair<int, int> r) {
	if (l.first >= r.first) swap(l, r);
	if (l.first == r.first || l.second == r.second) {
		return false;
	}
	if (l.second >= r.second || l.second <= r.first) return false;
	return true;
}

vector<vector<int>> edge;

vector<int> dfs(int v, vector<int> used, int c) {
	used[v] = c;
	//cout << v << " " << c << endl;
	for (int u : edge[v]) {
		if (!used[u]) {
			used = dfs(u, used, -c);
			if (used[0] == -2) return used;
		}
		else {
			if (used[u] == used[v]) {
				used[0] = -2;
				return used;
			}
		}
	}
	//cout << v << " " << c << "fin\n";
	return used;
}

int main() {
	int n, m;
	cin >> n >> m;
	int t1, t2;
	vector<pair<int, int>> b(m);
	edge.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		if (t2 < t1) swap(t1, t2);
		b[i] = { t1, t2 };
	}
	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (intersect(b[i], b[j])) {
				edge[i].push_back(j);
				edge[j].push_back(i);
				//cout << i << " " << j << endl;
			}
		}
	}
	for (int v = 0; v < m; v++) {
		if (!ans[v]) {
			vector<int> g = dfs(v, ans, 1);
			//if (g[0] == -2) g = dfs(v, ans, -1);
			if (g[0] == -2) {
				cout << "Impossible\n";
				//system("pause");
				return 0;
			}
			ans = g;
		}
	}
	for (int i : ans) {
		if (i == 1) cout << "i";
		else cout << "o";
	}
	//system("pause");
	return 0;
}
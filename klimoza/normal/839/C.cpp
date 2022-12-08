#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 998244353;

vector<vector<int>> g;
vector<int> leaf;
vector<int> d;
double ans = 0;

void dfs(int v, double x, int last = -1) {
	int t = 0;
	for (int u : g[v]) {
		if (u != last) {
			d[u] = d[v] + 1;
			dfs(u, x / (g[v].size() - (last != -1)), v);
			t++;
		}
	}
	if (!t) ans += x * d[v];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);

	int n;
	cin >> n;
	g.resize(n);
	d.resize(n);
	for (int i = 1; i < n; i++) {
		int t1, t2; cin >> t1 >> t2; t1--; t2--;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(0, 1);
	cout << ans << endl;
	//system("pause");
	return 0;
}
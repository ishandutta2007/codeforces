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
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

vector<vector<int>> g;
vector<ll> sz;
vector<ll> ans;

ll an = 0;

int n;

void cnt(int v, int last = -1) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == last) continue;
		cnt(u, v);
		ans[v] += ans[u];
		sz[v] += sz[u];
	}
	ans[v] += sz[v];
	//cout << v + 1 << " " << ans[v] << " " << sz[v] << endl;
}

void get_ans(int v, ll rofl = 0, int last = -1) {
	//cout << v + 1 << " " << rofl << endl;
	an = max(an, rofl + ans[v]);
	for (int u : g[v]) {
		if (u == last) continue;
		get_ans(u, (rofl) + (ans[v] - ans[u] - sz[v]) + (sz[v] - sz[u]) + (n - sz[u]), v);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	cin >> n;
	g.resize(n);
	sz.resize(n);
	ans.resize(n);
	int t1, t2;
	for (int i = 1; i < n; i++) {
		cin >> t1 >> t2; t1--; t2--;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	cnt(0);
	get_ans(0);
	cout << an << endl;
	//system("pause");
	return 0;
}
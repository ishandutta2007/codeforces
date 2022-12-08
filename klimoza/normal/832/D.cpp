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
ll mod = 1e9 + 7;

const int l = 20;

vector<int> tin;
vector<int> tout;
vector<vector<int>> up;
vector<int> d;
vector<vector<int>> g;
int timr = 0;

void dfs(int v, int last = 0) {
	//cout << v << endl;
	tin[v] = timr++;
	up[v][0] = last;
	for (int i = 1; i < l; i++) up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u : g[v]) {
		if (u == last) continue;
		d[u] = d[v] + 1;
		dfs(u, v);
	}
	tout[v] = timr++;
}

int upper(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lca(int a, int b) {
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;
	for (int i = l - 1; i >= 0; i--) {
		if (!upper(up[a][i], b)) a = up[a][i];
	}
	return up[a][0];
}


void check(int a, int b, int c, int t1, int t2, int t3, int &maxi) {
	//cout << d[t3] << " " << d[t1] << " " << d[a] << endl;
	if (upper(a, b) && upper(a, c)) maxi = max(maxi, d[t3] - d[a] + 1);
	else if (upper(b, a) && upper(c, a))  maxi = max(maxi, d[a] - max(d[b], d[c]) + 1);
	else if (upper(a, b) && upper(c, a)) {}
	else if (upper(b, a) && upper(a, c)) {}
	else if (upper(a, b)) {}
	else if (upper(a, c)) {}
	else if (upper(b, a)) maxi = max(maxi, d[a] - max(d[b], d[t2]) + 1);
	else if (upper(c, a)) maxi = max(maxi, d[a] - max(d[c], d[t1]) + 1);
	else if (t1 == t2) maxi = max(maxi, d[t3] - d[t1] + d[a] - d[t1] + 1);
	else maxi = max(maxi, d[a] - max(d[t1], d[t2]) + 1);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, q, a, b, c, t; cin >> n >> q;
	tin.resize(n); tout.resize(n); up.assign(n, vector<int>(l)); d.resize(n); g.resize(n);
	for (int i = 1; i < n; i++) {
		cin >> t; t--;
		g[i].push_back(t); g[t].push_back(i);
	}
	dfs(0);
	//cout << d[0] << " " << d[1] << " " << d[2] << endl;
	while (q--) {
		cin >> a >> b >> c; a--; b--; c--;
		int maxi = 1;
		int t1 = lca(a, b);
		int t2 = lca(a, c);
		int t3 = lca(b, c);
		check(a, b, c, t1, t2, t3, maxi);
		check(b, a, c, t1, t3, t2, maxi);
		check(c, a, b, t2, t3, t1, maxi);
		cout << maxi << endl;
	}
	//system("pause");
	return 0;
}
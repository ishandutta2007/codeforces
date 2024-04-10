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

vector<vector<int>> g;
vector<int> sz;
vector<int> d;
vector<int> p;
vector<int> par;
vector<bool> prv;

void dfs(int v, int last = -1) {
	sz[v] = 1;
	if (g[v].size() == 1) {
		p[v] = v;
	}
	int maxi = -1;
	for (int u : g[v]) {
		if (u == last) continue;
		d[u] = d[v] + 1;
		dfs(u, v);
		sz[v] += sz[u];
		if (sz[u] > maxi) {
			p[v] = p[u];
			maxi = sz[u];
		}
	}
}

bool cmp(int a, int b) {
	return sz[a] < sz[b];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	g.resize(n);
	sz.resize(n);
	d.resize(n);
	p.resize(n);
	par.resize(n);
	prv.resize(n);
	int t1, t2;
	for (int i = 1; i < n; i++) {
		cin >> t1 >> t2; t1--; t2--;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(0);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end(), cmp);
		if (i != 0) {
			par[i] = g[i].back();
			g[i].pop_back();
		}
	}
	cout << "d " << 1 << endl;
	int ln = -1;
	cin >> ln;
	if (ln == 0) {
		cout << "! " << 1 << endl;
		return 0;
	}
	while (true) {
		if (ln == 0) {
			cout << "! " << cur + 1 << endl;
			break;
		}
		int t = g[cur].size();
		if (t == 1) {
			cur = g[cur][0];
			ln--;
			continue;
		}
		if (sz[g[cur][t - 1]] < sz[cur] / 2) {
			cout << "s " << cur + 1 << endl;
			int v;
			cin >> v;
			assert(v != -1);
			v--;
			cur = v;
			ln--;
			continue;
		} else{
			if (prv[g[cur][t - 1]]) {
				g[cur].pop_back();
				continue;
			}
			//cout << "flex " << g[cur][t - 1] << " " << p[g[cur][t - 1]] << endl;
			cout << "d " << p[g[cur][t - 1]] + 1 << endl;
			int h;
			cin >> h;
			assert(h != -1);
			int y = (ln + h - d[p[g[cur][t - 1]]] + d[cur]) / 2;
			int x = h - y;
			//cout << x << " " << y << endl;
			if (x == d[cur] - d[p[g[cur][t - 1]]]) {
				g[cur].pop_back();
				continue;
			}
			else {
				int u = p[g[cur][t - 1]];
				while (x) {
					prv[u] = true;
					u = par[u];
					x--;
				}
				cur = u;
				ln = y;
				continue;
			}
		}
	}
	//system("pause");
	return 0;
}
/*
15
1 14
1 15
14 10
14 11
10 2
10 3
11 4
11 5
15 12
15 13
12 6
12 7
13 8
13 9
*/
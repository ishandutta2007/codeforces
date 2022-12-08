#define _CRT_SECURE_NO_WARNINGS
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

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

#define int long long

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());

struct Edge {
	int v, u, w;
	Edge() {}
	Edge(int _v, int _u, int _w) : v(_v), u(_u), w(_w) {}
};

const int N = 807;

vector<pair<int, int>> g[N];
int nums[200000 + 7];
int d[N][N];

void Djikstra(int x) {
	set<pair<int, int>> e;
	for (int i = 0; i < N; i++) {
		d[x][i] = inf;
		if(i != x)
		e.insert({ inf, i });
	}
	d[x][x] = 0;
	e.insert({ 0, x });
	for (int i = 0; i < N; i++) {
		auto v = *e.begin();
		e.erase(e.begin());
		if (v.first == inf) break;
		for (auto u : g[v.second]) {
			if (d[x][u.first] == inf || d[x][u.first] > d[x][v.second] + u.second) {
				e.erase({ d[x][u.first], u.first });
				d[x][u.first] = d[x][v.second] + u.second;
				e.insert({ d[x][u.first], u.first });
			}
		}
	}
}

signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int n, m, k;
	cin >> n >> m >> k;
	vector<Edge> ed(m);
	for (auto& u : ed) {
		cin >> u.v >> u.u >> u.w;
		u.v--; u.u--;
	}
	sort(all(ed), [](Edge a, Edge b) {return a.w < b.w; });
	vector<int> ver;
	for (int i = 0; i < min(m, k); i++) {
		ver.push_back(ed[i].v); ver.push_back(ed[i].u);
	}
	sort(all(ver));
	ver.erase(unique(all(ver)), ver.end());
	for (int i = 0; i < size(ver); i++) {
		nums[ver[i]] = i;
	}
	for (int i = 0; i < min(m, k); i++) {
		int v = nums[ed[i].v];
		int u = nums[ed[i].u];
		g[v].push_back({ u, ed[i].w });
		g[u].push_back({ v, ed[i].w });
	}
	for (int i = 0; i < size(ver); i++) Djikstra(i);
	vector<int> ans;
	for (int i = 0; i < size(ver); i++) {
		for (int j = i + 1; j < size(ver); j++) {
			ans.push_back(d[i][j]);
		}
	}
	sort(all(ans));
	cout << ans[k - 1] << endl;
	return 0;
}
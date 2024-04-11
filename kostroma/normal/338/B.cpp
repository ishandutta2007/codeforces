#pragma comment (linker, "/STACK:128000000")
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
    while (t--) {
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n, m, d;

vector<int> g[100500];
int p[100500];

bool bad[100500];

int mx[100500];
int mx1[100500];

int level[100500];

int timer = 1;
int tin[100500], tout[100500];

void dfs (int v, int p = -1) {
	tin[v] = timer++;
	level[v] = ((p == -1) ? 0 : (level[p] + 1));
	if (bad[v]) {
		if (mx[v] == -1)
			mx[v] = v;
		else
			if (mx1[v] == -1)
				mx1[v] = v;
	}

	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)
			continue;
		dfs(to, v);
		if (mx[v] == -1 || level[mx[to]] > level[mx[v]]) {
			mx1[v] = mx[v];
			mx[v] = mx[to];
		}
		else
			if (mx1[v] == -1 || level[mx[to]] > level[mx1[v]]) {
				mx1[v] = mx[to];
			}
	}
	tout[v] = timer++;
}

bool upper (int v, int u) {
	return u >= 0 && v >= 0 && tin[v] <= tin[u] && tout[u] <= tout[v];
}

int ans = 0;

void dfs1 (int v, int p, int farDist) {
	if (farDist > d)
		return;
	if (farDist <= d && level[mx[v]] - level[v] <= d) {
		++ans;
	}
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)
			continue;
		int faar = mx[v];
		if (upper(to, faar))
			faar = mx1[v];
		if (faar == -1)
			dfs1(to, v, farDist + 1);
		else
			dfs1(to, v, max(farDist + 1, level[faar] - level[v] + 1));
	}
}

void solve() {
	cin >> n >> m >> d;
	for (int i = 0; i < m; ++i)
		cin >> p[i], --p[i], bad[p[i]] = true;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	memset(mx, -1, sizeof mx);
	memset(mx1, -1, sizeof mx1);

	dfs(0);


	dfs1(0, -1, -1000000000);

	cout << ans;
}
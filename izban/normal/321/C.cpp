#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, cnt[maxn], h[maxn];
char c[maxn];
vector<int> e[maxn], gr[maxn];


bool cmp(int a, int b) {
	return cnt[a] > cnt[b];
}

void dfs1(int v, int p = -1) {
	cnt[v] = 1;
	h[v] = 1;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs1(e[v][i], v);
		cnt[v] += cnt[e[v][i]];
		h[v] = max(h[v], h[e[v][i]] + 1);
	}
	//vector<int> ee;
	//for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) ee.push_back(e[v][i]);
	//e[v] = ee;
	//sort(e[v].begin(), e[v].end(), cmp);
}

int g(int x) {
	int res = 0;
	while (x % 2 == 0) {
		x /= 2;
		res++;
	}
	return res;
}

void dfs2(int v, char C) {
	while (1) {
		sort(e[v].begin(), e[v].end(), cmp);
		if (cnt[v] == 1 || cnt[e[v][0]] * 2 <= cnt[v]) break;
		cnt[v] -= cnt[e[v][0]];
		cnt[e[v][0]] += cnt[v];
		v = e[v][0];
	}
	c[v] = C;
	cnt[v] = 0;
	for (int i = 0; i < e[v].size(); i++) if (cnt[e[v][i]]) dfs2(e[v][i], C + 1);
}

void gen() {
	memset(h, 0, sizeof(h));
	memset(c, 0, sizeof(c));
	memset(cnt, 0, sizeof(cnt));
	n = 1000; //n = rand() % 900 + 1;
	for (int i = 1; i <= n; i++) e[i].clear();
	vector<int> p;
	for (int i = 1; i <= n; i++) p.push_back(i);
	random_shuffle(p.begin(), p.end());
	for (int i = 1; i < p.size(); i++) {
		int v = p[rand() % i], u = p[i];
		e[u].push_back(v);
		e[v].push_back(u);
	}
}

bool check(int v, char C, char mn, int p = -1) {
	bool res = 1;
	mn = min(mn, c[v]);
	if (c[v] == C && p != -1 && mn >= C) return 0;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) res &= check(e[v][i], C, mn, v);
	return res;
}

void solve() {
	dfs1(1);
	dfs2(1, 'A');
}

void stress(bool f) {
	if (!f) return;
	srand(13);
	for (int it = 0; it < 10000; it++) {
		gen();
		solve();
		bool res = 1; char mx = 0; int o = 1;
		for (int i = 1; i <= n; i++) {
			res &= check(i, c[i], c[i]) && c[i] >= 'A' && c[i] <= 'Z';
			mx = max(mx, c[i]);
			if (c[i] > c[o]) o = i;
		}
		if (!res) {
			cout << it << " " << o << " " << c[o] <<  endl;
			cout << n << endl;
			for (int i = 1; i <= n; i++) for (int j = 0; j < e[i].size(); j++) if (i < e[i][j]) cout << i << " " << e[i][j] << endl;
			break;
		}
		cerr << it << " " << (char)mx << endl;
	}
	exit(0);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    stress(0);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	solve();
	for (int i = 1; i <= n; i++) cout << (char)c[i] << " ";
	
	return 0;
}
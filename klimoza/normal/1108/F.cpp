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

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9 + 7;

struct Edge {
	int v, u;
	ll w;
	Edge(){}
};

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

const int N = 2e5 + 7;

int p[N], sz[N];

void make_dsu(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int get_par(int k) {
	if (p[k] == k) return k;
	return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;	
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<Edge> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].v >> a[i].u >> a[i].w;
		a[i].v--; a[i].u--;
	}
	make_dsu(n);
	sort(a.begin(), a.end(), cmp);
	vector<bool> can(m);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (i == 0 || a[i].w != a[i - 1].w) {
			for (int j = i; j < m && a[j].w == a[i].w; j++) {
				if (get_par(a[j].v) != get_par(a[j].u)) can[j] = true;
			}
		}
		if (get_par(a[i].v) != get_par(a[i].u)) merge(a[i].v, a[i].u);
		else if (can[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}
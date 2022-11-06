#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define fs first
#define sn second

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

const int N = 2500;

int a[N][N];

void fail() {
	printf("NOT MAGIC\n");
	exit(0);
}

vector<int> parent, edges, size;

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
int union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		parent[b] = a;
		edges[a] += edges[b];
		size[a] += size[b];
	}
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	forn(i, 0, n) forn(j, 0, n) scanf("%d", &a[i][j]);
	forn(i, 0, n) if (a[i][i] != 0) fail();
	forn(i, 0, n) forn(j, 0, n) if (a[i][j] != a[j][i]) fail();
	vector<pair<int, pair<int, int>>> v;
	forn(i, 0, n) forn(j, 0, i) v.push_back({a[i][j], {i, j}});
	sort(v.begin(), v.end());
	parent.resize(n);
	edges.resize(n);
	size.resize(n);
	forn(i, 0, n) {
		parent[i] = i;
		edges[i] = 0;
		size[i] = 1;
	}
	set<int> upd;
	forn(i, 0, n * (n - 1) / 2) {
		int l = find_set(v[i].sn.fs), r = find_set(v[i].sn.sn);
		if (l == r) {
			++edges[l];
		} else {
			l = union_sets(l, r);
			++edges[l];
		}
		upd.insert(l);
		if (i == n * (n - 1) / 2 || v[i].fs != v[i + 1].fs) {
			for (int j : upd) {
				if (parent[j] != j) continue;
				int sz = size[j];
				if (edges[j] != sz * (sz - 1) / 2) fail();
			}
			upd.clear();
		}
	}
	cout << "MAGIC\n";
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
vector<int> e[200005]; // samo tree edge
int u[400005], v[400005], w[400005];
int l[200005], r[200005], t;
long long d0[200005], tmh[200005];

void dfs(int x, long long d) {
	l[x] = ++t;
	d0[x] = d;
	for (int eid : e[x]) {
		dfs(v[eid], d+w[eid]);
	}
	r[x] = t;
}

const int MAXN = 262144;

struct tree {

	long long mn[2*MAXN], lazy[2*MAXN];

	void init() {
		for (int i=MAXN-1; i>=1; i--) {
			mn[i] = min(mn[2*i], mn[2*i+1]);
		}
	}

	void push(int x) {
		if (x < MAXN) {
			lazy[2*x] += lazy[x];
			lazy[2*x+1] += lazy[x];
		}
		mn[x] += lazy[x];
		lazy[x] = 0;
	}

	void add(int l, int r, long long val, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			lazy[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		add(l, r, val, 2*node, nl, nm);
		add(l, r, val, 2*node+1, nm+1, nr);

		mn[node] = min(mn[2*node], mn[2*node+1]);
	}

	long long get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (r < nl || nr < l) {
			return 1e18;
		}
		if (l <= nl && nr <= r) {
			return mn[node];
		}

		int nm = (nl + nr) >> 1;
		return min(
			get(l, r, 2*node, nl, nm),
			get(l, r, 2*node+1, nm+1, nr)
		);
	}
};

tree drvo_dubina, drvo_takemehome;

void update_w(int eid, int nuw) {
	int delta = nuw - w[eid];
	w[eid] += delta;
	if (eid < n) {
		// tree edge, apdejtuju se oba drva
		drvo_dubina.add(l[v[eid]], r[v[eid]], delta);
		drvo_takemehome.add(l[v[eid]], r[v[eid]], delta);
	} else {
		// back edge, apdejtuju samo tmh
		drvo_takemehome.add(l[u[eid]], l[u[eid]], delta);
	}
}

long long find_len(int a, int b) {
	// ako je a iznad b:
	if (l[a] <= l[b] && r[b] <= r[a]) {
		// samo se spusti do b
		return drvo_dubina.get(l[b], l[b]) - drvo_dubina.get(l[a], l[a]);
	} else {
		// prvo dodji do korena
		return drvo_takemehome.get(l[a], r[a]) - drvo_dubina.get(l[a], l[a])
			+ find_len(1, b);	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;

	cin >> n >> q;

	for (int i=1; i<=2*n-2; i++) {
		cin >> u[i] >> v[i] >> w[i];
		if (i < n) {
			e[u[i]].push_back(i);
		} else {
			tmh[u[i]] = w[i];
		}
	}

	dfs(1, 0);

	for (int i=1; i<=n; i++) {
		drvo_dubina.add(l[i], l[i], d0[i]);
	}

	for (int i=1; i<=n; i++) {
		drvo_takemehome.add(l[i], l[i], d0[i] + tmh[i]);
	}

	// d0 i tmh prestaju da vaze odavde
	// w i dalje vazi

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			update_w(x, y);
		} else {
			cout << find_len(x, y) << '\n';
		}
	}
}
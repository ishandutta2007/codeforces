#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v;
};

map<int, basic_string<edge>> e;

typedef pair<int*, int> par;

int p[200005], sz[200005];
basic_string<par> st;

void add_sentinel() {
	st += par{nullptr, 0};
}

void rollback() {
	while (st.size() && st.back().first) {
		*st.back().first = st.back().second;
		st.pop_back();
	}

	st.pop_back();
}

int endp(int x) {
	while (x != p[x])
		x = p[x];
	return x;
}

bool merge(int x, int y, bool record = false) {
	x = endp(x);
	y = endp(y);
	if (x == y)
		return false;
	if (sz[x] < sz[y])
		swap(x, y);
	if (record) {
		st += par{p+y, p[y]};
		st += par{sz+x, sz[x]};
	}
	p[y] = x;
	sz[x] += sz[y];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	fill(sz+1, sz+n+1, 1);
	iota(p+1, p+n+1, 1);

	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[w] += {u, v};
	}
	
	int unused = 0;

	for (auto p : e) {

		int br_korisnih_grana = 0;

		for (auto ee : p.second) {
			add_sentinel();
			auto r = merge(ee.u, ee.v, true);
			if (r) {
				br_korisnih_grana++;
			}
			rollback();
		}

		int br_spajanja = 0;

		for (auto ee : p.second) {
			auto r = merge(ee.u, ee.v, true);
			if (r) {
				br_spajanja++;
			}
		}

		unused += br_korisnih_grana - br_spajanja;
	}

	cout << unused << '\n';

}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll a[200005];

int p[200005];
ll lo[200005];

int ep(int x) {
	if (x == p[x])
		return x;
	return p[x] = ep(p[x]);
}

struct offer {
	int u, v;
	ll w;
	bool operator< (const offer& b) const {
		return w < b.w;
	}
};

offer b[200005];

set<pair<ll, int>> pq;
ll sol = 0;

// pri cemu znam da su spojivi
void mergee(int x, int y, bool use_a) {
	x = ep(x);
	y = ep(y);
	pq.erase({lo[x], x});
	pq.erase({lo[y], y});
	p[x] = y;
	if (use_a) sol += lo[x] + lo[y];
	lo[y] = min(lo[y], lo[x]);
	pq.insert({lo[y], y});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	copy(a+1, a+n+1, lo+1);
	iota(p+1, p+n+1, 1);
	for (int i=0; i<m; i++)
		cin >> b[i].u >> b[i].v >> b[i].w;
	sort(b, b+m);
	for (int i=1; i<=n; i++)
		pq.insert({a[i], i});
	for (int i=0; i<m; i++) {
		while (pq.size() >= 2) {
			auto it1 = pq.begin();
			auto it2 = next(it1);
			if (it1->first + it2->first <= b[i].w) {
				mergee(it1->second, it2->second, true);
			} else {
				break;
			}
		}
		int x = ep(b[i].u);
		int y = ep(b[i].v);
		if (x != y) {
			mergee(x, y, false);
			sol += b[i].w;
		}
	}

	while (pq.size() >= 2) {
		auto it1 = pq.begin();
		auto it2 = next(it1);
		mergee(it1->second, it2->second, true);
	}

	cout << sol << '\n';
}
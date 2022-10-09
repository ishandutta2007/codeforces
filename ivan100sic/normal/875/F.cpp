#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
struct dama {
	int a, b, w;
	bool operator< (const dama& o) const {
		return w > o.w;
	}
} a[200005];

// 0 = zauzet (upetljan), x>0 = ima alt path do x
int p[200005];
bool open[200005];

int e(int x) {
	if (p[x] == x)
		return x;
	return p[x] = e(p[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> a[i].a >> a[i].b >> a[i].w;
	sort(a, a+m);
	iota(p+1, p+n+1, 1);
	fill(open+1, open+n+1, true);
	int sol = 0;
	for (int i=0; i<m; i++) {
		auto [u, v, w] = a[i];
		int uu = e(u);
		int vv = e(v);
		if (open[uu]) {
			open[uu] = 0;
			// cerr << "set " << uu << " --> " << v << '\n';
			if (open[vv])
				p[uu] = vv;
			sol += w;
		} else if (open[vv]) {
			open[vv] = 0;
			if (open[uu])
				p[vv] = uu;
			sol += w;
		}
	}
	cout << sol << '\n';
}
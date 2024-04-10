#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	ll sol, ls, rs, zbir;
};

node napravi(ll x) {
	return {x, x, x, x};
}

node spoji(node x, node y) {
	node t;
	t.sol = max({x.sol, y.sol, x.rs + y.ls});
	t.ls = max(x.ls, x.zbir + y.ls);
	t.rs = max(y.rs, y.zbir + x.rs);
	t.zbir = x.zbir + y.zbir;
	return t;
}

int n, m;
node a[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int l;
		cin >> l;
		node t;
		for (int j=0; j<l; j++) {
			int x;
			cin >> x;
			if (j)
				t = spoji(t, napravi(x));
			else
				t = napravi(x);
		}
		a[i] = t;
	}
	node q = napravi(-1e18);
	for (int i=1; i<=m; i++) {
		int x;
		cin >> x;
		q = spoji(q, a[x]);
	}
	cout << q.sol << '\n';
}
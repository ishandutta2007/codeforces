#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct koder {
	int x, y, id;
	bool operator< (const koder& o) const {
		return y - x < o.y - o.x;
	}
};

int n, m;
basic_string<int> e[300005];
koder a[300005], b[300005];

ll z1[300005], z2[300005];

ll sol[300005];

ll adhoc(koder a, koder b) {
	return min(a.x + b.y, b.x + a.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}

	copy(a, a+n, b);
	sort(b, b+n);

	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		e[u] += v;
		e[v] += u;
	}

	for (int i=0; i<n; i++) {
		z1[i+1] = z1[i] + b[i].y;
		z2[i+1] = z2[i] + b[i].x;
		e[i] += i;
	}

	for (int i=0; i<n; i++) {
		auto j = lower_bound(b, b+n, a[i]) - b;

		sol[i] = z1[j] - a[i].y*1ll*j;
		sol[i] += (z2[n] - z2[j]) - a[i].x*1ll*(n-j);
		sol[i] += n*1ll*a[i].x;
		sol[i] += n*1ll*a[i].y;

		for (int x : e[i])
			sol[i] -= adhoc(a[i], a[x]);
	}

	for (int i=0; i<n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}
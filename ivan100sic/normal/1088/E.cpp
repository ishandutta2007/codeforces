#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mx = -1000000009, ct;

int n;
basic_string<int> e[300005];
int a[300005];

ll naj(int x, int p) {
	ll z = a[x];
	for (int y : e[x]) {
		if (y == p)
			continue;
		z += max(0ll, naj(y, x));
	}
	mx = max(mx, z);
	return z;
}

ll cnt(int x, int p) {
	ll z = a[x];
	for (int y : e[x]) {
		if (y == p)
			continue;
		z += max(0ll, cnt(y, x));
	}
	if (z == mx) {
		ct++;
		z = 0;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	naj(1, 1);
	cnt(1, 1);
	cout << mx*ct << ' ' << ct << '\n';
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];
ll d[100005];
ll s = 0;

void inc(int i, ll x) {
	s -= max(d[i], 0ll);
	d[i] += x;
	s += max(d[i], 0ll);
}

ll g() {
	if (d[0] < 0) return s + d[0];
	else return s;
}

ll h(ll x) {
	if (x % 2 == 0) return x/2;
	if (x > 0) return x/2 + 1;
	return x/2;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	d[0] = a[0];
	for (int i=1; i<n; i++) {
		d[i] = a[i] - a[i-1];
	}

	for (int i=0; i<n; i++) {
		s += max(d[i], 0ll);
	}

	cout << h(g()) << '\n';
	int t;
	cin >> t;
	while (t--) {
		int l, r, v;
		cin >> l >> r >> v;
		inc(l-1, v);
		if (r < n) inc(r, -v);
		cout << h(g()) << '\n';
	}
}
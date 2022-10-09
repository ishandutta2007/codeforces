#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[100005];
basic_string<int> e[100005];

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

ll lcm(ll x, ll y) {
	ll g = gcd(x, y);
	if (1.0 * x * y / g > 1e14)
		return 1e14;
	return x / g * y;
}

struct vr {
	ll a, b;
};

// 18/6, 8/4
// 12/12
// 0/12

// (12 13 (5 6))

vr dfs(int x, int p) {
	ll nzs = 1;
	basic_string<vr> rez;
	for (int y : e[x]) {
		if (y == p)
			continue;
		vr d = dfs(y, x);
		rez += d;
		nzs = lcm(nzs, d.b);
	}
	if (rez.size() == 0)
		return {a[x], 1};
	ll sol = 1e14;
	for (auto d : rez)
		sol = min(sol, d.a / nzs * nzs);
	return {sol * (ll)rez.size(), nzs * (ll)rez.size()};
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

	cout << accumulate(a, a+n+1, 0ll) - dfs(1, 1).a << '\n';
}
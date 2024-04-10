#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r;
};

typedef basic_string<seg> vpii;

int a[1505], z[1505], n;
map<int, vpii> mp;
vpii sol;

vpii disj(const vpii& a) {
	vpii b;
	for (auto [l, r] : a) {
		if (b.empty() || l > b.back().r) {
			b += {l, r};
		} else if (r < b.back().r) {
			b.back() = {l, r};
		}
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			mp[z[j]-z[i-1]] += {i, j};
	for (auto [ignore, w] : mp) {
		auto q = disj(w);
		if (q.size() > sol.size())
			sol = q;
	}
	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}
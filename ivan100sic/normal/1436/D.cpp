// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
ll a[200005];
basic_string<int> e[200005];
ll abv[200005], cap[200005];
bool okf;
const ll inf = 1e18;

ll dfs(int x, ll c) {
	if (e[x].empty()) {
		if (a[x] > c) {
			okf = 0;
			return 0;
		} else {
			return c - a[x];
		}
	}

	ll sf = 0;
	for (int y : e[x]) {
		sf += dfs(y, c);
	}

	if (a[x] > sf) {
		okf = 0;
		return 0;
	}

	return sf - a[x];
}

bool ok(ll c) {
	okf = 1;
	dfs(1, c);
	return okf;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}

	for (int i=1; i<=n; i++) {
		long long x;
		cin >> x;
		a[i] = x;
	}

	ll l = 0, r = inf, o = -1;
	while (l <= r) {
		ll m = (l+r) / 2;
		if (ok(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << (long long)(o) << '\n';
}
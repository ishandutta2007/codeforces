#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// dp[i] <- (dp[j] + (xi-xj)*yi - ai)
// dp[i] <- (xi*yi-ai) + dp[j] + (-xj) * yi

struct line {
	ld kraj;
	ll k, b;
	ld val(ld x) const {
		return k*x + b;
	}
};

struct rect {
	ll x, y, w;
	bool operator< (const rect& o) const {
		return x < o.x;
	}
};

int n;
rect a[1000005];
line s[2000005]; int sl, sr;

ld presek(line u, line v) {
	return (ld)(v.b - u.b) / (u.k - v.k);
}

void add_line(ll k, ll b) {
	line t = {0, k, b};
	while (sl != sr) {
		ld x = s[sl].kraj;
		if (s[sl].val(x) < t.val(x)) {
			sl++;
		} else {
			break;
		}
	}
	if (sl == sr) {
		t.kraj = 1e36;
		s[sr++] = t;
	} else {
		t.kraj = presek(s[sl], t);
		s[--sl] = t;
	}
}

ll search(ll x) {
	int l = sl, r = sr-1;
	ll best = -1e18;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (s[m].kraj >= x) {
			best = max(best, s[m].k * x + s[m].b);
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	sort(a+1, a+n+1);
	sl = sr = 1000002;
	add_line(0, 0);
	ll sol = 0;
	for (int i=1; i<=n; i++) {
		ll dpi = search(a[i].y) + a[i].x * a[i].y - a[i].w;
		sol = max(sol, dpi);
		add_line(-a[i].x, dpi);
	}
	cout << sol << '\n';
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
int a[200005], ainv[200005], b[200005], bp[200005];
ll x, y;

void ans(ll x) {
	cout << x << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> x >> k >> y;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
		ainv[a[i]] = i;
	}

	for (int i=0; i<m; i++) {
		cin >> b[i];
		b[i]--;
		bp[i] = ainv[b[i]];
	}

	ll sol = 0;

	// moze?
	for (int i=0; i<m-1; i++) {
		if (bp[i] > bp[i+1]) {
			ans(-1);
		}
	}

	for (int i=0; i<=m; i++) {
		int bord = 0, l = -1, r = -1;

		if (i > 0) {
			l = bp[i-1] + 1;
			bord = a[bp[i-1]];
		} else {
			l = 0;
		}

		if (i < m) {
			r = bp[i];
			bord = max(bord, a[bp[i]]);
		} else {
			r = n;
		}

		if (l == r) {
			continue;
		}

		if (r-l < k) {
			// could mean trouble!
			// possible only when all are less than bord
			if (*max_element(a+l, a+r) < bord) {
				sol += (r-l) * y;
			} else {
				ans(-1);
			}

			continue;
		}

		if (k*y < x) {
			// prefer Berserk
			if (*max_element(a+l, a+r) < bord) {
				// can we do it with Berserk only?
				sol += (r-l) * y;
			} else {
				// if not, we must do at least one FB, do berserks until you reach k elms
				sol += (r-l-k) * y + x;
			}
		} else {
			// prefer Fireball
			sol += x * ((r-l) / k) + y * ((r-l) % k);
		}
	}

	ans(sol);
}
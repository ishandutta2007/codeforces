// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double ld;

double rd_() {
	string s;
	cin >> s;
	int k = s.size();
	int p = find(begin(s), end(s), '.') - begin(s);
	if (p == k) {
		ll x = 0;
		for (int i=0; i<k; i++) {
			x = 10*x + s[i] - 48;
		}
		return x;
	} else {
		ll x = 0, f = 0, g = 1;
		for (int i=0; i<p; i++) {
			x = 10*x + s[i] - 48;
		}
		for (int i=p+1; i<k; i++) {
			f = 10*f + s[i] - 48;
			g = 10*g;
		}

		return ld(x*g + f) / g;
	}
}

double rd() {
	ld x;
	scanf("%lf", &x);
	return x;
}

struct pt {
	ld x, y;
};

struct hcirc {
	ld x, y, r;
};

int n;
vector<pt> a[1000005];
ld povrs[1000005];
hcirc hc[1000005];

inline ld sq(ld x) { return x*x; }

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	rd(); rd();

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int c;
		scanf("%d", &c);
		a[i].resize(c);
		for (auto& [x, y] : a[i]) {
			x = rd();
			y = rd();
		}

		ld xlo = 1e18, xhi = -1e18;
		ld ylo = 1e18, yhi = -1e18;

		for (int j=0; j<c; j++) {
			int k = j == c-1 ? 0 : j+1;
			auto [u, v] = a[i][j];
			auto [p, q] = a[i][k];
			povrs[i] += u*q - p*v;

			xlo = min(xlo, u);
			ylo = min(ylo, v);
			xhi = max(xhi, u);
			yhi = max(yhi, v);
		}

		hc[i] = {(xlo + xhi) / 2, (ylo + yhi) / 2, sqrt(sq(xhi - xlo) + sq(yhi - ylo)) / 2};
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		ld x, y, r;
		x = rd();
		y = rd();
		r = rd();
		ld mv = r*0.1273123;

		basic_string<int> sol;
		ld s = 0;

		for (int i=0; i<n; i++) {
			int c = a[i].size();
			bool touch = false;
			int h = 0;

			// no, skip?
			if (sq(hc[i].x - x) + sq(hc[i].y - y) > sq(r + hc[i].r)) {
				continue;
			}

			for (int j=0; j<c; j++) {
				int k = j == c-1 ? 0 : j+1;
				auto [p, q] = a[i][j];
				auto [u, v] = a[i][k];
				p -= x;
				q -= y;
				u -= x;
				v -= y;

				ld sqd = sq(p-u) + sq(q-v);
				ld det = q*u - p*v;
				ld mul = det / sqd;
				ld hx = (q-v) * mul;
				ld hy = (u-p) * mul;
				ld r2 = sq(r);

				if ((hx-p)*(hx-u) + (hy-q)*(hy-v) < 0) {
					touch |= sq(hx) + sq(hy) <= r2;
				}

				touch |= sq(p) + sq(q) <= r2;

				if (touch) break;

				p += mv;
				u += mv;
				if (p*u < 0 && (p-u)*(q*u - p*v) < 0)
					h++;
			}

			if (touch || h % 2) {
				sol += i;
				s += povrs[i];
			}
		}

		printf("%lf %d\n", s/2, (int)sol.size());
		for (int x : sol)
			printf(" %d", x);
		printf("\n");
	}
}
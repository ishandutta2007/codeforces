#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld sol = 0;
int n, k, a;
int b[8], l[8];

void solve() {
	ld s = 0;
	for (int mask=0; mask<(1<<n); mask++) {
		ld p = 1;
		int b = 0, f = 0;
		for (int i=0; i<n; i++) {
			if (mask & (1 << i)) {
				p *= (100 - l[i]) / 100.0;
				b += ::b[i];
			} else {
				p *= l[i] / 100.0;
				f += 1;
			}
		}

		if (2*f > n) {
			s += p;
		} else {
			s += p*a/(a+b);
		}
	}

	sol = max(sol, s);
}

void gen(int i, int k) {
	if (i == n) {
		solve();
		return;
	}

	int tmp = l[i];
	for (int j=0; j<=k; j++) {
		l[i] = min(100, tmp + j*10);
		gen(i+1, k-j);
	}
	l[i] = tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> a;
	for (int i=0; i<n; i++) {
		cin >> b[i] >> l[i];
	}

	gen(0, k);
	cout << setprecision(20) << fixed << sol << '\n';
}
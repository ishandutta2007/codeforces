// thanks for the time limit, you must be so proud of yourself
// this is the worst problem i've seen in a while
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[19], b[19], c[19];

int f[10], sol;

void ok() {
	int g[10], h[10];
	copy(f, f+10, g);
	for (int i=18; i>=0; i--) {
		bool put = 0;
		if (g[a[i]]) {
			copy(g, g+10, h);
			h[a[i]]--;
			int p = 9;
			bool ok = 1;
			for (int j=i-1; j>=0; j--) {
				while (!h[p]) p--;
				h[p]--;
				if (p > a[j]) {
					break;
				} else if (p < a[j]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				g[a[i]]--;
				c[i] = a[i];
				put = 1;
			}
		}

		if (!put) {
			bool ok = false;
			for (int j=a[i]+1; j<=9; j++) {
				if (g[j]) {
					c[i] = j;
					g[j]--;
					ok = true;
					break;
				}
			}
			if (!ok) {
				return;
			}
			int p = 0;
			for (int j=i-1; j>=0; j--) {
				while (!g[p]) p++;
				g[p]--;
				c[j] = p;
			}
			break;
		}
	}

	for (int i=18; i>=0; i--) {
		if (c[i] < b[i]) {
			sol++;
			return;
		} else if (c[i] > b[i]) {
			return;
		}
	}
	sol++;
}

void rek(int d, int g) {
	if (!d) {
		f[0] = g;
		ok();
		return;
	}
	for (int i=0; i<=g; i++) {
		f[d] = i;
		rek(d-1, g-i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll l, r;
	cin >> l >> r;
	for (ll i=0,x=l; i<19; i++,x/=10)
		a[i] = x%10;
	for (ll i=0,x=r; i<19; i++,x/=10)
		b[i] = x%10;
	rek(9, 19);
	cout << sol << '\n';
}
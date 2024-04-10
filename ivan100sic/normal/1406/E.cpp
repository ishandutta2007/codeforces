// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;

int ask(char t, ll x) {
	if (x > n) return 0;
	cout << t << ' ' << x << '\n' << flush;
	int y;
	cin >> y;
	return y;
}

basic_string<int> d[100005], p;
int alive[100005], alive_cnt;

void kill(int q) {
	for (int i=q; i<=n; i+=q) {
		alive_cnt -= alive[i];
		alive[i] = 0;
	}
}

int est(ll q) {
	int z = 0;
	for (ll i=q; i<=n; i+=q) {
		z += alive[i];
	}
	return z;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	alive_cnt = n;
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j+=i) {
			d[j] += i;
		}
		alive[i] = 1;
	}

	for (int i=2; i<=n; i++) {
		if (d[i].size() == 2) {
			p += i;
		}
	}

	ll x = 1;

	for (int i=0; i<100; i++) {
		int l = p.size() * i / 100;
		int r = p.size() * (i+1) / 100;
		for (int j=l; j<r; j++) {
			int q = p[j];
			ask('B', q);
			kill(q);
		}

		// it's one of these
		if (ask('A', 1) != alive_cnt) {
			for (int k=l; k<(int)p.size(); k++) {
				int r = p[k];
				if (ask('A', r) != est(r)) {
					while (ask('A', x*r) != est(x*r)) {
						x *= r;
					}
				}
			}
			break;
		}
	}

	ask('C', x);
}
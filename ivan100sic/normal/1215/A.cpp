#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, p, q, k;

	cin >> n >> m >> p >> q >> k;

	// hi, izbacuj greedy
	if (p > q) {
		swap(p, q);
		swap(n, m);
	}

	int lo, hi;

	if (k <= n*p) {
		hi = k/p;
	} else {
		hi = n + (k-n*p)/q;
	}

	lo = max(0, n+m-(n*p+m*q-k));

	cout << lo << ' ' << hi << '\n';
}
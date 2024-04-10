#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[200005];
int n, m;
int k[200005], k2[200005], sumk;

bool probaj(int t) {
	int spent = 0, spendable = 0;
	copy(k+1, k+n+1, k2+1);
	for (int i=min(200000, t); i>=1; i--) {
		for (int x : e[i]) {
			spendable += k2[x];
			k2[x] = 0;
		}
		if (spendable > 0) {
			spendable--;
			spent++;
		}
	}

	cerr << "t = " << t << '\n';
	cerr << "spent = " << spent << '\n';

	return 2*sumk - spent <= t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> k[i];
		sumk += k[i];
	}

	for (int i=0; i<m; i++) {
		int d, t;
		cin >> d >> t;
		e[d] += t;
	}

	int l = 0, r = 600005, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (probaj(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}
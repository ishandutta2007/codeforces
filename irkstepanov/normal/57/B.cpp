#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int mod = 1e9 + 7;

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

const int nmax = 100500;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	vector<int> l(m), r(m);
	vector<ll> c(m);
	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i] >> c[i];
	}

	ll res = 0;

	while (q--) {
		int pos;
		cin >> pos;
		ll ans = 0;
		for (int i = 0; i < m; ++i) {
			if (pos >= l[i] && pos <= r[i]) {
				ans += c[i] + pos - l[i];
			}
		}
		res += ans;
	}
	cout << res << "\n";

}
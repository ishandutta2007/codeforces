#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int BASE = 10'000'019;
const int MOD = 1'000'000'007;

int n, k, q;
int v[36000], w[36000], l[36000], r[36000];
const int MAXN = 65536;
basic_string<int> e[2 * MAXN];
int isq[2*MAXN];

void add(int l, int r, int i, int x = 1, int xl = 1, int xr = MAXN) {
	if (r < xl || xr < l)
		return;
	if (l <= xl && xr <= r) {
		e[x] += i;
		return;
	}
	int xm = (xl+xr) >> 1;
	add(l, r, i, 2*x, xl, xm);
	add(l, r, i, 2*x+1, xm+1, xr);
}

int ans(const vector<int>& dp) {
	int pw = 1, z = 0;
	for (int i=1; i<=k; i++) {
		z = (z + 1ll * dp[i] * pw) % MOD;
		pw = (pw * 1ll * BASE) % MOD;
	}
	return z;
}

void dodaj(vector<int>& dp, int v, int w) {
	for (int i=k; i>=w; i--)
		dp[i] = max(dp[i], dp[i-w] + v);
}

void solve(vector<int> dp, int x=1, int xl=1, int xr=MAXN) {
	if (!isq[x])
		return;
	// dodaj ove u cvoru
	for (int i : e[x])
		dodaj(dp, v[i], w[i]);
	if (x >= MAXN)
		cout << ans(dp) << '\n';
	else {
		int xm = (xl+xr) >> 1;
		solve(dp, 2*x, xl, xm);
		solve(dp, 2*x+1, xm+1, xr);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> v[i] >> w[i];
		l[i] = 1;
		r[i] = n+30000;
	}
	cin >> q;
	int xtra = 0;
	for (int i=1; i<=q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			xtra++;
			cin >> v[n+xtra] >> w[n+xtra];
			l[n+xtra] = n+i;
			r[n+xtra] = n+q;
		} else if (t == 2) {
			int x;
			cin >> x;
			r[x] = n+i;
		} else {
			int z = n+i + MAXN - 1;
			while (z > 0) {
				isq[z] = 1;
				z >>= 1;
			}
		}
	}

	for (int i=1; i<=n+q; i++) {
		if (v[i] > 0) {
			add(l[i], r[i], i);
		}
	}

	solve(vector<int>(k+1, 0));
}
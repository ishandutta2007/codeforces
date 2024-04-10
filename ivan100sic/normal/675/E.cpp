#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXN = 131072;

int n;
int h[100005];
pair<int, int> a[2*MAXN];
ll dp[100005];

void update(int x, pair<int, int> v) {
	x += MAXN;
	a[x] = v;
	while (x > 1) {
		x >>= 1;
		a[x] = max(a[2*x], a[2*x+1]);
	}
}

pair<int, int> query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return {0, 0};
	if (l <= xl && xr <= r)
		return a[x];
	int xm = (xl+xr) >> 1;
	return max(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> h[i];
		update(i, {h[i], i});
	}
	h[n] = n;
	update(n, {n, n});

	ll sol = 0;

	for (int i=n-1; i>=1; i--) {
		int j = query(i+1, h[i]).second;
		dp[i] = dp[j] - (h[i] - j) + (n - h[i]) + (h[i] - i);
		// cerr << i << ' ' << dp[i] << '\n';
		sol += dp[i];
	}

	cout << sol << '\n';
}
#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define N 101

ll dp[N][N][N * N];
ll n, k, a[N], b[N], c[N], d[N];

#define DP dp[i][ct][sm]
ll r(ll i, ll ct, ll sm) {
	if(i < 0) return (1 - (!ct) * (!sm)) * N * N;
	if(~DP) return DP;
	DP = r(i - 1, ct, sm) + a[i];
	if(ct) DP = min(DP, r(i - 1, ct - 1, max(0, sm - b[i])));
	return DP;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof dp);
	cin >> n;
	F(i, 0, n) cin >> a[i];
	F(i, 0, n) cin >> b[i];
	copy_n(b, n, c);
	sort(c, c + n);
	reverse(c, c + n);
	partial_sum(c, c + n, d);
	k = 1;
	ll sm = accumulate(a, a + n, 0);
	while(d[k - 1] < sm) k++;
	cout << k << ' ' << r(n - 1, k, sm) << '\n';
}
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, x;

ll dp[2][5005];
ll a[5005];

ll pref[5005], suff[5005];

void napravi(ll* a) {
	for (int i=0; i<=n; i++) {
		if (i % k == 0) {
			pref[i] = a[i];
		} else {
			pref[i] = max(pref[i-1], a[i]);
		}
	}
	suff[n] = a[n];
	for (int i=n-1; i>=0; i--) {
		if (i % k == k-1) {
			suff[i] = a[i];
		} else {
			suff[i] = max(suff[i+1], a[i]);
		}
	}
}

ll gett(int l, int r) {
	if (r < 0)
		return -123123123123123123ll;
	if (r < k)
		return pref[r];
	return max(suff[l], pref[r]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> x;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	memset(dp[0], 128, sizeof(dp[0]));
	dp[0][0] = 0;
	auto ol = dp[0];
	auto nu = dp[1];
	for (int i=0; i<x; i++) {
		napravi(ol);
		for (int j=0; j<=n; j++)
			nu[j] = gett(j-k, j-1) + a[j];

		swap(ol, nu);
	}
	ll sol = -1;
	for (int i=n-k+1; i<=n; i++)
		sol = max(sol, ol[i]);
	cout << sol << '\n';
}
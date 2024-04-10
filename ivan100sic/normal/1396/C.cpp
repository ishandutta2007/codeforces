// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Dokle vise sa ovako govnjivim zadacima, aman????

const ll inf = 1e18;
ll a[1000005], dp[1000005][2];

void mn(ll& x, ll y) {
	x = min(x, y);
}

ll n, r1, r2, r3, d;

ll dvaput(ll k) {
	return min((a[k] + 2) * r1, r2 + r1);
}

ll jednom(ll k) {
	return a[k] * r1 + r3;
}

ll kakogod(ll k) {
	return min(jednom(k), dvaput(k));
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	memset(dp, 63, sizeof dp);
	dp[1][0] = jednom(1);
	dp[2][0] = jednom(1) + jednom(2) + d;
	dp[2][1] = kakogod(1) + kakogod(2) + 3*d;

	for (int i=3; i<=n; i++) {
		// simple 1
		mn(dp[i][0], jednom(i) + min(dp[i-1][0], dp[i-1][1]) + d);
		// dva sa prethodnom dvojkom
		mn(dp[i][1], kakogod(i) + dp[i-1][1] + 3*d);
		// dva bez prethodne dvojke
		mn(dp[i][1], kakogod(i) + kakogod(i-1) + min(dp[i-2][0], dp[i-2][1]) + 4*d);
	}

	ll sol = min(dp[n][0], dp[n][1]);

	// cerr << "sol " << __LINE__ << ' ' << sol << '\n';

	// klasa
	ll vr = kakogod(n-1) + jednom(n) + 2*d;
	mn(vr, kakogod(n-1) + kakogod(n) + 4*d);
	for (int i=n-2; i>=1; i--) {
		mn(sol, min(dp[i][0], dp[i][1]) + vr + d);
		// cerr << "sol " << __LINE__ << ' ' << i << ' ' << sol << '\n';
		vr += 2*d;
		vr += kakogod(i);
	}

	// cerr << "sol " << __LINE__ << ' ' << sol << '\n';

	// vrati se skroz kuci?
	ll ajde = 2*(n-1)*d;
	for (int i=1; i<n; i++) {
		ajde += kakogod(i);
	}

	// cerr << "sol " << __LINE__ << ' ' << ajde + jednom(n) << '\n';
	mn(sol, ajde + jednom(n));
	// cerr << "sol " << __LINE__ << ' ' << ajde + kakogod(n) + 2*d << '\n';
	mn(sol, ajde + kakogod(n) + 2*d);

	// for (int i=1; i<=n; i++) {
	// 	cerr << i << ": " << jednom(i) << ' ' << kakogod(i) << '\n';
	// }

	cout << sol << '\n';
}
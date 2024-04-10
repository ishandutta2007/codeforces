#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

const int nmax = 1050;

ld dp[2][nmax];

ll pw(ll x, ll y) {
	ll ans = 1;
	for (int i = 0; i < y; ++i) {
		ans *= x;
	}
	return ans;
}

ld get(ll l, ll r) {
	ll ans = 0;
	for (int i = 0; i <= 18; ++i) {
		ll x = pw(10, i);
		ll y = x * 2 - 1;
		ll a = max(x, l), b = min(y, r);
		if (a <= b) {
			ans += b - a + 1;
		}
	}
	return ld(ans) / (r - l + 1);
}

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; ++i) {
    	cin >> l[i] >> r[i];
    }
    
    int k;
    cin >> k;

    dp[0][0] = 1;
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < nmax; ++j) {
    		dp[ptr ^ 1][j] = 0;
    	}
    	ld p = get(l[i], r[i]);
    	for (int j = 0; j <= i; ++j) {
    		dp[ptr ^ 1][j + 1] += p * dp[ptr][j];
    		dp[ptr ^ 1][j] += (1 - p) * dp[ptr][j];
    	}
    	ptr ^= 1;
    }

    ld ans = 0;
    for (int i = 0; i <= n; ++i) {
    	if (i * 100 >= k * n) {
    		ans += dp[ptr][i];
    	}
    }

    cout << fixed;
    cout.precision(20);
    cout << ans << "\n";

}
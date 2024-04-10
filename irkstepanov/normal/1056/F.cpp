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

struct datum {
	int a, p;
	bool operator<(const datum& other) const {
		return a > other.a;
	}
};

const int nmax = 105;

ld dp[nmax][nmax * 10];
const ld inf = 1e18;

bool eq(ld a, ld b) {
	return abs(a - b) <= 1e-9;
}

bool ok(ld a, ld b, ld c, ld u) {
	if (c <= 0) {
		return true;
	}
	if (a * u * u + b * u + c <= 0) {
		return true;
	}
	ld x = -b / (2 * a);
	if (x >= 0 && x <= u && a * x * x + b * x + c <= 0) {
		return true;
	}
	return false;
}

ld degs[nmax];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    degs[0] = 0.9;
    for (int i = 1; i < nmax; ++i) {
    	degs[i] = degs[i - 1] * 0.9;
    }
    
    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	ld c, t;
    	cin >> c >> t;
    	vector<datum> a(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i].a >> a[i].p;
    	}
    	sort(all(a));

    	for (int i = 0; i < nmax; ++i) {
    		for (int j = 0; j < nmax * 10; ++j) {
    			dp[i][j] = inf;
    		}
    	}
    	dp[0][0] = 0;
    	for (int i = 0; i < n; ++i) {
    		for (int k = i; k >= 0; --k) {
    			for (int b = k * 10; b >= k; --b) {
    				if (eq(dp[k][b], inf)) {
    					continue;
    				}
    				dp[k + 1][b + a[i].p] = min(dp[k + 1][b + a[i].p], dp[k][b] + ld(a[i].a) / degs[k]);
    			}
    		}
    	}
    	int ans = 0;
    	for (int k = 0; k <= n; ++k) {
    		for (int b = max(k, ans); b <= k * 10; ++b) {
    			if (eq(dp[k][b], inf)) {
    				continue;
    			}
    			ld d = dp[k][b];
    			if (ok(c, 1 - c * t + c * k * 10, d - t + k * 10, t)) {
    				ans = max(ans, b);
    			}
    		}
    	}
    	cout << ans << "\n";
    }

}
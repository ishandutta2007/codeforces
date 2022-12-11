#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

const int rmax = 31;

int getMax(int n, int k) {
	vector<vector<int> > dp(2, vector<int>(rmax, -1));
	int val = (n & (1 << (rmax - 1)));
	if (bit(k, rmax - 1)) {
		dp[1][rmax - 1] = (val ^ (1 << (rmax - 1)));
		dp[0][rmax - 1] = val;
	} else {
		dp[1][rmax - 1] = val;
	}
	for (int r = rmax - 2; r >= 0; --r) {
		if (dp[0][r + 1] != -1) {
			dp[0][r] = max(dp[0][r], dp[0][r + 1] | (1 << r));
		}
		if (dp[1][r + 1] != -1) {
			val = (n & (1 << r));
			if (bit(k, r)) {
				dp[1][r] = max(dp[1][r], dp[1][r + 1] ^ val ^ (1 << r));
				dp[0][r] = max(dp[0][r], dp[1][r + 1] ^ val);
			} else {
				dp[1][r] = max(dp[1][r], dp[1][r + 1] ^ val);
			}
		}
	}
	assert(dp[1][0] == (n ^ k));
	return max(dp[0][0], dp[1][0]);
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;
    while (tt--) {
    	int n, m;
    	cin >> n >> m;
    	int lf = -1, rg = m + 2;
    	while (rg - lf > 1) {
    		int k = (lf + rg) >> 1;
    		if (getMax(n, k) <= m) {
    			lf = k;
    		} else {
    			rg = k;
    		}
    	}
    	cout << rg << "\n";
    }

}
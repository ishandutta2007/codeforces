#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 1510;

int dp[nmax][nmax];
int pref[nmax];

int get(int l, int r) {
	int ans = pref[r];
	if (l) {
		ans -= pref[l - 1];
	}
	return ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int m,s ,k;
    cin >> n >> s >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    vector<int> sorted = a;
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    vector<int> to(n, -1);
    while (s--) {
    	int l, r;
    	cin >> l >> r;
    	--l, --r;
    	to[l] = max(to[l], r);
    }

    vector<int> opt(n);
    opt[0] = to[0];
    for (int i = 1; i < n; ++i) {
    	opt[i] = max(opt[i - 1], to[i]);
    }

    int lf = -1, rg = sz(sorted);
    while (rg - lf > 1) {
    	memset(dp, 0, sizeof(dp));
    	int md = (lf + rg) >> 1;
    	int val = sorted[md];
    	if (a[0] <= val) {
    		pref[0] = 1;
    	} else {
    		pref[0] = 0;
    	}
    	for (int i = 1; i < n; ++i) {
    		pref[i] = pref[i - 1];
    		if (a[i] <= val) {
    			++pref[i];
    		}
    	}
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j <= m; ++j) {
    			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    			if (opt[i] >= i) {
    				dp[opt[i] + 1][j + 1] = max(dp[opt[i] + 1][j + 1], dp[i][j] + get(i, opt[i]));
    			}
    		}
    	}
    	//cout << "!" << dp[3][1] << endl;
    	int maxx = 0;
    	for (int i = 0; i <= n; ++i) {
    		for (int j = 0; j <= m; ++j) {
    			maxx = max(maxx, dp[i][j]);
    		}
    	}
    	if (maxx >= k) {
    		rg = md;
    	} else {
    		lf = md;
    	}
    }

    if (rg == sz(sorted)) {
    	cout << "-1\n";
    	return 0;
    }


    cout << sorted[rg] << endl;

    
}
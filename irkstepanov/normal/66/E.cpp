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

void solve(const vector<ll>& d, vector<bool>& ans) {
	int n = sz(d);
	vector<ll> dp(n), suff(n);
	dp[n - 1] = min(d[n - 1], ll(0));
	suff[n - 1] = d[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		dp[i] = min(d[i], ll(0));
		dp[i] = min(dp[i], d[i] + dp[i + 1]);
		suff[i] = d[i] + suff[i + 1];
	}
	ll worst_prefix = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += d[i];
		worst_prefix = min(worst_prefix, sum);
	}
	for (int i = 0; i < n; ++i) {
		if (dp[i] >= 0 && suff[i] + worst_prefix >= 0) {
			ans[i] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	cin >> b[i];
    }

    vector<ll> d;
    for (int i = 0; i < n; ++i) {
    	d.pb(a[i] - b[i]);
    }

    vector<bool> ans(n, false);
    solve(d, ans);

    d.clear();
    vector<bool> ans2(n, false);
    for (int i = n; i; --i) {
    	d.pb(a[i % n] - b[i - 1]);
    }
    solve(d, ans2);
    for (int i = 0; i < n; ++i) {
    	if (ans2[i]) {
    		ans[(n - i) % n] = true;
    	}
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	if (ans[i]) {
    		++cnt;
    	}
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
    	if (ans[i]) {
    		cout << i + 1 << " ";
    	}
    }
    cout << "\n";

}
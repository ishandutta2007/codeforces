#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pll> dp(n);
    dp[n - 1] = {a[n - 1], 0};

    for (int i = n - 2; i >= 0; --i) {
        pll p = dp[i + 1];
        dp[i] = {p.second + a[i], p.first};
        ll sum = a[i];
        for (int j = i + 1; j < n; ++j) {
            p = {0, 0};
            if (j + 1 < n) {
                p = dp[j + 1];
            }
            //cout << p.first << " " << p.second << "\n";
            if (dp[i].first < p.second + a[j]) {
                dp[i] = {p.second + a[j], p.first + sum};
            }
            sum += a[j];
        }
    }

    cout << dp[0].second << " " << dp[0].first << "\n";

}
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = sz(s);

    vector<vector<ll> > dp(n, vector<ll>(10));
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int d = 0; d < 10; ++d) {
            int x = (s[i] - '0') + d;
            dp[i][x / 2] += dp[i - 1][d];
            if (x % 2 == 1 && (x / 2 + 1) < 10) {
                dp[i][x / 2 + 1] += dp[i - 1][d];
            }
        }
    }

    ll ans = 0;
    for (int d = 0; d < 10; ++d) {
        ans += dp[n - 1][d];
    }
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        int x = (s[i] - '0') + (s[i - 1] - '0');
        if (x / 2 != s[i] - '0' && (x + 1) / 2 != s[i] - '0') {
            ok = false;
        }
    }
    if (ok) {
        --ans;
    }
    cout << ans << "\n";
    
}
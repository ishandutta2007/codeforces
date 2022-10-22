#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll dp[3001][3001];
string s, t;

ll calc(int l, int r) {
    if(dp[l][r] > -1) return dp[l][r];
    if(l == r) return 1;
    ll ans = 0;
    if(r-1 < t.size()) {
        if(s.at(r-l-1) == t.at(r-1)) {
            ans += calc(l, r-1);
        }
    }
    else ans += calc(l, r-1);
    if(l < t.size()) {
        if(s.at(r-l-1) == t.at(l)) {
            ans += calc(l+1, r);
        }
    }
    else ans += calc(l+1, r);
    return dp[l][r] = ans%MOD;
}

int main() {
    for(int i = 0; i < 3001; i++) {
        for(int j = 0; j < 3001; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> s >> t;
    ll ans = 0;
    for(int i = t.size(); i <= s.size(); i++) {
        ans += calc(0, i);
        ans %= MOD;
    }
    cout << ans << '\n';
}
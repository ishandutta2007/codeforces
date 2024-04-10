#include<bits/stdc++.h>

using namespace std;

// fuck life

const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<string> dp(1 << n);
    vector<int> cnt(1 << n);
    map<string, int> cost;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        int id = i + 1;
        if (id * 2 > (int) s.size()) {
            dp[i] = s[i];
        } else {
            dp[i] = s[i] + min(dp[id * 2 - 1], dp[id * 2]) + max(dp[id * 2 - 1], dp[id * 2]);
        }
        if (cost.find(dp[i]) != cost.end()) {
            int v = cost[dp[i]];
            cnt[i] = cnt[v];
        } else {
            if (id * 2 > (int) s.size()) {
                cnt[i] = 1;
            } else if (dp[id * 2 - 1] == dp[id * 2]) {
                cnt[i] = cnt[id * 2] * 1ll * cnt[id * 2] % mod;
            } else {
                cnt[i] = 2 * 1ll * cnt[id * 2 - 1] % mod * cnt[id * 2] % mod;
            }
            cost[dp[i]] = i;
        }
        //cout << dp[i] << " " << cost[dp[i]] << " " << cnt[i] << endl;
    }
    cout << cnt[0];
}
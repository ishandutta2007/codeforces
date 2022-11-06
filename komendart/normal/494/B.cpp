#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    string templ = t + "#" + s;
    vector<int> pi(templ.size(), 0);
    for (int i = 1; i < templ.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && templ[i] != templ[j]) j = pi[j - 1];
        if (templ[i] == templ[j]) j++;
        pi[i] = j;
    }

    vector<int> dp(templ.size(), 0);
    vector<int> prefix_sum(templ.size(), 0);
    vector<int> prefix_sum2(templ.size(), 0);
    int last_meeting = -1;
    for (int i = t.size() + 1; i < templ.size(); i++) {
        if (pi[i] == t.size()) {
            last_meeting = i - (int) t.size() + 1;
        }
        if (last_meeting != -1) {
           dp[i] = prefix_sum2[last_meeting - 1] + last_meeting - (int) t.size();
           dp[i] %= MOD;
        }
        prefix_sum[i] = (prefix_sum[i - 1] + dp[i]) % MOD;
        prefix_sum2[i] = (prefix_sum2[i - 1] + prefix_sum[i]) % MOD;
    }

    cout << prefix_sum.back() << endl;
}
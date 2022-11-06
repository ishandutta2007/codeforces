#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> l(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    unordered_map<int, int> dp;
    dp.rehash(3e5);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto j: dp) {
            int t = gcd(j.first, l[i]);
            if (dp.find(t) == dp.end()) {
                dp[t] = j.second + c[i];
            } else {
                dp[t] = min(dp[t], j.second + c[i]);
            }
        }
    }

    if (dp.find(1) == dp.end()) {
        cout << -1 << '\n';
    } else {
        cout << dp[1] << '\n';
    }
}
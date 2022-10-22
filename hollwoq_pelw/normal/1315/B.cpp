#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr int ALPHABET_SIZE = 26;
constexpr ll INF = 1e18;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    string s;
    vector<ll> dp;
    for (int _ = 0; _ < T; ++_) {
        int a, b, p;
        cin >> a >> b >> p;

        cin >> s;

        int n = s.length();

        dp.assign(n, 0);

        for (int i = n - 2; i >= 0; --i) {
            if (i + 1 == n - 1) {
                dp[i] = (s[i] == 'A' ? a : b);
            }
            else if (s[i] == s[i + 1]) {
                dp[i] = dp[i + 1];
            }
            else {
                dp[i] = dp[i + 1] + (s[i] == 'A' ? a : b);
            }
        }

        int ans = n - 1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] <= p) {
                ans = i;
                break;
            }
        }

        cout << ans + 1 << "\n";
    }

    return 0;
}
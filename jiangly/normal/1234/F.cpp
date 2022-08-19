#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    string s;
    cin >> s;
    int f[1 << 20] = {};
    memset(f, 0x80, sizeof(f));
    f[0] = 0;
    for (int i = 0; i < int(s.length()); ++i) {
        int mask = 0;
        for (int j = i; j < min(i + 20, int(s.length())); ++j)
            if (mask >> (s[j] - 'a') & 1)
                break;
            else {
                mask |= 1 << (s[j] - 'a');
                f[mask] = j - i + 1;
            }
    }
    for (int i = 1; i < 1 << 20; ++i)
        for (int j = 0; j < 20; ++j)
            if (i >> j & 1)
                f[i] = max(f[i], f[i ^ 1 << j]);
    int ans = 0;
    for (int i = 0; i < 1 << 20; ++i)
        ans = max(ans, f[i] + f[((1 << 20) - 1) ^ i]);
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}
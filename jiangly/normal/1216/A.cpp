#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n / 2; ++i)
        if (s[2 * i] == s[2 * i + 1]) {
            s[2 * i] = 'a' + 'b' - s[2 * i];
            ++ans;
        }
    cout << ans << '\n';
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
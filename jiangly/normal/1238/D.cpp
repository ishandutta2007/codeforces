#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    LL ans = LL(n) * (n - 1) / 2;
    for (int i = 0; i < n - 1; ++i)
        if (s[i] != s[i + 1])
            --ans;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n - 1 && s[j + 1] == s[i])
            ++j;
        if (j - i >= 1) {
            if (i > 0)
                ans -= j - i;
            if (j < n - 1)
                ans -= j - i;
        }
        i = j + 1;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
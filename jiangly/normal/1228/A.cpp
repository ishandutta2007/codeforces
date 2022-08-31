#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        string s = to_string(i);
        sort(s.begin(), s.end());
        if (unique(s.begin(), s.end()) == s.end()) {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}
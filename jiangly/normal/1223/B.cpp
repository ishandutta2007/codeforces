#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void init() {
    
}
void solve() {
    string s, t;
    cin >> s >> t;
    set<char> a(s.begin(), s.end()), b(t.begin(), t.end());
    for (char c : a)
        if (b.count(c)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}
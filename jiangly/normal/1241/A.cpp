#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void init() {
    
}
void solve() {
    int n;
    cin >> n;
    if (n <= 4)
        cout << 4 - n << "\n";
    else
        cout << n % 2 << "\n";
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
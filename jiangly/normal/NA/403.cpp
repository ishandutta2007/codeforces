#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    LL x, y;
    cin >> x >> y;
    if (y == x - 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
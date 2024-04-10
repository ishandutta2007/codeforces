#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << (sum + n - 1) / n << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}
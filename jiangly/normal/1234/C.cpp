#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    int x = 0;
    for (int i = 0; i < n; ++i)
        if (s[x][i] > '2') {
            x ^= 1;
            if (s[x][i] <= '2') {
                cout << "NO\n";
                return;
            }
        }
    if (x == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
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
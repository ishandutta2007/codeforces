#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 12;
string s[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i)
    if (s[i][m - 1] == 'R')
        ++ans;
    for (int j = 0; j + 1 < m; ++j)
    if (s[n - 1][j] == 'D')
        ++ans;
    cout << ans << "\n";
}

int main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}
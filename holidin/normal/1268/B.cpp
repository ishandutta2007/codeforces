#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 1;
int a[N], b[N];
int dp[N][4];

void solve() {
    string s;
    int i, j, k, n;
    cin >> n;
    int ans = 0;
    int d[2];
    d[0] = d[1] = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i % 2] += a[i] / 2;
        d[(i + 1) % 2] += a[i] - a[i] / 2;
    }
    cout << min(d[0], d[1]);
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, test;

    solve();
}
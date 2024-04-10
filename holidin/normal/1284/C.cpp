#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

int p[N];

void solve() {
    int i, j, k, n, m, q;
    cin >> n >> m;
    p[0] = 1;
    for (i = 1; i <= n; ++i)
        p[i] = (p[i - 1] * i) % m;
    int ans = (n * p[n]) % m;
    for (int len = 2; len <= n; ++len) {
        int pos = n - len + 1;
        ans = (ans + ((((p[len] * pos) % m) * p[n - len]) % m) * pos) % m;
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);

    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
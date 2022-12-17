#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 1005 + 1;
int sumclose[N];

int a[N];
int cnt[N];

void solve() {
    int i, j, n, mod;
    cin >> n >> mod;
    if (n > mod) {
        cout << 0;
        return;
    }
    int ans = 1;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        for (j = 0; j < i; ++j)
            ans = (ans * abs(a[i] - a[j])) % mod;
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 2e5 + 100;
int a[N], l[N], r[N], bg[N], en[N], cnt[N], c[N];


void solve() {
    int i, j, k, n;
    cin >> n >> k;
    for (i = 0; i < N; ++i)
        l[i] = inf, r[i] = 0;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = i + 1;
        ++cnt[a[i]];
    }
    for (i = 0; i < N; ++i)
    if (r[i] != 0) {
        ++bg[l[i]];
        c[l[i]] = cnt[i];
        ++en[r[i]];
    }
    int ans = 0, balance = 0, mx = 0;
    for (i = 0; i <= n; ++i) {
        balance -= en[i];
        if (balance == 0) {
            ans -= mx;
            mx = 0;
        }
        if (bg[i] > 0) {
            ans += c[i];
            mx = max(mx, c[i]);
        }
        balance += bg[i];
    }
    cout << ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    solve();
}
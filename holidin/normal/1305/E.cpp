#include <bits/stdc++.h>
#pragma GCC optimize 03
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 22;

int a[N], cnt[N];

mt19937 rnd(10000);

void solve() {
    int i, j, n, b, m;
    cin >> n >> m;
    int sum = 0;
    for (i = 1; i <= n; ++i)
    if ((i - 1) / 2 + sum <= m) {
        a[i] = i;
        sum += (i - 1) / 2;
    } else
        break;
    if (i > n && sum < m) {
        cout << -1;
        exit(0);
    }
    int p = i;
    for (i = 1; i <= p; ++i)
    for (j = i + 1; j <= p; ++j)
        ++cnt[a[i] + a[j]];
    int x;
    if (p <= n)
    for (i = p; i <= 1000000; ++i)
    if (cnt[i] == m - sum) {
        sum = 0;
        a[p] = i;
    }
    x = 1e8 + 1;
    for (i = p + 1; i <= n; ++i) {
        a[i] = x + 10012 * i;
    }
    for (i = 1; i <= n; ++i)
        cout << a[i] << ' ';
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}
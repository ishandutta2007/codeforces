#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;

int a[N], t[N], pr[N];

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

void solve() {
    int i, j, k, n, m, d, w;
    cin >> m >> d >> w;
    int mn = min(m, d);
    int ans = 0;
    if (d % w == 1) {
        cout << mn * (mn - 1) / 2 << "\n";
        return;
    }
    int ans1 = 0;
    bool has = 0;
    int c;
    for (c = 2; c * c <= w; ++c)
    if (w % c == 0 && d % (w / c) == 1 % (w / c)) {
        int tt = mn / c;
        ans1 = mn * tt - c * tt * (tt + 1) / 2;
        has = 1;
        break;
    }
    if (!has)
    for (; c >= 1; --c)
    if (w % c == 0 && d % c == 1 % c) {
        int tt = mn / (w / c);
        ans1 = mn * tt - (w / c) * tt * (tt + 1) / 2;
        break;
    }
    cout << ans1  << "\n";
}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}
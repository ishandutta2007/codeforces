#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 1e6 + 5;

int pref[maxn][10];
int g[maxn];
int f[maxn];

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < 10; ++j) {
            pref[i][j] = pref[i - 1][j];
        }
        if (i < 10) {
            f[i] = i;
        } else if (i % 10 == 0) {
            f[i] = f[i / 10];
        } else {
            f[i] = f[i / 10] * (i % 10);
        }
        if (i < 10) g[i] = i;
        else g[i] = g[f[i]];
        ++pref[i][g[i]];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pref[r][k] - pref[l - 1][k] << '\n';
    }
}
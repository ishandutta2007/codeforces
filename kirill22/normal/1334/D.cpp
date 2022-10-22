#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define all(a) a.begin(), a.end()

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    int x = -1;
    if (r == n * (n - 1))  {
        x = 1;
        r--;
    }
    int tmp = 1;
    int j = 0;
    for (int i = l; i <= r; i++) {
        while (j + (n - tmp) * 2 - 1 < i) {
            tmp++;
            j += (n - tmp + 1) * 2;
        }
        if (i % 2 == j % 2) cout << tmp << " ";
        else {
            int p = (i - j) / 2;
            cout << tmp + 1 + p << " ";
        }
    }
    if (x != -1) cout << 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
}
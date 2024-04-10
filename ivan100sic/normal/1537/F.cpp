// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
basic_string<int> e[200005];
int a[200005];

int c[200005], bip;
void dfs(int x) {
    for (int y : e[x]) {
        if (c[y] == 0) {
            c[y] = 3 - c[x];
            dfs(y);
        } else if (c[y] == c[x]) {
            bip = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            e[i] = {};
            c[i] = 0;
            bip = 1;
        }

        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            int y;
            cin >> y;
            a[i] -= y;
        }

        for (int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            e[x] += y;
            e[y] += x;
        }

        c[1] = 1;
        dfs(1);

        if (!bip) {
            cout << (accumulate(a+1, a+n+1, 0ll) % 2 == 0 ? "YES\n" : "NO\n");
        } else {
            ll z = 0;
            for (int i=1; i<=n; i++) {
                z += a[i] * (c[i] * 2 - 3);
            }
            cout << (z == 0 ? "YES\n" : "NO\n");
        }
    }
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
int a[100005];
vector<int> e[100005];
int cnt, tgt;

int dfs(int x, int p) {
    int z = a[x];
    for (int y : e[x]) {
        if (y == p) continue;
        z ^= dfs(y, x);
    }
    if (z == tgt) {
        cnt++;
        return 0;
    } else {
        return z;
    }
}

void ans(bool b) {
    cout << (b ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i=1; i<=n; i++) e[i] = {};
        cnt = 0;

        for (int i=1; i<=n; i++) cin >> a[i];
        
        for (int i=1; i<n; i++) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        tgt = accumulate(a+1, a+n+1, 0, bit_xor<int>());
        dfs(1, 1);

        if (tgt == 0) {
            ans(true);
        } else {
            ans(cnt >= 3 && k >= 3);
        }
    }
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int a[501][501];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, pair<int, int>>> edges(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) a[i][j] = 0;
            else a[i][j] = n;
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        a[x][y] = a[y][x] = 1;
        edges[i] = {c, make_pair(x, y)};
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    ll ans = 1234567891234567890;
    for(auto pa : edges) {
        ll c = pa.first;
        auto p = pa.second;
        int x, y;
        tie(x, y) = p;
        ans = min(ans, c * (a[0][x] + a[y][n-1] + 1));
        ans = min(ans, c * (a[0][y] + a[x][n-1] + 1));
        for(int i = 0; i < n; i++) {
            ans = min(ans, c * (a[0][i] + a[x][i] + a[n-1][i] + 2));
            ans = min(ans, c * (a[0][i] + a[y][i] + a[n-1][i] + 2));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
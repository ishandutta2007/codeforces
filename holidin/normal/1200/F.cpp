#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e3 + 1;
const int mod = 5 * 7 * 8 * 9;

set <int> s;
bool circle;
int xk, yk;
int t[N][mod], cnt[N * mod], top = 0;
bool use[N][mod];
int d[N];
vector <int> e[N];

void dfs(int u, int y) {
    use[u][y] = 1;
    int y1 = ((y + d[u]) % mod + mod) % mod;
    int u1 = e[u][y1 % e[u].size()];
    if (use[u1][y1])
        if (t[u1][y1] == 0) {
            s.clear();
            s.insert(u);
            circle = 1;
            t[u][y] = ++top;
            xk = u1, yk = y1;
            if (u == xk && y == yk) {
                circle = 0;
                cnt[t[u][y]] = s.size();
            }
        } else {
            t[u][y] = t[u1][y1];
            circle = 0;
        }
    else {
        dfs(u1, y1);
        t[u][y] = t[u1][y1];
        if (circle) {
            s.insert(u);
            if (u == xk && y == yk) {
                circle = 0;
                cnt[t[u][y]] = s.size();
            }
        }
    }
}

int main() {
    int i, j, k, n, q, u, y;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> d[i];
    for (i = 1; i <= n; ++i) {
        cin >> k;
        e[i].resize(k);
        for (j = 0; j < k; ++j)
            cin >> e[i][j];
    }
    for (i = 1; i <= n; ++i)
        for (j = 0; j < mod; ++j)
            if (!use[i][j])
                dfs(i, j);
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> u >> y;
        y = ((y % mod) + mod) % mod;
        cout << cnt[t[u][y]] << "\n";
    }
}
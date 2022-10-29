#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char g[1005][1005];
ll cnt[1005][1005];
ll dir[][2] = {0, 1, 1, 0, -1, 0, 0, -1};
struct node {
    ll x, y;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, t;
    cin >> n >> m >> t;
    memset(cnt, 0x3f, sizeof cnt);
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++) cin >> g[i][j];
    queue<node> que;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            bool f = 0;
            for (ll k = 0; k < 4; k++) {
                ll x = i + dir[k][0];
                ll y = j + dir[k][1];
                if (g[x][y] == 0) continue;
                if (g[i][j] == g[x][y]) f = 1;
            }
            if (f) {
                que.push({i, j});
                cnt[i][j] = 0;
            }
        }
    }
    while (!que.empty()) {
        ll x = que.front().x;
        ll y = que.front().y;
        ll d = cnt[x][y];
        que.pop();
        for (ll k = 0; k < 4; k++) {
            ll xx = x + dir[k][0];
            ll yy = y + dir[k][1];
            if (g[xx][yy] == 0) continue;
            if (cnt[xx][yy] > d + 1) {
                cnt[xx][yy] = d + 1;
                que.push({xx, yy});
            }
        }
    }
    for (ll i = 1; i <= t; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll k = cnt[a][b];
        if (k == 0x3f3f3f3f3f3f3f3f) {
            cout << g[a][b] << endl;
            continue;
        }
        if (k >= c)
            cout << g[a][b] << endl;
        else {
            if ((c - k) & 1)
                cout << (g[a][b] == '0' ? 1 : 0) << endl;
            else
                cout << g[a][b] << endl;
        }
    }
}
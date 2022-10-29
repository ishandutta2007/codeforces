#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 3e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, m;

ll encode(ll i, ll j) {
    return i * m + j;
}

void decode(ll x, ll &i, ll &j) {
    i = x / m;
    j = x % m;
}

struct edge {
    ll to;
    ll c;
};

ll dis[N];
vector<vector<char> > gra;
vector<edge> g[N];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    ll p, q;
    cin >> p >> q;
    memset(dis, 0x3f, sizeof dis);
    gra.resize(n + 5, vector<char>(m + 5, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> gra[i][j];
        }
    }
    vector<ll> v;
    ll cst[3] = {p, p, q};
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (gra[i][j] == '.') {
                v.push_back(encode(i, j));
            } else if (gra[i][j] == 'L') {
                ll dir[][2] = {1, 1, -1, 1, 0, 2};
                for (ll k = 0; k < 3; k++) {
                    ll xx = i + dir[k][0];
                    ll yy = j + dir[k][1];
                    if (1 <= xx && xx <= n && 1 <= yy && yy <= m && gra[xx][yy] != '#') {
                        g[encode(xx, yy)].push_back({encode(i, j), cst[k]});
                    }
                }
            } else if (gra[i][j] == 'R') {
                ll dir[][2] = {-1, -1, 1, -1, 0, -2};
                for (ll k = 0; k < 3; k++) {
                    ll xx = i + dir[k][0];
                    ll yy = j + dir[k][1];
                    if (1 <= xx && xx <= n && 1 <= yy && yy <= m && gra[xx][yy] != '#') {
                        g[encode(xx, yy)].push_back({encode(i, j), cst[k]});
                    }
                }
            } else if (gra[i][j] == 'U') {
                ll dir[][2] = {1, -1, 1, 1, 2, 0};
                for (ll k = 0; k < 3; k++) {
                    ll xx = i + dir[k][0];
                    ll yy = j + dir[k][1];
                    if (1 <= xx && xx <= n && 1 <= yy && yy <= m && gra[xx][yy] != '#') {
                        g[encode(xx, yy)].push_back({encode(i, j), cst[k]});
                    }
                }
            } else if (gra[i][j] == 'D') {
                ll dir[][2] = {-1, 1, -1, -1, -2, 0};
                for (ll k = 0; k < 3; k++) {
                    ll xx = i + dir[k][0];
                    ll yy = j + dir[k][1];
                    if (1 <= xx && xx <= n && 1 <= yy && yy <= m && gra[xx][yy] != '#') {
                        g[encode(xx, yy)].push_back({encode(i, j), cst[k]});
                    }
                }
            }
        }
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<>> que;
    for (auto x: v) {
        dis[x] = 0;
        que.push({0, x});
    }

    while (!que.empty()) {
        auto [d, x] = que.top();
        que.pop();
        if (d > dis[x]) {
            continue;
        }
        for (auto e: g[x]) {
            if (dis[e.to] > dis[x] + e.c) {
                dis[e.to] = dis[x] + e.c;
                que.push({dis[e.to], e.to});
            }
        }
    }
    ll ans = inf;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (gra[i][j] == '#' || dis[encode(i, j)] == inf) continue;
            ll dir[][2] = {1, 0, 0, 1};
            for (ll k = 0; k < 2; k++) {
                ll xx = i + dir[k][0];
                ll yy = j + dir[k][1];
                if (xx <= n && yy <= m && gra[xx][yy] != '#' && dis[encode(xx, yy)] != inf) {
                    ans = min(ans, 1ll * dis[encode(i, j)] + dis[encode(xx, yy)]);
                }
            }
        }
    }
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}
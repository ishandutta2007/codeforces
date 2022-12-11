#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<pii> p(r);
    vector<vector<int> > hor(n), ver(m);
    int start;
    map<pii, int> mapa;
    for (int i = 0; i < r; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        p[i] = {a, b};
        mapa[{a, b}]= i;
        hor[a].pb(i);
        ver[b].pb(i);
        if (a == 0 && b == 0) {
            start = i;
        }
    }

    queue<int> q[2];
    q[0].push(start);
    vector<int> dist(r, inf);
    dist[start] = 0;

    int curr = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = inf;
    while (!q[curr].empty()) {
        vector<int> vct;
        while (!q[curr].empty()) {
            int v = q[curr].front();
            q[curr].pop();
            vct.pb(v);
            for (int k = 0; k < 4; ++k) {
                int x = p[v].first + dx[k], y = p[v].second + dy[k];
                if (mapa.count({x, y})) {
                    int u = mapa[{x, y}];
                    if (dist[u] > dist[v]) {
                        dist[u] = dist[v];
                        q[curr].push(u);
                    }
                }
            }
        }
        curr ^= 1;
        for (int v : vct) {
            vector<int> vx = {p[v].first - 2, p[v].first - 1, p[v].first, p[v].first + 1, p[v].first + 2};
            for (int x : vx) {
                if (x >= 0 && x < n) {
                    if (x == n - 1 && x != p[v].first + 2) {
                        ans = min(ans, dist[v] + 1);
                    }
                    for (int i : hor[x]) {
                        if (dist[i] > dist[v] + 1) {
                            dist[i] = dist[v] + 1;
                            q[curr].push(i);
                        }
                    }
                    hor[x].clear();
                }
            }
            vector<int> vy = {p[v].second - 2, p[v].second - 1, p[v].second, p[v].second + 1, p[v].second + 2};
            for (int y : vy) {
                if (y >= 0 && y < m) {
                    if (y == m - 1 && y != p[v].second + 2) {
                        ans = min(ans, dist[v] + 1);
                    }
                    for (int i : ver[y]) {
                        if (dist[i] > dist[v] + 1) {
                            dist[i] = dist[v] + 1;
                            q[curr].push(i);
                        }
                    }
                    ver[y].clear();
                }
            }
        }
    }

    for (int v = 0; v < r; ++v) {
        if (p[v].first == n - 1 && p[v].second == m - 1) {
            ans = min(ans, dist[v]);
        } else if (p[v].first == n - 1 || p[v].second == m - 1) {
            ans = min(ans, dist[v] + 1);
        }
    }

    cout << (ans == inf ? -1 : ans) << "\n";

}
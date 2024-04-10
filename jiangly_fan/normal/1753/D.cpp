#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
using PLI = pair<LL, int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<string> s(n);
    for (auto& si : s) cin >> si;
    vector vis(n, vector<int>(m));
    LL ans = -1;
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < m; j += 1)
            if (s[i][j] != '#' and not vis[i][j]) {
                vector<int> dx = {0, -1, 0, 1};
                vector<int> dy = {1, 0, -1, 0};
                auto check = [&](int x, int y) {
                    return x >= 0 and x < n and y >= 0 and y < m and s[x][y] != '#';
                };
                map<pair<int, int>, int> mp;
                vector<pair<int, int>> vp;
                int k = 0;
                function<void(int, int)> DFS = [&](int x, int y) {
                    vis[x][y] = 1;
                    mp[{x, y}] = k ++;
                    vp.emplace_back(x, y);
                    for (int i = 0; i < 4; i += 1) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (check(nx, ny) and not vis[nx][ny])
                            DFS(nx, ny);
                    }
                };
                DFS(i, j);
                vector<vector<pair<int, int>>> G(k);
                vector<LL> d(k, -1);
                priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
                auto add = [&](int u, int x, int y, int w) {
                    if (check(x, y)) G[u].emplace_back(mp[{x, y}], w);
                };
                for (auto [x, y] : vp){
                    if (s[x][y] == 'L') {
                        add(mp[{x, y}], x, y + 2, q);
                        add(mp[{x, y}], x - 1, y + 1, p);
                        add(mp[{x, y}], x + 1, y + 1, p);
                    } else if (s[x][y] == 'R') {
                        add(mp[{x, y}], x, y - 2, q);
                        add(mp[{x, y}], x - 1, y - 1, p);
                        add(mp[{x, y}], x + 1, y - 1, p);
                    } else if (s[x][y] == 'U') {
                        add(mp[{x, y}], x + 2, y, q);
                        add(mp[{x, y}], x + 1, y - 1, p);
                        add(mp[{x, y}], x + 1, y + 1, p);
                    } else if (s[x][y] == 'D') {
                        add(mp[{x, y}], x - 2, y, q);
                        add(mp[{x, y}], x - 1, y - 1, p);
                        add(mp[{x, y}], x - 1, y + 1, p);
                    } else {
                        pq.emplace(d[mp[{x, y}]] = 0, mp[{x, y}]);
                    }
                }
                vector<vector<pair<int, int>>> H(k);
                for (int i = 0; i < k; i += 1)
                    for (auto [j, w] : G[i])
                        H[j].emplace_back(i, w);
                G.swap(H);
                while (not pq.empty()) {
                    auto [_, u] = pq.top();
                    pq.pop();
                    if (_ > d[u]) continue;
                    for (auto [v, w] : G[u]) {
                        if (d[v] == -1 or d[v] > d[u] + w)
                            pq.emplace(d[v] = d[u] + w, v);
                    }
                }
                for (auto [x, y] : vp) {
                    for (int i = 0; i < 4; i += 1) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (check(nx, ny)) {
                            int a = mp[{x, y}];
                            int b = mp[{nx, ny}];
                            if (d[a] != -1 and d[b] != -1) {
                                LL pans = d[a] + d[b];
                                if (ans == -1 or ans > pans)
                                    ans = pans;
                            }
                        }
                    }
                }
            }
    cout << ans;
}
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
int t, n, m, vCnt, bCnt;
std::vector<std::string> mp, ans;
std::vector<std::vector<int>> vId, e;
std::vector<std::pair<int, int>> edges, ver;
std::vector<bool> isIn;
std::vector<int> deg, dis, pre;
class DSU {
private:
    std::vector<int> fa;
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0)
            x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
public:
    DSU(int n) : fa(n, -1) {}
    bool query(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (fa[x] > fa[y])
                std::swap(x, y);
            fa[x] += fa[y];
            fa[y] = x;
        }
    }
};
void solve() {
    std::cin >> n >> m;
    mp.resize(n);
    vId.assign(n, std::vector<int>(m));
    edges.clear();
    ver.clear();
    vCnt = 0;
    bCnt = 0;
    for (int i = 0; i < n; ++i)
        std::cin >> mp[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 'O') {
                if ((i + j) % 2 == 0 && (i != 0 || j != 0))
                    ++bCnt;
                vId[i][j] = vCnt++;
                ver.emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 'O' && (i != 0 || j != 0)) {
                if (i + 1 < n && mp[i + 1][j] == 'O') {
                    if ((i + j) % 2 == 0) {
                        edges.emplace_back(vId[i][j], vId[i + 1][j]);
                    } else {
                        edges.emplace_back(vId[i + 1][j], vId[i][j]);
                    }
                }
                if (j + 1 < m && mp[i][j + 1] == 'O') {
                    if ((i + j) % 2 == 0) {
                        edges.emplace_back(vId[i][j], vId[i][j + 1]);
                    } else {
                        edges.emplace_back(vId[i][j + 1], vId[i][j]);
                    }
                }
            }
        }
    }
    isIn.assign(edges.size(), false);
    int baseSize = 0;
    while (true) {
        e.assign(edges.size(), std::vector<int>());
        for (int i = 0; i < int(edges.size()); ++i) {
            if (isIn[i]) {
                deg.assign(vCnt, 0);
                DSU s(vCnt);
                for (int j = 0; j < int(edges.size()); ++j) {
                    auto [u, v] = edges[j];
                    if (i != j && isIn[j]) {
                        ++deg[u];
                        s.merge(u, v);
                    }
                }
                for (int j = 0; j < int(edges.size()); ++j) {
                    auto [u, v] = edges[j];
                    if (!isIn[j]) {
                        if (deg[u] <= 1)
                            e[i].push_back(j);
                        if (!s.query(u, v))
                            e[j].push_back(i);
                    }
                }
            }
        }
        dis.assign(edges.size(), -1);
        pre.assign(edges.size(), -1);
        deg.assign(vCnt, 0);
        DSU s(vCnt);
        for (int i = 0; i < int(edges.size()); ++i) {
            auto [u, v] = edges[i];
            if (isIn[i]) {
                ++deg[u];
                s.merge(u, v);
            }
        }
        std::queue<int> que;
        for (int i = 0; i < int(edges.size()); ++i) {
            auto [u, v] = edges[i];
            if (!isIn[i] && deg[u] <= 1) {
                dis[i] = 0;
                que.push(i);
            }
        }
        int t = -1;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            if (!isIn[u] && !s.query(edges[u].first, edges[u].second)) {
                t = u;
                break;
            }
            for (int v : e[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    pre[v] = u;
                    que.push(v);
                }
            }
        }
        if (t == -1)
            break;
        ++baseSize;
        for (int i = t; i != -1; i = pre[i])
            isIn[i] = !isIn[i];
    }
    if (baseSize < 2 * bCnt) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    DSU s(vCnt);
    for (int i = 0; i < int(edges.size()); ++i) {
        auto [u, v] = edges[i];
        if (isIn[i])
            s.merge(u, v);
    }
    for (int i = 0; i < int(edges.size()); ++i) {
        auto [u, v] = edges[i];
        if (!isIn[i] && !s.query(u, v)) {
            isIn[i] = true;
            s.merge(u, v);
        }
    }
    ans.assign(2 * n - 1, std::string(2 * m - 1, ' '));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans[2 * i][2 * j] = mp[i][j];
    for (int i = 0; i < int(edges.size()); ++i) {
        auto [u, v] = edges[i];
        if (isIn[i]) {
            auto [x1, y1] = ver[u];
            auto [x2, y2] = ver[v];
            if (x1 == x2) {
                ans[x1 + x2][y1 + y2] = '-';
            } else {
                ans[x1 + x2][y1 + y2] = '|';
            }
        }
    }
    if (mp[0][1] == 'O' && !s.query(vId[0][0], vId[0][1])) {
        s.merge(vId[0][0], vId[0][1]);
        ans[0][1] = '-';
    }
    if (mp[1][0] == 'O' && !s.query(vId[0][0], vId[1][0])) {
        s.merge(vId[0][0], vId[1][1]);
        ans[1][0] = '|';
    }
    for (auto &s : ans)
        std::cout << s << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
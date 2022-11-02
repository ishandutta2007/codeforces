#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector adj(2, std::vector<int>(n, -1));
    std::vector<int> u(m), v(m), w(m), a(m, -1), b(m, -1);
    std::vector<int> dir(m, -1);
    int M = m;
    std::function<int(int, int, int, int)> addEdge = [&](int x, int y, int c,
                                                         int j) {
        if (j == -1) {
            j = M++;
            u.push_back(x);
            v.push_back(y);
            w.push_back(c);
            a.push_back(-1);
            b.push_back(-1);
            dir.push_back(-1);
        }
        if (x == y) {
            dir[j] = 0;
            return j;
        }
        if (adj[c - 1][x] != -1) {
            int i = adj[c - 1][x];
            adj[c - 1][u[i]] = adj[c - 1][v[i]] = -1;
            int p = addEdge(u[i] ^ v[i] ^ x, y, c, -1);
            a[p] = i;
            b[p] = j;
            return j;
        }
        if (adj[c - 1][y] != -1) {
            int i = adj[c - 1][y];
            adj[c - 1][u[i]] = adj[c - 1][v[i]] = -1;
            int p = addEdge(x, u[i] ^ v[i] ^ y, c, -1);
            a[p] = i;
            b[p] = j;
            return j;
        }
        adj[c - 1][x] = adj[c - 1][y] = j;
        return j;
    };
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i] >> w[i];
        --u[i], --v[i];
        addEdge(u[i], v[i], w[i], i);
    }
    std::vector<int> out(n);
    std::function<void(int)> dfs = [&](int x) {
        for (int c = 1; c <= 2; ++c) {
            int j = adj[c - 1][x];
            if (j == -1 || dir[j] != -1) {
                continue;
            }
            int y = u[j] ^ v[j] ^ x;
            if (out[x] > 0) {
                dir[j] = 1;
                out[x] -= c;
                out[y] += c;
            } else {
                dir[j] = 0;
                out[x] += c;
                out[y] -= c;
            }
            if (x == v[j]) {
                dir[j] ^= 1;
            }
            dfs(y);
        }
    };
    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += std::abs(out[i]) == 1;
    }
    for (int i = M - 1; i >= m; --i) {
        int A = a[i], B = b[i];
        if (u[i] == v[i]) {
            dir[A] = 0;
            dir[B] = dir[A] ^ (u[A] == u[B]);
            continue;
        }
        if (u[i] == u[A] || v[i] == v[A]) {
            dir[A] = dir[i];
        } else {
            dir[A] = dir[i] ^ 1;
        }
        if (u[i] == u[B] || v[i] == v[B]) {
            dir[B] = dir[i];
        } else {
            dir[B] = dir[i] ^ 1;
        }
    }
    std::cout << ans << '\n';
    for (int i = 0; i < m; ++i) {
        std::cout << dir[i] + 1;
    }
    std::cout << '\n';
    return 0;
}
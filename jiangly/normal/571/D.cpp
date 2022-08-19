#include <bits/stdc++.h>
using namespace std;
constexpr int N = 500000;
struct Tree {
    int n;
    vector<int> parent, lc, rc, id;
    vector<vector<int>> mod;
    Tree(int n) {
        parent.assign(2 * n - 1, -1);
        lc.assign(2 * n - 1, -1);
        rc.assign(2 * n - 1, -1);
        id.resize(n);
        iota(id.begin(), id.end(), 0);
        mod.resize(2 * n - 1);
    }
};
long long fen[N + 1];
void add(int x, int y) {
    for (int i = x + 1; i <= N; i += i & -i)
        fen[i] += y;
}
long long sum(int x) {
    long long res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += fen[i];
    return res;
}
long long sum(int l, int r) {return sum(r) - sum(l);}
int getLeft(int x) {
    int s = sum(x);
    x = 0;
    for (int i = 1 << 18; i > 0; i /= 2) {
        if (x + i <= N && fen[x + i] < s) {
            x += i;
            s -= fen[x];
        }
    }
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Tree t1(n), t2(n);
    vector<vector<int>> query(n);
    vector<int> lb(m), sz(2 * n - 1, 1);
    vector<long long> ans(m, -1);
    int c1 = 0, c2 = 0;
    for (int i = 0; i < m; ++i) {
        char op;
        cin >> op;
        if (op == 'U') {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            int p = n + (c1++);
            t1.parent[t1.id[a]] = t1.parent[t1.id[b]] = p;
            t1.lc[p] = t1.id[a];
            t1.rc[p] = t1.id[b];
            t1.id[a] = p;
            sz[p] = sz[t1.lc[p]] + sz[t1.rc[p]];
        } else if (op == 'M') {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            int p = n + (c2++);
            t2.parent[t2.id[a]] = t2.parent[t2.id[b]] = p;
            t2.lc[p] = t2.id[a];
            t2.rc[p] = t2.id[b];
            t2.id[a] = p;
        } else if (op == 'A') {
            int x;
            cin >> x;
            --x;
            t1.mod[t1.id[x]].push_back(i);
        } else if (op == 'Z') {
            int x;
            cin >> x;
            --x;
            t2.mod[t2.id[x]].push_back(i);
        } else {
            int x;
            cin >> x;
            --x;
            query[x].push_back(i);
        }
    }
    function<void(int)> dfs1 = [&](int u) {
        for (int i : t2.mod[u])
            add(i, 1);
        if (u < n) {
            for (int i : query[u])
                lb[i] = getLeft(i);
        } else {
            dfs1(t2.lc[u]);
            dfs1(t2.rc[u]);
        }
        for (int i : t2.mod[u])
            add(i, -1);
    };
    function<void(int)> dfs2 = [&](int u) {
        for (int i : t1.mod[u])
            add(i, sz[u]);
        if (u < n) {
            for (int i : query[u])
                ans[i] = sum(lb[i], i);
        } else {
            dfs2(t1.lc[u]);
            dfs2(t1.rc[u]);
        }
        for (int i : t1.mod[u])
            add(i, -sz[u]);
    };
    for (int i = 0; i < n + c2; ++i)
        if (t2.parent[i] == -1)
            dfs1(i);
    for (int i = 0; i < n + c1; ++i)
        if (t1.parent[i] == -1)
            dfs2(i);
    for (int i = 0; i < m; ++i)
        if (ans[i] != -1)
            cout << ans[i] << "\n";
    return 0;
}
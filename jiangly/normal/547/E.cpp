#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2E5;
int cnt_nodes, dfs_now;
int child[M][26], in[M], out[M], fail[M];
vector<int> e[M];
int fen[M];
int lowbit(int x) {return x & -x;}
void add(int x, int y) {
    ++x;
    while (x < M) {
        fen[x] += y;
        x += lowbit(x);
    }
}
int sum(int x) {
    int result = 0;
    while (x > 0) {
        result += fen[x];
        x -= lowbit(x);
    }
    return result;
}
int sum(int l, int r) {return sum(r) - sum(l);}
void init() {
    cnt_nodes = 1;
    for (int i = 0; i < 26; ++i)
        child[0][i] = 1;
}
int insert(const string &s) {
    int p = 1;
    for (char c : s) {
        if (child[p][c - 'a'] == 0)
            child[p][c - 'a'] = ++cnt_nodes;
        p = child[p][c - 'a'];
    }
    return p;
}
void build() {
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int i = 0; i < 26; ++i) {
            if (child[p][i] == 0) {
                child[p][i] = child[fail[p]][i];
            } else {
                fail[child[p][i]] = child[fail[p]][i];
                que.push(child[p][i]);
            }
        }
    }
    for (int i = 2; i <= cnt_nodes; ++i)
        e[fail[i]].push_back(i);
}
void dfs(int u) {
    in[u] = dfs_now++;
    for (int v : e[u])
        dfs(v);
    out[u] = dfs_now;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    vector<int> endp(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        endp[i] = insert(s[i]);
    }
    build();
    vector<vector<tuple<int, int, int>>> queries(n);
    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        queries[--r].emplace_back(endp[--k], 1, i);
        if (--l > 0)
            queries[l - 1].emplace_back(endp[k], -1, i);
    }
    dfs(1);
    for (int i = 0; i < n; ++i) {
        int p = 1;
        for (char c : s[i]) {
            p = child[p][c - 'a'];
            add(in[p], 1);
        }
        for (auto qr : queries[i]) {
            int p, coef, j;
            tie(p, coef, j) = qr;
            ans[j] += coef * sum(in[p], out[p]);
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    return 0;
}
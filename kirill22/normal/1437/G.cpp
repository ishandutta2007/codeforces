#include<bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> Td;

void update(int v, int l, int r, int i, int x) {
    if (l + 1 == r) {
        Td[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        update(v * 2 + 1, l, m, i, x);
    } else {
        update(v * 2 + 2, m, r, i, x);
    }
    Td[v] = max(Td[v * 2 + 1], Td[v * 2 + 2]);
}

int get(int v, int l, int r, int l1, int r1) {
    if (l1 >= r || l >= r1) return -1;
    if (l1 <= l && r <= r1) return Td[v];
    int m = (l + r) / 2;
    return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
}

int id = 0;
vector<vector<int>> g;
vector<int> sz, ID, first, h, parent;

void get_sz(int v) {
    sz[v] = 1;
    for (auto u : g[v]) {
        get_sz(u);
        sz[v] += sz[u];
    }
}

void dfs(int v, int pr, int root) {
    ID[v] = id; id++;
    if (pr != -1) {
        h[ID[v]] = h[ID[pr]] + 1;
        parent[ID[v]] = ID[pr];
    }
    int j = -1;
    for (auto u : g[v]) {
        if (u != pr && sz[u] * 2 >= sz[v]) {
            j = u;
        }
    }
    if (j != -1) {
        dfs(j, v, root);
        first[ID[j]] = ID[root];
    }
    for (auto u : g[v]) {
        if (u != pr && u != j) {
            dfs(u, v, u);
            first[ID[u]] = ID[u];
        }
    }
}

int A = 26;
vector<vector<int>> go;
vector<int> suf;

int solve(int x) {
    int res = -1;
    while (true) {
        if (first[x] == 0) {
            res = max(res, get(0, 0, go.size(), 0, x + 1));
            break;
        }
        res = max(res, get(0, 0, go.size(), first[x], x + 1));
        x = parent[first[x]];
    }
    return res;
}

void build() {
    go.push_back(vector<int> (A));
    suf.push_back(0);
}

int add(string s) {
    int v = 0;
    for (auto c : s) {
        if (go[v][c - 'a'] == 0) {
            go[v][c - 'a'] = go.size();
            go.push_back(vector<int> (A));
            suf.push_back(0);
        }
        v = go[v][c - 'a'];
    }
    return v;
}

void bfs() {
    queue<int> q;
    q.push(0);
    g.resize(go.size());
    sz.resize(go.size());
    ID.resize(go.size());
    h.resize(go.size());
    parent.resize(go.size(), -1);
    first.resize(go.size());
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < A; i++) {
            if (go[v][i] == 0) {
                go[v][i] = go[suf[v]][i];
            }
            else {
                if (v) {
                    suf[go[v][i]] = go[suf[v]][i];
                }
                q.push(go[v][i]);
            }
        }
    }
    for (int i = 0; i < go.size(); i++) {
        if (suf[i] != i) {
            g[suf[i]].pb(i);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build();
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = add(s);
    }
    multiset<int> ST[go.size()];
    bfs();
    get_sz(0);
    dfs(0, -1, 0);
    Td.resize(4 * g.size(), -1);
    for (auto x : a) {
        ST[ID[x]].insert(0);
        update(0, 0, g.size(), ID[x], 0);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            ST[ID[a[i]]].erase(ST[ID[a[i]]].find(b[i]));
            ST[ID[a[i]]].insert(x);
            b[i] = x;
            update(0, 0, g.size(), ID[a[i]], *ST[ID[a[i]]].rbegin());
        }
        else {
            int ans = -1;
            string s;
            cin >> s;
            int tmp = 0;
            for (auto c : s) {
                tmp = go[tmp][c - 'a'];
                ans = max(ans, solve(ID[tmp]));
            }
            cout << ans << '\n';
        }
    }
}
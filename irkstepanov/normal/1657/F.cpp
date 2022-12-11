#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int rmax = 25;

vector<vector<int> > tree;
vector<int> parent;
vector<int> tin, tout;
vector<vector<int> > shifts;

int timer = 0;

void dfs(int v, int p) {
    parent[v] = p;
    tin[v] = timer++;
    for (int to : tree[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    tout[v] = timer++;
}

bool ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }
    for (int r = rmax - 1; r >= 0; --r) {
        int p = shifts[r][u];
        if (!ancestor(p, v)) {
            u = p;
        }
    }
    return parent[u];
}

vector<int> path(int u, int v) {
    int w = lca(u, v);
    vector<int> ans;
    int curr = u;
    while (curr != w) {
        ans.pb(curr);
        curr = parent[curr];
    }
    ans.pb(curr);

    vector<int> tmp;
    curr = v;
    while (curr != w) {
        tmp.pb(curr);
        curr = parent[curr];
    }
    reverse(all(tmp));

    for (int x : tmp) {
        ans.pb(x);
    }
    return ans;
}

const int sigma = 26;

vector<vector<int> > g;
int n, q;

void addEdge(int from, int v, int c, bool rev = false) {
    int to = 2 * q + v * sigma + c;
    if (rev) {
        swap(from, to);
    }
    g[from].pb(to);
}

vector<bool> used;
vector<int> order;

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs1(to);
        }
    }
    order.pb(v);
}

vector<int> C;
vector<vector<int> > gr;

void dfs2(int v) {
    C[v] = timer;
    for (int to : gr[v]) {
        if (C[to] == -1) {
            dfs2(to);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    cin >> n >> q;

    g.resize(2 * q + n * sigma);

    tree.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    parent.resize(n);
    tin.resize(n);
    tout.resize(n);
    dfs(0, 0);

    shifts = vector<vector<int> >(rmax, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        shifts[0][i] = parent[i];
    }
    for (int r = 0; r + 1 < rmax; ++r) {
        for (int v = 0; v < n; ++v) {
            int p = shifts[r][v];
            shifts[r + 1][v] = shifts[r][p];
        }
    }


    vector<vector<pii> > who(n);

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        string s;
        cin >> s;
        vector<int> vct = path(u, v);
        assert(sz(vct) == sz(s));
        for (int j = 0, r = sz(s) - 1; j < sz(s); ++j, --r) {
            //cout << "!" << vct[j] << " " << s[j] << endl;
            who[vct[j]].pb({2 * i, s[j] - 'a'});
            addEdge(2 * i, vct[j], s[j] - 'a');
            who[vct[j]].pb({2 * i + 1, s[r] - 'a'});
            addEdge(2 * i + 1, vct[j], s[r] - 'a');
        }
    }

    for (int v = 0; v < n; ++v) {
        for (int c = 0; c < sigma; ++c) {
            for (pii p : who[v]) {
                if (p.second != c) {
                    addEdge(p.first ^ 1, v, c, true);
                }
            }
        }
    }

    int N = sz(g);
    used.assign(N, false);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(all(order));

    gr.resize(N);
    for (int v = 0; v < N; ++v) {
        for (int to : g[v]) {
            gr[to].pb(v);
        }
    }
    C.assign(N, -1);
    timer = 0;
    for (int v : order) {
        if (C[v] == -1) {
            dfs2(v);
            ++timer;
        }
    }

    for (int i = 0; i < q; ++i) {
        if (C[2 * i] == C[2 * i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    vector<int> ans(n, 0);

    for (int v = 0; v < n; ++v) {
        for (pii p : who[v]) {
            int a = p.first;
            int b = p.first ^ 1;
            if (C[a] > C[b]) {
                ans[v] = p.second;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << char(ans[i] + 'a');
    }
    cout << "\n";

}
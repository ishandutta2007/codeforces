#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxn = 1e5 + 5;
const int BLOCK = 500;
const int LOG = 19;

struct Query {
    int left, right, ind;
    int lca;

    bool operator < (const Query &q) const {
        if (left / BLOCK == q.left / BLOCK) {
            return right < q.right;
        }
        return left < q.left;
    }
};

vector<int> graph[maxn];
int sex[maxn];
int f[maxn];
int walk[2 * maxn];
int tin[maxn], tout[maxn], timer = 0;
int go[maxn][LOG];

char used[maxn];
int girls[maxn], boys[maxn];
ll current_ans = 0;

void add(int pos) {
    int v = walk[pos];
    int x = f[v];
    int d = (used[v]) ? -1: 1;
    used[v] = !used[v];
    if (sex[v]) {
        boys[x] += d;
        current_ans += d * girls[x];
    } else {
        girls[x] += d;
        current_ans += d * boys[x];
    }
}

void dfs1(int v, int p) {
    tin[v] = timer++;
    walk[tin[v]] = v;
    for (auto to: graph[v]) {
        if (to != p) {
            dfs1(to, v);
        }
    }
    tout[v] = timer++;
    walk[tout[v]] = v;
}

void dfs2(int v, int p) {
    go[v][0] = (p == -1) ? v: p;
    for (int i = 1; i < LOG; ++i) {
        go[v][i] = go[go[v][i - 1]][i - 1];
    }
    for (auto to: graph[v]) {
        if (to != p) {
            dfs2(to, v);
        }
    }
}

bool is_ancestor(int a, int b) {
    return tin[a] < tin[b] && tout[b] < tout[a];
}

int get_lca(int a, int b) {
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i = LOG - 1; i >= 0; --i) {
        if (!is_ancestor(go[a][i], b)) {
            a = go[a][i];
        }
    }
    return go[a][0];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> sex[i];
    }
    map<int, int> compressed;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (!compressed.count(x)) compressed[x] = i;
        f[i] = compressed[x];
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(1, -1);
    dfs2(1, -1);

    int q;
    cin >> q;
    vector<Query> queries(q);
    vector<ll> ans(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        queries[i].ind = i;
        queries[i].lca = get_lca(a, b);
        if (queries[i].lca == a || queries[i].lca == b) {
            queries[i].lca = -1;
            queries[i].left = min(tin[a], tin[b]);
            queries[i].right = max(tin[a], tin[b]);
        } else {
            queries[i].left = min(tout[a], tout[b]);
            queries[i].right = max(tin[a], tin[b]);
        }
    }

    sort(queries.begin(), queries.end());
    int left = 0, right = -1;
    for (auto &query: queries) {
        while (right < query.right) add(++right);
        while (left > query.left) add(--left);
        while (right > query.right) add(right--);
        while (left < query.left) add(left++);
        if (query.lca != -1) add(tin[query.lca]);
        ans[query.ind] = current_ans;
        if (query.lca != -1) add(tin[query.lca]);
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}
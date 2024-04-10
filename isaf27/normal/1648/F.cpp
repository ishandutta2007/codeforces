#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937_64 rnd(239);
#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

const int M = 5e5 + 239;
const int L = 19;
const int T = (1 << 20) + 239;
const ll INF = 1e18;
const int BIG = 1e9;

int n, m, k;
vector<int> g[M], v[M];
bool used[M];
int tin[M], tout[M], timer, h[M];
vector<pair<int, int>> edges;

void dfs(int p) {
    tin[p] = timer++;
    used[p] = true;
    for (int i : g[p]) {
        if (!used[i]) {
            h[i] = h[p] + 1;
            v[p].emplace_back(i);
            dfs(i);
        } else if (tin[i] < tin[p] && h[i] < h[p] - 1) {
            // i --- p is outer edge
            edges.emplace_back(i, p);
        }
    }
    tout[p] = timer;
}

int dp[M][L];

void dfs_tree(int p, int last) {
    dp[p][0] = last;
    for (int i = 1; i < L; i++) {
        dp[p][i] = dp[dp[p][i - 1]][i - 1];
    }
    for (int i : v[p]) {
        dfs_tree(i, p);
    }
}

bool is_upper(int s, int f) {
    return tin[s] <= tin[f] && tout[f] <= tout[s];
}

int lca(int s, int f) {
    if (is_upper(s, f)) {
        return s;
    }
    if (is_upper(f, s)) {
        return f;
    }
    for (int i = L - 1; i >= 0; i--) {
        if (!is_upper(dp[s][i], f)) {
            s = dp[s][i];
        }
    }
    return dp[s][0];
}

vector<int> paths_down[M];
ll sum_idx[M], hash1[M], hash2[M];
int hash_idx[M];
int cnt[M];

void dfs_counters(int p) {
    for (int i : v[p]) {
        dfs_counters(i);
        cnt[p] += cnt[i];
        sum_idx[p] += sum_idx[i];
        hash1[p] += hash1[i];
        hash2[p] += hash2[i];
    }
}

int hash_order[M];

void calc_hash_idx() {
    iota(hash_order, hash_order + n, 0);
    sort(hash_order, hash_order + n, [&](int i, int j) {
        if (hash1[i] != hash1[j]) {
            return hash1[i] < hash1[j];
        }
        return hash2[i] < hash2[j];
    });
    int cnt = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hash1[hash_order[i - 1]] != hash1[hash_order[i]] ||
            hash2[hash_order[i - 1]] != hash2[hash_order[i]]) {
            cnt++;
        }
        hash_idx[hash_order[i]] = cnt;
    }
}

pair<int, int> info[M];
int first[M], last[M];
int cnt_equal[M];
int vertex_idx[M];

void dfs_comp(int p) {
    vertex_idx[h[p]] = p;
    if (p > 0 && sum_idx[p] > 0) {
        if (info[hash_idx[p]].first == -1) {
            info[hash_idx[p]] = make_pair(h[p], h[p]);
        } else {
            first[p] = info[hash_idx[p]].first;
            last[p] = info[hash_idx[p]].second;
            cnt_equal[vertex_idx[last[p]]]--, cnt_equal[p]++;
            info[hash_idx[p]].second = h[p];
        }
    }
    for (int i : v[p]) {
        dfs_comp(i);
    }
}

vector<int> hard_paths[M];

int dfs_hard_paths(int p) {
    int go = p;
    for (int i : v[p]) {
        int cur = dfs_hard_paths(i);
        if (cnt_equal[i] > 0) {
            go = cur;
        }
        cnt_equal[p] += cnt_equal[i];
    }
    if (p > 0 && (go != p || cnt_equal[p] > 0)) {
        int t = dp[p][0];
        for (int i : paths_down[t]) {
            int x = lca(go, i);
            if (x != t) {
                hard_paths[x].emplace_back(t);
            }
        }
    }
    return go;
}

int ans;
int s1, f1, s2, f2;

// segment tree
pair<ll, int> tree[T];
ll add[T];

void build(int i, int l, int r) {
    tree[i] = make_pair(0LL, r - 1);
    add[i] = 0;
    if (r - l == 1) {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
}

inline void push(int i, int l, int r) {
    tree[i].first += add[i];
    if (r - l > 1) {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void upd(int i, int l, int r, int ql, int qr, ll x) {
    push(i, l, r);
    if (ql == qr) {
        return;
    }
    if (r <= ql || qr <= l) {
        return;
    }
    if (ql <= l && r <= qr) {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * i + 1, l, mid, ql, qr, x);
    upd(2 * i + 2, mid, r, ql, qr, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

ll global_add;

void make_zero(int i, int l, int r, int p) {
    push(i, l, r);
    if (r - l == 1) {
        tree[i].first = -global_add;
        return;
    }
    int mid = (l + r) / 2;
    if (p < mid) {
        push(2 * i + 2, mid, r);
        make_zero(2 * i + 1, l, mid, p);
    } else {
        push(2 * i + 1, l, mid);
        make_zero(2 * i + 2, mid, r, p);
    }
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

pair<ll, int> getmax(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (qr <= l || r <= ql) {
        return make_pair(-INF, -1);
    }
    if (ql <= l && r <= qr) {
        return tree[i];
    }
    int mid = (l + r) / 2;
    return max(getmax(2 * i + 1, l, mid, ql, qr),
               getmax(2 * i + 2, mid, r, ql, qr));
}

void dfs_ans(int p) {
    vertex_idx[h[p]] = p;
    int to = -1;
    for (int i : v[p]) {
        if (cnt_equal[i] > 0) {
            to = i;
        }
    }
    if (to != -1) {
        {
            int cs = 0;
            for (int i : paths_down[p]) {
                if (is_upper(to, i)) {
                    cs++;
                }
            }
            global_add += cs * 2 + cnt[p] - cnt[to];
        }
        {
            for (int i : hard_paths[p]) {
                upd(0, 0, n, 0, h[i], -2);
            }
        }
        if (last[to] != -1) {
            // possibly update the answer
            upd(0, 0, n, last[to], h[p], -BIG);
            pair<ll, int> t = getmax(0, 0, n, first[to] - 1, h[p]);
            t.first += global_add;
            if (t.first > ans) {
                ans = t.first;
                s1 = to, f1 = p;
                s2 = vertex_idx[t.second], f2 = vertex_idx[t.second + 1];
            }
        }
        make_zero(0, 0, n, h[p]);
        dfs_ans(to);
    }
    for (int i : v[p]) {
        if (i != to) {
            make_zero(0, 0, n, h[p]);
            dfs_ans(i);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v[i].clear();
        g[i].clear();
        paths_down[i].clear();
        hard_paths[i].clear();
        cnt[i] = 0, h[i] = 0;
        sum_idx[i] = 0;
        hash1[i] = 0, hash2[i] = 0;
        first[i] = -1, last[i] = -1;
        cnt_equal[i] = 0;
        used[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int s, f;
        cin >> s >> f;
        s--, f--;
        g[s].emplace_back(f);
        g[f].emplace_back(s);
    }

    // make dfs tree
    edges.clear();
    timer = 0;
    dfs(0);
    dfs_tree(0, 0);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int x = lca(a, b);
        if (x != a) {
            paths_down[x].emplace_back(a);
            cnt[a]++, cnt[x]--;
        }
        if (x != b) {
            paths_down[x].emplace_back(b);
            cnt[b]++, cnt[x]--;
        }
    }

    int idx = 0;
    for (const auto& t : edges) {
        ll h1 = rnd();
        ll h2 = rnd();
        idx++;
        sum_idx[t.first] -= idx;
        sum_idx[t.second] += idx;
        hash1[t.first] -= h1;
        hash1[t.second] += h1;
        hash2[t.first] -= h2;
        hash2[t.second] += h2;
    }
    dfs_counters(0);
    calc_hash_idx();

    ans = 0;
    s1 = 1;
    f1 = dp[1][0];
    s2 = 2;
    f2 = dp[2][0];

    {
        // two bridges
        vector<pair<int, int>> mx;
        mx.reserve(3);
        mx.emplace_back(-1, -1);
        mx.emplace_back(-1, -1);
        for (int i = 1; i < n; i++) {
            if (sum_idx[i] == 0 && hash1[i] == 0 && hash2[i] == 0) {
                mx.emplace_back(cnt[i], i);
                int p = 2;
                while (p > 0 && mx[p - 1] < mx[p]) {
                    swap(mx[p - 1], mx[p]);
                    p--;
                }
                mx.pop_back();
            }
        }
        if (mx[0].second != -1 && ans < mx[0].first) {
            ans = mx[0].first;
            s1 = mx[0].second;
            f1 = dp[s1][0];
            s2 = (s1 % (n - 1)) + 1;
            f2 = dp[s2][0];
        }
        if (mx.back().second != -1) {
            int cur = mx[0].first + mx[1].first;
            if (ans < cur) {
                ans = cur;
                s1 = mx[0].second;
                f1 = dp[s1][0];
                s2 = mx[1].second;
                f2 = dp[s2][0];
            }
        }
    }

    {
        // dfs tree edge + the only outer edge for it
        for (int i = 1; i < n; i++) {
            if (sum_idx[i] >= 1 && sum_idx[i] <= (ll)edges.size()) {
                int x = edges[sum_idx[i] - 1].first;
                int y = edges[sum_idx[i] - 1].second;
                if (is_upper(i, y) && is_upper(x, dp[i][0])) {
                    if (ans < cnt[i]) {
                        ans = cnt[i];
                        s1 = x;
                        f1 = y;
                        s2 = i;
                        f2 = dp[i][0];
                    }
                }
            }
        }
    }

    {
        // two dfs tree edges
        for (int i = 0; i < n; i++) {
            info[i] = make_pair(-1, -1);
        }
        dfs_comp(0);
        dfs_hard_paths(0);
        build(0, 0, n);
        global_add = 0;
        dfs_ans(0);
    }

    cout << ans << "\n";
    cout << s1 + 1 << " " << f1 + 1 << "\n";
    cout << s2 + 1 << " " << f2 + 1 << "\n";
}

int main() {
#ifdef ONPC
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; // g;
    cin >> t; // >> g;
    while (t--) {
        solve();
    }

    return 0;
}
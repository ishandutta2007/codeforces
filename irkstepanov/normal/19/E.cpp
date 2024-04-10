 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int rmax = 15;

vector<vector<int> > g;
map<pii, int> edge_id;
vector<char> used;
vector<int> old_to_new;

class solver
{
public:
    solver(int rr)
    {
        root = rr;
        timer = 0;
        n = 0;
        dfs(root, root);
        shifts.resize(rmax);
        for (int r = 0; r < rmax; ++r) {
            shifts[r].resize(n);
        }
        for (int i = 0; i < n; ++i) {
            shifts[0][i] = parent[i];
        }
        for (int r = 1; r < rmax; ++r) {
            for (int i = 0; i < n; ++i) {
                int t = shifts[r - 1][i];
                shifts[r][i] = shifts[r - 1][t];
            }
        }
        fenwick.resize(2);
        for (int i = 0; i < 2; ++i) {
            fenwick[i].resize(2 * n);
        }
        for (int v : new_to_old) {
            for (int to : g[v]) {
                if (v > to) {
                    continue;
                }
                if (parent[old_to_new[to]] != old_to_new[v] && parent[old_to_new[v]] != old_to_new[to]) {
                    int x = old_to_new[v], y = old_to_new[to];
                    int z = lca(x, y);
                    int dx = dist(x, z);
                    int dy = dist(y, z);
                    if ((dx + dy + 1) & 1) {
                        bad_edges.pb(mp(v, to));
                        if (x != z) {
                            int t = pre(x, z);
                            update(0, t_in[t], 1);
                            update(0, t_in[x] + 1, -1);
                        }
                        if (y != z) {
                            int t = pre(y, z);
                            update(0, t_in[t], 1);
                            update(0, t_in[y] + 1, -1);
                        }
                    } else {
                        if (x != z) {
                            int t = pre(x, z);
                            update(1, t_in[t], 1);
                            update(1, t_in[x] + 1, -1);
                        }
                        if (y != z) {
                            int t = pre(y, z);
                            update(1, t_in[t], 1);
                            update(1, t_in[y] + 1, -1);
                        }
                    }
                }
            }
        }
        if (!bad_edges.empty()) {
            if (sz(bad_edges) == 1) {
                ans.pb(edge_id[bad_edges[0]]);
            }
            for (int i = 0; i < n; ++i) {
                if (get(0, t_in[i]) - get(0, t_out[i]) == sz(bad_edges) && get(1, t_in[i]) - get(1, t_out[i]) == 0) {
                    ans.pb(edge_id[mp(new_to_old[i], new_to_old[parent[i]])]);
                }
            }
            if (ans.empty()) {
                ans = {-1};
            }
        }
    }
    void dfs(int v, int p)
    {
        used[v] = true;
        old_to_new[v] = n;
        new_to_old.pb(v);
        ++n;
        t_in.pb(timer++);
        t_out.pb(0);
        parent.pb(old_to_new[p]);
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to, v);
            }
        }
        t_out[old_to_new[v]] = timer++;
    }
    bool ancestor(int u, int v)
    {
        return t_in[u] <= t_in[v] && t_out[u] >= t_out[v];
    }
    int lca(int u, int v)
    {
        if (ancestor(u, v)) {
            return u;
        }
        for (int r = rmax - 1; r >= 0; --r) {
            if (!ancestor(shifts[r][u], v)) {
                u = shifts[r][u];
            }
        }
        return parent[u];
    }
    int pre(int u, int w)
    {
        for (int r = rmax - 1; r >= 0; --r) {
            if (!ancestor(shifts[r][u], w)) {
                u = shifts[r][u];
            }
        }
        return u;
    }
    int dist(int u, int w) // w is ancestor of u
    {
        if (u == w) {
            return 0;
        }
        int d = 0;
        for (int r = rmax - 1; r >= 0; --r) {
            if (!ancestor(shifts[r][u], w)) {
                d += (1 << r);
                u = shifts[r][u];
            }
        }
        return d + 1;
    }
    void update(int id, int pos, int val)
    {
        for (; pos < 2 * n; pos = (pos | (pos + 1))) {
            fenwick[id][pos] += val;
        }
    }
    int get(int id, int pos)
    {
        int a = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            a += fenwick[id][pos];
        }
        return a;
    }

    vector<int> ans;

private:
    int root, n, timer;
    vector<vector<int> > shifts;
    vector<int> new_to_old;
    vector<pii> bad_edges;
    vector<vector<int> > fenwick;
    vector<int> parent, t_in, t_out;
};

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    cin >> n >> m;
    old_to_new.resize(n);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
        edge_id[mp(u, v)] = i;
        edge_id[mp(v, u)] = i;
    }

    used.assign(n, false);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            solver s(i);
            vector<int> v = s.ans;
            if (v.size() == 1 && v[0] == -1) {
                cout << "0\n";
                return 0;
            }
            if (v.empty()) {
                continue;
            }
            if (ans.empty()) {
                ans = v;
                continue;
            }
            cout << "0\n";
            return 0;
        }
    }

    if (ans.empty()) {
        cout << m << "\n";
        for (int i = 1; i <= m; ++i) {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
    sort(all(ans));
    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}
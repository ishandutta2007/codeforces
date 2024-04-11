#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e17;

struct SegmentTree {
private:
    struct Node {
        pair<ll, int> value;
        ll add;

        Node() {
            value = {INF, -1};
            add = 0;
        }
    };

    int tsize;
    vector<Node> tree;

    void push(int v) {
        if (v >= tsize) return;
        tree[v * 2].value.first += tree[v].add;
        tree[v * 2].add += tree[v].add;
        tree[v * 2 + 1].value.first += tree[v].add;
        tree[v * 2 + 1].add += tree[v].add;
        tree[v].add = 0;
    }

    void update(int l, int r, ll k, int v, int tl, int tr) {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            tree[v].add += k;
            tree[v].value.first += k;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        update(l, r, k, v * 2, tl, tm);
        update(l, r, k, v * 2 + 1, tm + 1, tr);
        tree[v].value = min(tree[v * 2].value, tree[v * 2 + 1].value);
    }

    pair<ll, int> getMin(int l, int r, int v, int tl, int tr) {
        if (r < tl || tr < l) return {INF, -1};
        if (l <= tl && tr <= r) {
            return tree[v].value;
        }
        push(v);
        int tm = (tl + tr) / 2;
        pair<ll, int> left = getMin(l, r, v * 2, tl, tm);
        pair<ll, int> right = getMin(l, r, v * 2 + 1, tm + 1, tr);
        return min(left, right);
    }

public:
    void init(int n) {
        for (tsize = 1; tsize < n; tsize *= 2);
        tree.resize(2 * tsize);
    }

    void updateOnePos(int pos, pair<ll, int> value) {
        pos += tsize;
        vector<int> parents;
        for (int t = pos; t > 1; t >>= 1) {
            parents.push_back(t >> 1);
        }
        reverse(parents.begin(), parents.end());
        for (auto i: parents) {
            push(i);
        }
        tree[pos].value = value;
        for (; pos > 1; pos >>= 1) {
            tree[pos >> 1].value = min(tree[pos].value, tree[pos ^ 1].value);
        }
    }

    void update(int l, int r, ll k) {
        return update(l, r, k, 1, 0, tsize - 1);
    }

    pair<ll, int> getMin(int l, int r) {
        return getMin(l, r, 1, 0, tsize - 1);
    }
};

struct HeavyLight {
private:
    using Graph = vector<vector<int>>;

    SegmentTree tree;
    vector<int> root, parent, heavy, height, tin, tout;
    vector< vector<int> > stacks;
    vector<int> house;

    void initArrays(int n) {
        root.resize(n);
        parent.resize(n);
        heavy.resize(n);
        height.resize(n);
        tin.resize(n);
        tout.resize(n);
    }

    int dfs1(int v, const Graph &graph) {
        int maxSubTreeSize = 0;
        int commonSize = 1;
        for (auto to: graph[v]) {
            if (to != parent[v]) {
                parent[to] = v;
                height[to] = height[v] + 1;
                int subTreeSize = dfs1(to, graph);
                commonSize += subTreeSize;
                if (subTreeSize > maxSubTreeSize) {
                    heavy[v] = to;
                    maxSubTreeSize = subTreeSize;
                }
            }
        }
        return commonSize;
    }

    void dfs2(int v, const Graph &graph) {
        static int timer = 0;
        tin[v] = timer++;
        if (heavy[v]) {
            root[heavy[v]] = root[v];
            dfs2(heavy[v], graph);
        }
        for (auto to: graph[v]) {
            if (to != parent[v] && to != heavy[v]) {
                root[to] = to;
                dfs2(to, graph);
            }
        }
        tout[v] = timer - 1;
    }

public:
    void init(const Graph &graph, const vector<int> c) {
        int n = graph.size();
        initArrays(n);
        dfs1(0, graph);
        dfs2(0, graph);

        tree.init(n);
        stacks.resize(n);
        house = c;
        for (int i = (int) c.size() - 1; i >= 0; --i) {
            int v = c[i];
            tree.updateOnePos(tin[v], {i + 1, i});
            stacks[v].push_back(i);
        }
    }

    void update(int v, int k) {
        tree.update(tin[v], tout[v], k);
    }

    int get(int u, int v) {
        pair<ll, int> ansFirst = {INF, -1};
        pair<ll, int> ansSecond = {INF, -1};
        while (root[u] != root[v]) {
            if (height[root[u]] < height[root[v]]) {
                swap(u, v);
                swap(ansFirst, ansSecond);
            }
            ansFirst = min(ansFirst, tree.getMin(tin[root[u]], tin[u]));
            u = parent[root[u]];
        }
        if (tin[u] > tin[v]) swap(u, v);
        int ans = min({ansFirst, ansSecond, tree.getMin(tin[u], tin[v])}).second;
        if (ans != -1) {
            int v = house[ans];
            stacks[v].pop_back();
            if (stacks[v].empty()) {
                tree.updateOnePos(tin[v], {INF, -1});
            } else {
                int num = stacks[v].back();
                ll value = tree.getMin(tin[v], tin[v]).first;
                tree.updateOnePos(tin[v], {value + (num - ans), num});
            }
        }
        return ans;
    }
};

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector< vector<int> > graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
        --c[i];
    }

    HeavyLight hld;
    hld.init(graph, c);
    for (int i = 0; i < q; ++i) {
        int tp; cin >> tp;
        if (tp == 1) {
            int v, u, k;
            cin >> v >> u >> k;
            --v; --u;
            vector<int> ans;
            for (int i = 0; i < k; ++i) {
                int tmp = hld.get(v, u);
                if (tmp == -1) break;
                ans.push_back(tmp + 1);
            }
            cout << ans.size();
            for (auto i: ans) {
                cout << ' ' << i;
            }
            cout << '\n';
        } else {
            int v, k;
            cin >> v >> k;
            --v;
            hld.update(v, k);
        }
    }
}
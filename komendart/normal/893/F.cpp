#include <bits/stdc++.h>

using namespace std;

const int tsize = 1 << 17;
const int inf = 1e9 + 5;

struct Node {
    int minval;
    Node *left, *right;
};

Node* build(int left=0, int right=tsize-1) {
    if (left == right) return new Node{inf, 0, 0};
    Node *child = build(left, (left + right) / 2);
    return new Node{inf, child, child};
}

int get(Node *node, int l, int r, int tl=0, int tr=tsize-1) {
    if (r < tl || tr < l) return inf;
    if (l <= tl && tr <= r) return node->minval;
    int tm = (tl + tr) / 2;
    int a = get(node->left, l, r, tl, tm);
    int b = get(node->right, l, r, tm + 1, tr);
    return min(a, b);
}

Node *update(Node *node, int p, int value, int tl=0, int tr=tsize - 1) {
    if (tr < p || p < tl) return node;
    if (tl == tr) {
        return new Node{min(value, node->minval), 0, 0};
    }
    int tm = (tl + tr) / 2;
    return new Node{min(value, node->minval),
                    update(node->left, p, value, tl, tm),
                    update(node->right, p, value, tm + 1, tr)};
}

const int maxn = 1e5 + 5;

int n, root;
vector<int> graph[maxn];
int a[maxn];

Node* tree[maxn];
int depth[maxn];
int height[maxn];

void dfs1(int v, int p) {
    if (p != -1) {
        for (auto &to: graph[v]) {
            if (to == p) {
                swap(to, graph[v].back());
                break;
            }
        }
        graph[v].pop_back();
    }
    for (auto &to: graph[v]) {
        depth[to] = depth[v] + 1;
        dfs1(to, v);
        if (height[to] > height[graph[v][0]]) {
            swap(to, graph[v][0]);
        }
    }
    if (!graph[v].empty()) {
        height[v] = height[graph[v][0]] + 1;
    }
}

void dfs2(int v) {
    if (graph[v].empty()) {
        tree[v] = build();
        tree[v] = update(tree[v], depth[v], a[v]);
        return;
    }
    for (auto to: graph[v]) {
        dfs2(to);
    }
    tree[v] = tree[graph[v][0]];
    tree[v] = update(tree[v], depth[v], a[v]);
    for (auto to: graph[v]) {
        if (to == graph[v][0]) continue;
        for (int i = depth[to]; i <= depth[to] + height[to]; ++i) {
            tree[v] = update(tree[v], i, get(tree[to], i, i));
        }
    }
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> root;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs1(root, -1);
    dfs2(root);
    int m;
    cin >> m;
    int last = 0;
    for (int i = 0; i < m; ++i) {
        int v, h;
        cin >> v >> h;
        v = (v + last) % n + 1;
        h = (h + last) % n;
        last = get(tree[v], depth[v], depth[v] + min(h, height[v]));
        cout << last << '\n';
    }
}
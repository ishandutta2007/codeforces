#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5E5, M = 5E4, T = 1E7;
int n, m, q;
string s;
struct SuffixAutomaton {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int link, len;
        int next[ALPHABET_SIZE];
        Node() : link(0), len(0), next {} {}
    };
    vector<Node> t;
    SuffixAutomaton() {
        t.resize(2);
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            t[0].next[i] = 1;
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return (int)t.size() - 1;
    }
    int extend(int p, int c) {
        if (t[p].next[c] != 0) {
            int q = t[p].next[c];
            if (t[p].len + 1 == t[q].len)
                return q;
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            memcpy(t[r].next, t[q].next, ALPHABET_SIZE * sizeof(int));
            t[q].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (t[p].next[c] == 0) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        int q = t[p].next[c];
        if (t[p].len + 1 == t[q].len) {
            t[cur].link = q;
        } else {
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            memcpy(t[r].next, t[q].next, ALPHABET_SIZE * sizeof(int));
            t[q].link = t[cur].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
        }
        return cur;
    }
} sam;
struct Pair {
    int x, y;
    Pair() {}
    Pair(int x, int y) : x(x), y(y) {}
};
bool operator<(const Pair &lhs, const Pair &rhs) {return lhs.x < rhs.x || lhs.x == rhs.x && lhs.y > rhs.y;}
struct Node {
    int c[2];
    Pair mx;
} t[T];
int cnt_nodes;
int root[2 * M], parent[2 * M][16], endp[N], len[N];
vector<int> e[2 * M];
void pushup(int p) {t[p].mx = max(t[t[p].c[0]].mx, t[t[p].c[1]].mx);}
void insert(int &p, int l, int r, int x) {
    if (p == 0)
        p = ++cnt_nodes;
    if (r - l == 1) {
        t[p].mx = Pair(1, l);
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid)
        insert(t[p].c[0], l, mid, x);
    else
        insert(t[p].c[1], mid, r, x);
    pushup(p);
}
int merge(int p, int q) {
    if (p == 0)
        return q;
    if (q == 0)
        return p;
    int r = ++cnt_nodes;
    if (t[p].c[0] == 0 && t[p].c[1] == 0) {
        t[r].mx = Pair(t[p].mx.x + t[q].mx.x, t[p].mx.y);
        return r;
    }
    t[r].c[0] = merge(t[p].c[0], t[q].c[0]);
    t[r].c[1] = merge(t[p].c[1], t[q].c[1]);
    pushup(r);
    return r;
}
Pair rangeMax(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x)
        return Pair(0, m);
    if (p == 0)
        return Pair(0, x);
    if (l >= x && r <= y)
        return t[p].mx;
    int mid = (l + r) / 2;
    return max(rangeMax(t[p].c[0], l, mid, x, y), rangeMax(t[p].c[1], mid, r, x, y));
}
void dfs(int u) {
    for (int i = 1; i < 16; ++i)
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    for (int v : e[u]) {
        parent[v][0] = u;
        dfs(v);
        root[u] = merge(root[u], root[v]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = (int)s.length();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        int p = 1;
        for (int j = 0; j < (int)t.length(); ++j) {
            p = sam.extend(p, t[j] - 'a');
            insert(root[p], 0, m, i);
        }
    }
    for (int i = 2; i < (int)sam.t.size(); ++i)
        e[sam.t[i].link].push_back(i);
    dfs(1);
    int p = 1, l = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        while (sam.t[p].next[s[i] - 'a'] == 0) {
            p = sam.t[p].link;
            l = sam.t[p].len;
        }
        p = sam.t[p].next[s[i] - 'a'];
        ++l;
        endp[i] = p;
        len[i] = l;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        int p = endp[--b];
        --a;
        if (len[b] < b - a + 1) {
            cout << l << " " << 0 << "\n";
            continue;
        }
        for (int j = 15; j >= 0; --j)
            if (sam.t[parent[p][j]].len >= b - a + 1)
                p = parent[p][j];
        auto ans = rangeMax(root[p], 0, m, --l, r);
        cout << ans.y + 1 << " " << ans.x << "\n";
    }
    return 0;
}
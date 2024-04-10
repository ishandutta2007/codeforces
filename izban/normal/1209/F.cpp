#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

const int K = 2;
const int MOD[K] = {(int)1e9 + 7, 1000004233};
struct Hash {
    int a[K];

    Hash() {
        fill(a, a + K, 0);
    }

    Hash(int x) {
        fill(a, a + K, x);
    }

    Hash operator- (const Hash &h) const {
        Hash res;
        for (int i = 0; i < K; i++) {
            res.a[i] = (a[i] - h.a[i] + MOD[i]) % MOD[i];
        }
        return res;
    }

    Hash operator+ (const Hash &h) const {
        Hash res;
        for (int i = 0; i < K; i++) {
            res.a[i] = (a[i] + h.a[i]) % MOD[i];
        }
        return res;
    }

    Hash operator* (const Hash &h) const {
        Hash res;
        for (int i = 0; i < K; i++) {
            res.a[i] = (1LL * a[i] * h.a[i]) % MOD[i];
        }
        return res;
    }

    bool operator< (const Hash &h) const {
        for (int i = 0; i < K; i++) {
            if (a[i] != h.a[i]) return a[i] < h.a[i];
        }
        return 0;
    }

    bool operator== (const Hash &h) const {
        for (int i = 0; i < K; i++) {
            if (a[i] != h.a[i]) return 0;
        }
        return 1;
    }

    bool operator!= (const Hash &h) const {
        return !(*this == h);
    }
};
const Hash Q = Hash(10);
const int N = (int)1.01e6;
Hash p[N];
bool inited = 0;
void init() {
    if (inited) return;
    inited = 1;
    p[0] = Hash(1);
    for (int i = 1; i < N; i++) p[i] = p[i - 1] * Q;
}

const int INF = 1.01e9;

const int H = 19;
struct node {
    node *l, *r;
    int sz;
    Hash h;

    node() {}
    node(int x) {
        l = r = 0;
        sz = 1;
        h = Hash(x);
    }
    node(node *_l, node *_r) {
        l = _l;
        r = _r;
        sz = l->sz + r->sz;
        h = p[l->sz] * l->h + r->h;
    }
};
const int ML = 4e8;
const int NODES = ML / sizeof(node);
node nodes[NODES];
int cnode = 0;

auto zero = []() {
    node* leaf = new (nodes + cnode++) node(0);
    auto cur = leaf;
    for (int i = 0; i < H; i++) {
        cur = new (nodes + cnode++) node(cur, cur);
    }
    return cur;
}();

node* upd(node *t, int tl, int tr, int x, int y) {
    if (tl == tr) {
        return new (nodes + cnode++) node(y);
    }
    int tm = (tl + tr) >> 1;
    if (x <= tm) return new (nodes + cnode++) node(upd(t->l, tl, tm, x, y), t->r);
    return new (nodes + cnode++) node(t->l, upd(t->r, tm + 1, tr, x, y));
}

Hash get(node *t, int tl, int tr, int l, int r) {
    if (l > r) return Hash(0);
    if (l == tl && r == tr) {
        return t->h;
    }
    int tm = (tl + tr) >> 1;
    Hash left = get(t->l, tl, tm, l, min(r, tm));
    Hash right = get(t->r, tm + 1, tr, max(l, tm + 1), r);
    int cnt = max(0, r - tm);
    return right + left * p[cnt];
}

struct num {
    int len;
    node *root;

    bool operator< (const num &o) const {
        if (len != o.len) {
            return len < o.len;
        }
        auto left = root, right = o.root;
        if (left->h == right->h) {
            return 0;
        }
        for (int i = 0; i < H; i++) {
//            db(i);
//            db2(left->h.a[0], left->h.a[1]);
//            db2(right->h.a[0], right->h.a[1]);
            if (left->l->h != right->l->h) {
                left = left->l;
                right = right->l;
            } else {
                left = left->r;
                right = right->r;
            }
        }
//        db2(left->h.a[0], left->h.a[1]);
//        db2(right->h.a[0], right->h.a[1]);
        assert(left->h.a[0] != right->h.a[0]);
        return left->h.a[0] < right->h.a[0];
    }

    bool operator== (const num &o) const {
        return len == o.len && root->h == o.root->h;
    }

    num append(int x) {
        string s = to_string(x);

        num res = *this;
        for (int i = 0; i < (int)s.length(); i++) {
            res.root = upd(res.root, 0, res.root->sz - 1, res.len++, s[i] - '0');
        }
        return res;
    }

    int val() {
        return get(root, 0, root->sz - 1, 0, len - 1).a[0];
    }
};

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    init();

    int n, m;
    bool first = 1;
    while (scanf("%d%d", &n, &m) == 2) {
        if (first) first = 0;
        else printf("\n");

        vector<pair<int, int>> ed(m);
        vector<vector<int>> e(n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &ed[i].first, &ed[i].second);
            ed[i].first--;
            ed[i].second--;
            e[ed[i].first].push_back(i);
            e[ed[i].second].push_back(i);
        }

        vector<num> d(n, num({0, zero}));
        for (int i = 1; i < n; i++) {
            d[i].len = 1e9;
        }

        priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> q;
        q.push({d[0], 0});
        while (!q.empty()) {
            auto o = q.top();
            q.pop();
            int v = o.second;
            if (!(d[v] == o.first)) {
                continue;
            }
            for (auto id : e[v]) {
                num nd = d[v].append(id + 1);
                int to = ed[id].first ^ ed[id].second ^ v;
                if (nd < d[to]) {
                    d[to] = nd;
                    q.push({d[to], to});
                }
            }
        }
        for (int i = 1; i < n; i++) printf("%d\n", d[i].val());
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}
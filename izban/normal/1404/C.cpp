#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double dbl;

template<typename Util>
struct segtree_fast {
    int n, h;
    vector<typename Util::data> t;
    vector<typename Util::update> p;

    segtree_fast() = default;
    explicit segtree_fast(int _n, const typename Util::data &val) {
        n = _n;
        h = __builtin_clz(1) - __builtin_clz(n);
        p.assign(2 * n, Util::NEUTRAL_UPDATE);
        t.assign(2 * n, val);
    }
    explicit segtree_fast(vector<typename Util::data> a) {
        n = a.size();
        h = __builtin_clz(1) - __builtin_clz(n);
        p.assign(2 * n, Util::NEUTRAL_UPDATE);
        t.assign(2 * n, Util::NEUTRAL_DATA);
        copy(a.begin(), a.end(), t.begin() + n);
        for (int i = n - 1; i > 0; i--) {
            t[i] = Util::combine(t[i * 2], t[i * 2 + 1]);
        }
    }

    void update_vertex(int v, const typename Util::update &x) {
        Util::update_vertex(t[v], x);
        if (v < n) {
            p[v] = Util::merge_updates(p[v], x);
        }
    }

    void push_updates_to(int v) {
        for (int s = h; s > 0; s--) {
            int cur = v >> s;
            if (p[cur] != Util::NEUTRAL_UPDATE) {
                update_vertex(cur * 2, p[cur]);
                update_vertex(cur * 2 + 1, p[cur]);
                p[cur] = Util::NEUTRAL_UPDATE;
            }
        }
    }

    void recalc_path(int v) {
        while (v > 1) {
            v >>= 1;
            t[v] = Util::combine(t[v * 2], t[v * 2 + 1]);
            Util::update_vertex(t[v], p[v]);
        }
    }

    typename Util::data get(int l, int r) {
        if (l > r) return Util::NEUTRAL_DATA;
        l += n; r += n;
        push_updates_to(l);
        push_updates_to(r);

        auto res_left = Util::NEUTRAL_DATA;
        auto res_right = Util::NEUTRAL_DATA;
        while (l <= r) {
            if (l & 1) {
                res_left = Util::combine(res_left, t[l++]);
            }
            if (!(r & 1)) {
                res_right = Util::combine(t[r--], res_right);
            }
            l >>= 1;
            r >>= 1;
        }
        return Util::combine(res_left, res_right);
    }

    void upd(int ql, int qr, const typename Util::update &x) {
        if (ql > qr) return;
        ql += n; qr += n;
        int l = ql, r = qr;

        push_updates_to(l);
        push_updates_to(r);
        while (l <= r) {
            if (l & 1) {
                update_vertex(l++, x);
            }
            if (!(r & 1)) {
                update_vertex(r--, x);
            }
            l >>= 1;
            r >>= 1;
        }
        recalc_path(ql);
        recalc_path(qr);
    }
};

template<typename Util>
struct segtree_rec {
    int n;
    vector<typename Util::data> a, t;
    vector<typename Util::update> p;

    explicit segtree_rec(int _n, const typename Util::data &val) {
        n = _n;
        int N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, val);
        p.assign(2 * N, Util::NEUTRAL_UPDATE);
    }
    explicit segtree_rec(const vector<typename Util::data> &_a) {
        a = _a;
        n = a.size();
        int N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, Util::NEUTRAL_DATA);
        p.assign(2 * N, Util::NEUTRAL_UPDATE);
        build(1, 0, n - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = Util::combine(t[v * 2], t[v * 2 + 1]);
    }

    void update_vertex(int v, const typename Util::update &x) {
        Util::update_vertex(t[v], x);
        p[v] = Util::merge_updates(p[v], x);
    }

    void push(int v) {
        if (p[v] != Util::NEUTRAL_UPDATE) {
            update_vertex(v * 2, p[v]);
            update_vertex(v * 2 + 1, p[v]);
            p[v] = Util::NEUTRAL_UPDATE;
        }
    }

    typename Util::data get(int v, int tl, int tr, int l, int r) {
        if (l > r) return Util::NEUTRAL_DATA;
        if (l == tl && r == tr) return t[v];
        push(v);
        int tm = (tl + tr) >> 1;
        return Util::combine(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    typename Util::data get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }

    void upd(int v, int tl, int tr, int l, int r, const typename Util::update &x) {
        if (l > r) return;
        if (l == tl && r == tr) {
            update_vertex(v, x);
            return;
        }
        push(v);
        int tm = (tl + tr) >> 1;
        upd(v * 2, tl, tm, l, min(r, tm), x);
        upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = Util::combine(t[v * 2], t[v * 2 + 1]);
    }

    void upd(int l, int r, const typename Util::update &x) {
        upd(1, 0, n - 1, l, r, x);
    }
};

struct Data {
    using data = pair<int, int>;
    using update = int;

    static constexpr data NEUTRAL_DATA = {numeric_limits<int>::max(), -1};
    static constexpr update NEUTRAL_UPDATE = 0;

    static data combine(const data &left, const data &right) {
        return min(left, right);
    }

    static void update_vertex(data &value, const update &upd) {
        value.first += upd;
    }

    static update merge_updates(const update &old, const update &nw) {
        return old + nw;
    }
};

void print(vector<int> a) {
    for (int x : a) {
        printf("%d\n", x);
    }
}

template <typename T>
struct fenwick {
    int n;
    vector<T> f;

    fenwick() {}

    fenwick(int N) {
        n = N;
        f.assign(N, T(0));
    }

    fenwick(vector<T> a) {
        n = a.size();
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int x, T y) {
        for (; x < n; x |= x + 1) f[x] += y;
    }

    T get(int x) {
        T res(0);
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    // return min i: sum(0, i) > x
    int upper_bound(T x) {
        int k = 1;
        while (2 * k <= n) k *= 2;

        int res = 0;
        while (k > 0) {
            if (f[res + k - 1] <= x) {
                x -= f[res + k - 1];
                res += k;
            }
            k /= 2;
        }
        return res;
    }
};


vector<int> solve(vector<int> a, vector<pair<int, int>> b) {
    int n = a.size();
    int q = b.size();
    vector<int> ans(q, -1);
    vector<vector<int>> vct(n);
    for (int i = 0; i < q; i++) {
        vct[b[i].first].push_back(i);
    }

    const int INF = 1e9;
    vector<pair<int, int>> aa(n);
    for (int i= 0 ; i < n; i++) aa[i] = {INF, -i};
    segtree_rec<Data> tr(aa);
    fenwick<int> f(n);

    for (int i = n - 1; i >= 0; i--) {
//        int val = a[i] - (i + 1);
        int val = (i + 1) - a[i];
        if (val < 0) val = INF;
        tr.upd(i, i, -INF + val);

        while (1) {
            auto o = tr.get(0, n - 1);
            assert(o.first >= 0);
            if (o.first != 0) break;
            int j = -o.second;
            tr.upd(j, j, +INF);
            tr.upd(j, n - 1, -1);
            f.add(j, +1);
//            db(j);
        }
        for (int id : vct[i]) {
            ans[id] = f.get(0, n - 1 - b[id].second);
        }
    }
    return  ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        vector<int> a(n);
        vector<pair<int, int>> b(q);
        for  (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for  (int i = 0; i < q; i++) scanf("%d%d", &b[i].first, &b[i].second);

        print(solve(a, b));
    }

    return 0;
}
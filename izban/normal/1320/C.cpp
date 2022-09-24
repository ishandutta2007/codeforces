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
typedef long double ld;

struct monster {
    int x, y, z;
};
/*
struct segtree {
    struct data {
        int sum;
        int max_pref;
    };

    data combine(data a, data b) {

    }

    int n;
    vector<data> t;

    explicit segtree(int _n) {
        n = _n;
        int N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, {0, 0});
    }

    data get(int v, int tl, int tr, int l, int r) {
        if (l > r) return {0, 0};
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) >> 1;
        return combine(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    int get(int l, int r) {
        return 0;
    }

    void upd(int v, int tl, int tr, int x, int add) {
        assert(0);
    }

    void upd(int x, int add) {
        upd(1, 0, n - 1, x, add);
    }
};
*/

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

    static constexpr data NEUTRAL_DATA = {numeric_limits<int>::min(), -1};
    static constexpr update NEUTRAL_UPDATE = 0;

    static data combine(const data &left, const data &right) {
        return max(left, right);
    }

    static void update_vertex(data &value, const update &upd) {
        value.first += upd;
    }

    static update merge_updates(const update &old, const update &nw) {
        return old + nw;
    }
};
using segtree = segtree_rec<Data>;

const int INF = 1e9;
int solve(vector<pair<int, int>> a, vector<pair<int, int>> b, vector<monster> c) {
    auto norm = [](vector<pair<int, int>> &x) {
        vector<pair<int, int>> xx;
        sort(x.begin(), x.end(), [](const pair<int, int> &x1, const pair<int, int> &x2) {
            if (x1.first != x2.first) return x1.first < x2.first;
            return x1.second > x2.second;
        });
        for (auto o : x) {
            while (!xx.empty() && xx.back().second >= o.second) {
                xx.pop_back();
            }
            xx.push_back(o);
        }
        x = xx;
    };
    norm(a);
    norm(b);

    for (auto &o : a) o.first--;
    for (auto &o : b) o.first--;

    enum type {
        add_monster = 0,
        add_weapon = 1
    };
    struct event {
        int x;
        type t;
        int id;
        bool operator< (const event &ev) const {
            if (x != ev.x) return x < ev.x;
            return t < ev.t;
        }
    };
    vector<event> ev;
    for (int i = 0; i < (int)b.size(); i++) {
        ev.push_back({b[i].first, add_weapon, i});
    }
    for (int i = 0; i < (int)c.size(); i++) {
        ev.push_back({c[i].y, add_monster, i});
    }
    sort(ev.begin(), ev.end());

    vector<int> xx;
    for (auto o : a) {
        xx.push_back(o.first);
    }
    for (auto o : c) {
        xx.push_back(o.x);
    }
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    for (auto &o : a) {
        o.first = lower_bound(xx.begin(), xx.end(), o.first) - xx.begin();
    }
    for (auto &o : c) {
        o.x = lower_bound(xx.begin(), xx.end(), o.x) - xx.begin();
    }

    int m = xx.size();
    segtree tr(m, {0, 0});

    auto print = [&]() {
        for (int i = 0; i < m; i++) {
            int x = tr.get(i, i).first;
            cout << x << " ";
        }
        cout << endl;
    };

    int mn = INF;
    int mx = -INF;
    int last = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int fr = 0;
        if (i > 0) fr = a[i - 1].first + 1;

        tr.upd(fr, m - 1, -(a[i].second - last));
        last = a[i].second;
        mn = min(mn, a[i].first);
        mx = max(mx, a[i].first);
    };

    int ans = -2e9;
    int cur_cost = -1;
    for (auto o : ev) {
        if (o.t == add_monster) {
            tr.upd(c[o.id].x, m - 1, +c[o.id].z);
        } else {
            cur_cost = b[o.id].second;
            ans = max(ans, tr.get(mn, mx).first - cur_cost);
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m, p;
    while (scanf("%d%d%d", &n, &m, &p) == 3) {
        vector<pair<int, int>> a(n), b(m);
        vector<monster> c(p);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &b[i].first, &b[i].second);
        }
        for (int i = 0; i < p; i++) {
            scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].z);
        }

        cout << solve(a, b, c) << endl;
    }

    return 0;
}
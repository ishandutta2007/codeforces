#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = (int)1.01e9;

template <typename T>
struct segtree {
    int N;
    vector<T> t;
    T zero;
    function<T(T, T)> f;

    segtree() {}
    void init(int n, T _zero, function<T(T, T)> _f) {
        f = _f;
        zero = _zero;
        N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, zero);
    }
    segtree(int n, T _zero, function<T(T, T)> _f) {
        init(n, _zero, _f);
    }
    segtree(vector<T> &a, T _zero, function<T(T, T)> _f) {
        int n = a.size();
        init(n, _zero, _f);
        
        for (int i = 0; i < n; i++) t[N + i] = a[i];
        for (int i = N - 1; i > 0; i--) {
            t[i] = f(t[i * 2], t[i * 2 + 1]);
        }
    }

    T get(int l, int r) {
        T res = zero;
        l += N;
        r += N;
        while (l <= r) {
            if (l % 2 == 1) res = f(res, t[l]);
            if (r % 2 == 0) res = f(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    void upd(int x, T y) {
        x += N;
        t[x] = y;
        while (x > 1) {
            x >>= 1;
            t[x] = f(t[x * 2], t[x * 2 + 1]);     
        }
    }
};

struct segtree2 {
    int n;
    vector<pair<ll, int> > a;
    vector<pair<ll, int> > t;
    vector<ll> p;

    segtree2(vector<pair<ll, int> > _a) {
        a = _a;
        int N = 1;
        n = a.size();
        while (N < n) N <<= 1;
        t.resize(2 * N);
        p.assign(2 * N, 0);
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
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }

    void push(int v, int tl, int tr) {
        if (p[v]) {
            if (tl != tr) {
                p[v * 2] += p[v];
                p[v * 2 + 1] += p[v];
            }
            t[v].first += p[v];
            p[v] = 0;
        }
    }

    void add(int v, int tl, int tr, int l, int r, ll x) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            p[v] += x;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) >> 1;
        add(v * 2, tl, tm, l, min(r, tm), x);
        add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }

    void add(int l, int r, ll x) {
        add(1, 0, n - 1, l, r, x);
    }

    pair<ll, int> get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return make_pair((ll)4e18, -1);
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) >> 1;
        return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    pair<ll, int> get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
    
    pair<ll, int> get() {
        return t[1];
    }
};

int fast(vector<int> a, vector<pair<int, int> > b) {
    int n = a.size();
    //int m = b.size();
    sort(b.begin(), b.end());

    vector<int> mx(n + 1);
    mx[n] = 0;
    for (int i = n - 1; i >= 0; i--) mx[i] = max(mx[i + 1], a[i]);

    int last = INF;
    ll curSum = 0;

    vector<pair<int, int> > cost;
    vector<pair<ll, int> > have;
    vector<int> frst;
    cost.push_back({INF, -1});
    have.push_back({0, -1});
    frst.push_back(0);
    for (int i = 0; i < n; i++) {
        curSum += a[i];
        if (a[i] == mx[i] && last > a[i]) {
            int pp = cost.size();

            int j = lower_bound(b.begin(), b.end(), make_pair(a[i] + 1, -1)) - b.begin() - 1;
            while (j >= 0 && b[j].first > mx[i + 1]) {
                if (curSum >= b[j].second) {
                    cost.push_back({b[j].second, frst.size()});
                    have.push_back({curSum - b[j].second, frst.size()});
                    frst.push_back(pp);
                }
                j--;
            }
        }
    }
    /*for (auto o : cost) cout << o.first << " "; cout << endl;
    for (auto o : have) cout << o.first << " "; cout << endl;
    for (auto o : frst) cout << o << " "; cout << endl;*/

    int s = cost.size();
    segtree<pair<int, int> > t1(cost, make_pair(INF, -1), [&](pair<int, int> x, pair<int, int> y) {
        return min(x, y);
    });
    segtree2 t2(have);
    
    vector<pair<ll, int> > oo;
    for (int i = 0; i < s; i++) oo.push_back({(ll)4e18, i});
    segtree2 t3(oo);

    int ans = 0;
    while (1) {
        auto o = t1.get(0, s - 1);
        if (o.first == INF) break;
        int id = o.second;
        ///cerr << "dem " << id << endl;
        t1.upd(id, make_pair(INF, -1));

        auto tmp = t3.get(1, 0, s - 1, frst[id], s - 1).first;
        if (tmp >= cost[id].first) {
            ans++;
            t2.add(frst[id], s - 1, -cost[id].first);
            t3.add(id, id, t2.get(id, id).first - t3.get(id, id).first + 2 * cost[id].first);
            t3.add(frst[id], s - 1, -cost[id].first);
        }
        while (t2.get().first < 0) {
            int cid = t2.get().second;
            //cerr << "cant " << cid << endl;
            t1.upd(cid, make_pair(INF, -1));
            t2.add(cid, cid, (ll)4e18);
        }
    }
    return ans;
}

int slow(vector<int> a, vector<pair<int, int> > b) {
    int n = a.size(), m = b.size();
    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    int ans = 0;
    do {
        int cur = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            while (cur < m && b[p[cur]].first <= a[i] && sum >= b[p[cur]].second) {
                sum -= b[p[cur]].second;
                cur++;
            }
        } 
        ans = max(ans, cur);
    } while (next_permutation(p.begin(), p.end()));
    return ans;
}

void stress() {
    for (int it = 275;; it++) {
        cerr << it << endl;
        srand(it);

        int C = rand() % 100 + 1;
        int n = rand() % 8 + 1;
        int m = rand() % 8 + 1;
        vector<int> a(n);
        vector<pair<int, int> > b(m);
        for (int i = 0; i < n; i++) {
            a[i] = rand() % C + 1;
        }
        for (int i = 0; i < m; i++) {
            b[i].first = rand() % C + 1;
            b[i].second = rand() % C + 1;
        }

        auto ans1 = fast(a, b);
        auto ans2 = slow(a, b);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << " " << m << endl;
            for (int x : a) cout << x << " "; cout << endl;
            for (auto o : b) cout << o.first << " "; cout << endl;
            for (auto o : b) cout << o.second << " "; cout << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(n);
        vector<pair<int, int> > b(m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i].first);
        for (int i = 0; i < m; i++) scanf("%d", &b[i].second);

        cout << fast(a, b) << endl;
    }
    
    return 0;
}
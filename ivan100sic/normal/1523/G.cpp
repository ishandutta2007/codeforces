// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int>
struct fractional_cascading {
    int maxn;
    vector<vector<T>> a;
    vector<vector<int>> pl, pr;

    fractional_cascading(const vector<vector<T>>& b) {
        int n = b.size();
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.resize(2*maxn);
        copy(b.begin(), b.end(), a.begin() + maxn);
        build();
    }

    fractional_cascading(const vector<pair<int, T>>& b) {
        int n = 1;
        maxn = 1;
        for (const auto& [k, v] : b)
            n = max(n, k+1);
        while (maxn < n)
            maxn <<= 1;
        a.resize(2*maxn);
        for (const auto& [k, v] : b)
            a[k + maxn].push_back(v);
        build();
    }

    void build() {
        pl.resize(maxn);
        pr.resize(maxn);
        for (int i=0; i<maxn; i++)
            sort(begin(a[i+maxn]), end(a[i+maxn]));
        for (int i=maxn-1; i; i--) {
            size_t sl = 0, sr = 0, si = 0, q = a[2*i].size() + a[2*i+1].size();
            pl[i].resize(q+1);
            pr[i].resize(q+1);
            a[i].resize(q);
            while (si < q) {
                int r;
                if (sr == a[2*i+1].size()) r = 0;
                else if (sl == a[2*i].size()) r = 1;
                else r = a[2*i+1][sr] < a[2*i][sl];
                a[i][si++] = a[2*i+r][(r ? sr : sl)++];
                pl[i][si] = sl;
                pr[i][si] = sr;
            }
        }
    }

    template<class F>
    void get(int l, int r, F f, int x, int xl, int xr, int yl, int yr) const {
        if (r <= xl || xr <= l || yl == yr)
            return;
        if (l <= xl && xr <= r)
            return f(x, yl, yr);
        int xm = (xl+xr) >> 1;
        get(l, r, f, 2*x, xl, xm, pl[x][yl], pl[x][yr]);
        get(l, r, f, 2*x+1, xm, xr, pr[x][yl], pr[x][yr]);
    }

    template<class F>
    void operator() (int l, int r, const T& lo, const T& hi, F f) const {
        int yl = lower_bound(begin(a[1]), end(a[1]), lo) - begin(a[1]);
        int yr = lower_bound(begin(a[1]), end(a[1]), hi) - begin(a[1]);
        get(l, r, f, 1, 0, maxn, yl, yr);
    }
};

struct minint {
    int x = 2e9;

    minint operator+ (const minint& b) const {
        return { min(x, b.x) };
    }
};

template<class T = int, class F = plus<T>>
struct sparse_table {
    vector<vector<T>> d;
    T e;
    F f;

    sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
        d.push_back(a);
        int n = a.size();
        for (int h=1; h*2<=n; h<<=1) {
            int m = a.size() - h;
            vector<T> b(m);
            for (int i=0; i<m; i++)
                b[i] = f(a[i], a[i+h]);
            d.push_back(b);
            swap(a, b);
        }
    }

    T operator() (int l, int r) const {
        if (l >= r) return e;
        int i = 31 - __builtin_clz(r-l);
        return f(d[i][l], d[i][r-(1<<i)]);
    }
};

struct segment_table : fractional_cascading<pair<int, int>> {
    using base = fractional_cascading<pair<int, int>>;
    vector<sparse_table<minint>> t;

    static vector<pair<int, pair<int, int>>> indices(const vector<pair<int, int>>& b) {
        vector<pair<int, pair<int, int>>> c(b.size());
        for (size_t i=0; i<b.size(); i++) {
            c[i] = {b[i].first, {b[i].second, i}};
        }
        return c;
    }

    segment_table(const vector<pair<int, int>>& arg) : base(indices(arg)) {
        t.reserve(2*maxn);
        t.emplace_back(vector<minint>{});
        for (int i=1; i<2*maxn; i++) {
            vector<minint> vi(a[i].size());
            for (size_t j=0; j<vi.size(); j++) {
                vi[j].x = a[i][j].second;
            }
            t.emplace_back(vi);
        }
    }

    int operator() (int xl, int xr, int yl, int yr) const {
        minint ans;
        base::operator()(xl, xr, {yl, -1}, {yr, -1}, [&, this](int x, int tl, int tr) {
            ans = ans + t[x](tl, tr);
        });
        return ans.x;
    }
};

template<class T = int, class F = plus<T>>
struct fenwick {
    vector<T> a;
    T e;
    F f;

    fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

    void add(int p, const T& v) {
        for (p++; p <= (int)a.size(); p += p & -p)
            a[p-1] = f(a[p-1], v);
    }

    T operator() (int p) const {
        T v = e;
        for (; p; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a_orto(m), a_romb1(m), a_romb2(m);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        a_orto[i] = {x, y};
        a_romb1[i] = {x, y-x};
        a_romb2[i] = {y-x, y};
    }

    segment_table orto(a_orto);
    segment_table romb1(a_romb1);
    segment_table romb2(a_romb2);

    auto st = [&](int l, int r, int w) {
        int z = 1e9;
        if (w > r-l) return z;

        int d = (r-l)-w;
        int dl = d / 2;

        z = min(z, orto(l, l+dl+1, r-dl, r+1));
        z = min(z, romb1(l, l+dl+1, w, w+dl+1));
        z = min(z, romb2(w, w+dl+1, r-dl, r+1));

        return z;
    };

    int h = min(n, 20);
    for (int w=1; w<=h; w++) {
        fenwick<unsigned short> ft(n+1);
        int cnt = 0;
        for (auto [l, r] : a_orto) {
            if (r-l < w) continue;
            if (ft(r) == ft(l)) {
                cnt += r-l;
                for (int x=l; x<r; x++) {
                    ft.add(x, 1);
                }
            }
        }
        cout << cnt << '\n';
    }

    for (int w=h+1; w<=n; w++) {
        set<tuple<int, int, int>> s;

        auto ubaci = [&](int l, int r) {
            int id = st(l, r, w);
            if (id <= m) {
                s.insert({id, l, r});
            }
        };

        ubaci(0, n);

        int cnt = 0;
        while (s.size()) {
            auto [id, el, er] = *s.begin();
            s.erase(s.begin());
            // uzmi taj segment

            auto [sl, sr] = a_orto[id];
            cnt += sr - sl;
            ubaci(el, sl);
            ubaci(sr, er);
        }

        cout << cnt << '\n';
    }

}
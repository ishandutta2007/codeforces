// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = int, class F = plus<T>>
struct segtree {
    int maxn;
    vector<T> a;
    T e;
    F f;

    segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.assign(2*maxn, v);
        for (int i=maxn-1; i; i--)
            a[i] = f(a[2*i], a[2*i+1]);
    }

    void add(int p, const T& v) {
        p += maxn;
        a[p] = f(a[p], v);
        for (p >>= 1; p; p >>= 1)
            a[p] = f(a[2*p], a[2*p+1]);
    }

    void set(int p, const T& v) {
        p += maxn;
        a[p] = v;
        for (p >>= 1; p; p >>= 1)
            a[p] = f(a[2*p], a[2*p+1]);
    }

    T get(int l, int r, int x, int xl, int xr) const {
        if (r <= xl || xr <= l)
            return e;
        if (l <= xl && xr <= r)
            return a[x];
        int xm = (xl+xr) >> 1;
        return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
    }

    T operator() (int l, int r) const {
        return get(l, r, 1, 0, maxn);
    }
};

const int inf = 1e9;

int table[14][14];

void compute_transitions() {
    map<array<int, 3>, string> mp;

    auto run = [&](const string& b) {
        array<int, 3> u = {0, 1, 2};
        for (char c : b) {
            for (int& x : u) {
                if (x == c - 'a') {
                    x++;
                }
            }
        }
        return u;
    };

    for (int len = 6; len >= 0; len--) {
        for (int x = 0; x < (int)pow(3, len); x++) {
            string s(len, 0);
            for (int i=0, t=x; i<len; i++) {
                s[i] = t % 3 + 'a';
                t /= 3;
            }

            mp[run(s)] = s;            
        }
    }

    vector v(mp.begin(), mp.end());

    // for (int i : ra(0, 14)) {
    //     cerr << v[i].second << '\n';
    // }

    for (int i : ra(0, 14)) {
        for (int j : ra(0, 14)) {
            table[i][j] = R::find(v, *mp.find(run(v[i].second + v[j].second))) - v.begin();
            // cerr << table[i][j] << " \n"[j == 13];
        }
    }
}

void mn(int& x, int y) {
    x = min(x, y);
}

struct thing {
    int a[14];

    void allinf() {
        R::fill(a, inf);
    }

    void clamp() {
        for (int& x : a) x = min(x, inf);
    }

    thing() {
        allinf();
        a[0] = 0;
    }

    thing(char ch) {
        allinf();
        a[1] = a[2] = a[5] = 1;
        if (ch == 'a') a[5] = 0;
        if (ch == 'b') a[2] = 0;
        if (ch == 'c') a[1] = 0;
    }

    thing operator+ (const thing& o) const {
        thing r;
        r.a[0] = inf;
        for (int i : ra(0, 14)) {
            for (int j : ra(0, 14)) {
                mn(r.a[table[i][j]], a[i] + o.a[j]);
            }
        }
        r.clamp();
        return r;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    compute_transitions();

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    segtree<thing> st(n);
    for (int i : ra(0, n)) {
        st.set(i, s[i]);
    }

    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        st.set(p, c);
        auto rez = st.a[1];
        cout << *min_element(rez.a, rez.a + 13) << '\n';
    }
}
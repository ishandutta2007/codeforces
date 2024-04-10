// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

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

auto segtree_min = segtree(300005, make_pair(123123123, 0), [](auto p, auto q) { return min(p, q); }, make_pair(123123123, 0));

int n;
int a[300005];
int b[300005], bb;
basic_string<int> e[300005];

ll invs = 0;
fenwick fw(300005);

ll movs[300005], sz[300005];

int dr[300005];

void dfs1(int x) {
    sz[x] = 1;
    invs += fw(300005) - fw(a[x]);
    fw.add(a[x], 1);
    for (int y : e[x]) {
        dfs1(y);
        sz[x] += sz[y];
        movs[x] += movs[y];
    }
    movs[x] += sz[x] - 1;
    fw.add(a[x], -1);
}

int dub[300005], postnum, parent[300005];

// deca: [b, dr]
void dfs2(int x) {
    b[x] = ++bb;
    sort(begin(e[x]), end(e[x]), [&](int i, int j) { return a[i] < a[j]; });
    for (int y : e[x]) {
        dub[y] = dub[x] + 1;
        parent[y] = x;
        dfs2(y);
    }
    dr[x] = bb;
    ++postnum;
    segtree_min.set(b[x], {postnum, x});
}

int c[300005], cc;

void dfs3(int x, ll invs) {
    while (1) {
        auto st = segtree_min(b[x], dr[x]+1);
        if (st.first == 123123123) {
            // nema vise slobodnih cvorova, izadji
            return;
        }

        int yy = st.second;
        int raz = dub[yy] - dub[x];
        if (invs >= raz) {
            invs -= raz;
            c[yy] = ++cc;
            segtree_min.set(b[yy], {123123123, 0});
        } else {
            // naredjaj do dole
            if (c[x] == 0) {
                c[x] = ++cc;
                segtree_min.set(b[x], {123123123, 0});
            }

            for (int y : e[x]) {
                dfs3(y, 0);
            }

            if (invs > 0) {
                vector<int> seq;
                for (int t=yy; t!=x; t=parent[t]) {
                    seq.push_back(t);
                }
                seq.push_back(x);
                reverse(begin(seq), end(seq));

                for (ll i=0; i<invs; i++) {
                    swap(c[seq[i]], c[seq[i+1]]);
                }
            }

            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        e[u] += v;
    }

    dfs1(1);
    dfs2(1);
    dfs3(1, invs);

    // for (int i=1; i<=n; i++) {
    //     cerr << c[i] << " \n"[i == n];
    // }

    // provera
    if (equal(a+1, a+n+1, c+1)) {
        cout << "YES\n" << invs << '\n';
        for (int i=1; i<=n; i++) {
            cout << b[i] << " \n"[i == n];
        }
    } else {
        cout << "NO\n";
    }
}
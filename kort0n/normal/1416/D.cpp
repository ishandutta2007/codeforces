#include <bits/stdc++.h>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

l_l op(l_l a, l_l b) {
    return max(a, b);
}

l_l e() {return {-1, -1};}
using segtree = atcoder::segtree<l_l, op, e>;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};

ll N, M, Q;
ll p[201000];
vector<ll> vertex[201000];
ll a[501000], b[501000];
ll u[301000], v[301000];

void merge(int q, int w) {
    if(vertex[q].size() < vertex[w].size()) {
        swap(vertex[q], vertex[w]);
    }
    for(auto tmp : vertex[w]) {
        vertex[q].push_back(tmp);
    }
    vertex[w].clear();
}

ll L[501000], R[501000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    for(int i = 0; i < N; i++) cin >> p[i];
    set<ll> st;
    for(int i = 0; i < N; i++) {
        vertex[i].push_back(i);
    }
    for(int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        st.insert(i);
    }
    for(int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i];
        b[i]--;
        if(a[i] == 2) st.erase(b[i]);
    }
    UnionFind uni(N);
    for(auto tmp : st) {
        ll q = uni.root(u[tmp]);
        ll w = uni.root(v[tmp]);
        if(uni.merge(q, w)) {
            merge(q, w);
        }
    }
    for(int q = Q - 1; q >= 0; q--) {
        if(a[q] == 2) {
            ll tmp = b[q];
            ll q = uni.root(u[tmp]);
            ll w = uni.root(v[tmp]);
            if(uni.merge(q, w)) {
                merge(q, w);
            }
        } else {
            ll v = uni.root(b[q]);
            //cerr << v << endl;
            L[q] = vertex[v][0];
            R[q] = vertex[v].back();
        }
    }
    ll root = uni.root(0);
    for(int i = 0; i < N; i++) {
        if(uni.root(i) != i) continue;
        if(i == root) continue;
        uni.merge(root, i);
        merge(root, i);
    }
    /*
    for(auto tmp : vertex[root]) {
        cerr << tmp << " ";
    }
    cerr << endl;
    */
    vector<ll> inv(N);
    for(int i = 0; i < N; i++) {
        inv[vertex[root][i]] = i;
    }
    for(int q = 0; q < Q; q++) {
        if(a[q] == 2) continue;
        L[q] = inv[L[q]];
        R[q] = inv[R[q]] + 1;
        //cerr << q << " " << L[q] << " " << R[q] << endl;
    }
    vector<l_l> A(N);
    for(int i = 0; i < N; i++) {
        A[i].first = p[vertex[root][i]];
        A[i].second = i;
    }
    segtree seg(A);
    for(int q = 0; q < Q; q++) {
        if(a[q] == 2) continue;
        l_l tmp = seg.prod(L[q], R[q]);
        cout << tmp.first << endl;
        seg.set(tmp.second, {0, tmp.second});
    }
    return 0;
}
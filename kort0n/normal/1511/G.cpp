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

const long long INF = 1e18;
//const ll mod = 1000000007;
int N, Q;
int num[201000];
int L[201000], R[201000];
int M;
char ans[201000];
vector<int> query[201000];
const int C = 9;
vector<ll> idx[(1 << C)];
int op(int a, int b) {return a ^ b;}
int e() {return 0;}
using segtree = atcoder::segtree<int, op, e>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int c;
        cin >> c;
        num[c] = 1 - num[c];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> L[i] >> R[i];
        query[L[i]].push_back(i);
    }
    vector<int> a(M + 5, 0);
    segtree seg(a);
    for(int t = M; t >= 1; t--) {
        if(num[t] == 1) {
            idx[t%(1 << C)].push_back(M - t);
            //cerr << "added: " << t << endl;
        }
        for(int bit = C; bit < 18; bit++) {
            for(int i = t + (1 << bit); i <= M; i += (1 << bit)) {
                if(num[i] == 1) {
                    auto val = seg.get(i);
                    val ^= (1 << bit);
                    seg.set(i, val);
                }
            }
        }
        for(auto q : query[t]) {
            //cerr << "----------" << q << "---------" << endl;
            ll XOR = seg.prod(L[q], R[q] + 1);
            for(int bits = 0; bits < (1 << C); bits++) {
                if(idx[bits].empty()) continue;
                auto itr = lower_bound(idx[bits].begin(), idx[bits].end(), M - R[q]);
                if(((int)(idx[bits].end() - itr)) & 1) {
                    //cerr << bits << endl;
                    XOR ^= ((bits - (t % (1 << C))) + (1 << C)) % (1 << C);
                }
            }
            if(XOR == 0) ans[q] = 'B';
            else ans[q] = 'A';
        }
    }
    for(int q = 0; q < Q; q++) cout << ans[q];
    cout << endl;
    return 0;
}
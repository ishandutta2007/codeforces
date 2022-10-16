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
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

//#define endl "\n"
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
l_l SUM(l_l a, l_l b) {
    return {a.first + b.first, a.second + b.second};
}
l_l SUMe() {
    return {0, 0};
}
l_l SUMmapping(ll f, l_l a) {
    return {a.first + a.second * f, a.second};
}
ll SUMcomposition(ll l, ll r) {
    return l + r;
}
ll SUMid() {
    return 0;
}
ll N, Q;
map<ll, l_l> mp;
typedef atcoder::lazy_segtree<l_l, SUM, SUMe, ll, SUMmapping, SUMcomposition, SUMid> segtree;
segtree seg;
void ADD(ll val, l_l interval) {
    if(mp.count(val) == 0) {
        mp[val] = interval;
        return;
    }
    if(mp[val].first == interval.second) {
        mp[val] = {interval.first, mp[val].second};
    } else if(mp[val].second == interval.first) {
        mp[val] = {mp[val].first, interval.second};
    } else {
        assert(0);
    }
}
void DEL(ll val, l_l interval) {
    assert(mp.count(val) >= 1);
    if(mp[val] == interval) {
        mp.erase(val);
        return;
    }
    l_l a = mp[val];
    l_l b = interval;
    if(a.first == b.first) {
        if(a.second > b.second) {
            swap(a, b);
        }
        mp[val] = {a.second, b.second};
        return;
    }
    if(a.second == b.second) {
        if(a.first > b.first) {
            swap(a, b);
        }
        mp[val] = {a.first, b.first};
        return;
    }
    assert(0);
}
void update() {
    ll x, y;
    cin >> x >> y;
    ll L = x;
    ll R = x;
    while(true) {
        auto itr = mp.lower_bound(y);
        if(itr == mp.begin()) break;
        itr--;
        ll nowl = itr->second.first;
        ll nowr = itr->second.second;
        ll delta = y - itr->first;
        ll beforeval = itr->first;
        //cerr << nowl << " " << nowr << " " << beforeval << endl;
        chmin(L, nowl);
        chmin(nowr, x);
        if(nowl >= nowr) break;
        DEL(beforeval, {nowl, nowr});
        seg.apply(nowl, nowr, delta);
    }
    if(L != R) {
        ADD(y, {L, R});
    }
}
ll rest;
bool F(l_l x) {
    return x.first <= rest;
}
void query() {
    ll x, y;
    cin >> x >> y;
    x--;
    rest = y;
    ll ans = 0;
    //cerr << "-----------" << endl;
    while(true) {
        auto itr = mp.upper_bound(rest);
        if(itr == mp.begin()) break;
        itr--;
        ll now = itr->second.first;
        chmax(now, x);
        ll r = seg.max_right<F>(now);
        //cerr << now << " " << rest << " " << r << endl;
        ans += r - now;
        rest -= seg.prod(now, r).first;
        if(r == N) break;
    }
    cout << ans << endl;
}
void print() {
    for(int i = 0; i < N; i++) {
        cout << seg.prod(i, i + 1).first << " ";
    }
    cout << endl;
}
int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    cin >> N >> Q;
    vector<l_l> a(N);
    for(int i = 0; i < N; i++) {
        ll val;
        cin >> val;
        a[i].first = val;
        a[i].second = 1;
        ADD(val, {i, i + 1});
    }
    seg = segtree(a);
    for(int q = 0; q < Q; q++) {
        ll t;
        cin >> t;
        if(t == 1) update();
        else query();
        //print();
    }
    return 0;
}
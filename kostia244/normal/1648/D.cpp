// Problem: D. Serious Business
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1648/problem/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>

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

#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const ll inf = 1ll<<60;
struct RMQ {
	vector<vector<ll>> s;
	void build(vector<ll> a) {
		s.emplace_back(a);
		for(int k = 1; (1<<k) <= a.size(); k++) {
			s.emplace_back(s.back());
			for(int i = 0; i+(1<<(k-1)) < a.size(); i++) {
				s.back()[i] = max(s.back()[i], s.back()[i+(1<<(k-1))]);
			}
		}
	}
	ll qry(int l, int r) {
		if(l >= r) return -inf;
		int k = __lg(r-l);
		return max(s[k][l], s[k][r-(1<<k)]);
	}
};

ll op(ll x, ll y) { return max(x, y); }
ll e() { return -inf; }
using seg = atcoder::segtree<ll, op, e>;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(n), t(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++) {
		a[i] -= t[i];
		b[i] -= t[i];
	}
	for(int i = 1; i < n; i++) a[i] += a[i-1];
	for(int j = n-1; j-->0;) b[j] += b[j+1];
	for(int i = 0; i < n; i++) {
		a[i] += t[i];
		b[i] += t[i];
	}
	vector<vector<array<ll, 2>>> sg(2*n);
	vector<ll> done(2*n, -inf), M(2*n, inf), L(2*n, inf);
	for(ll l, r, k, i = 0; i < m; i++) {
		cin >> l >> r >> k;l--,r--;
		int ol = l;
		for(l+=n,r+=n+1;l<r;l>>=1,r>>=1) {
			if(l&1) {
				M[l] = min(M[l], k);
				sg[l++].push_back({ol, k});
			}
			if(r&1) {
				M[r-1] = min(M[r-1], k);
				sg[--r].push_back({ol, k});
			}
		}
	}
	for(int i = n; i--;) {
		for(int v = i+n; v; v/=2)
			L[v] = i;
	}
	RMQ L1;L1.build(a);
	seg L2(n);
	ll ans = -inf;
	for(int i = 0; i < n; i++) {
		ll cur = -inf;
		for(int T = n+i; T; T/=2) if(!sg[T].empty()) {
			if(done[T] == -inf) {
				for(auto [l, v] : sg[T]) {
					// assert(l <= L[T]);
					// assert(v >= M[T]);
					done[T] = max(done[T], L1.qry(l, i+1) - v);
					done[T]= max(done[T], L2.prod(max(l-1, 0ll), i) - v);
				}
				sg[T] = {{L[T], M[T]}};
				done[T] = max(done[T], 1-inf);
			}
			cur = max(cur, done[T]);
			for(auto [l, v] : sg[T]) {
				cur = max(cur, L1.qry(l, i+1) - v);
				cur = max(cur, L2.prod(max(l-1, 0ll), i) - v);
			}
		}
		L2.set(i, cur);
		ans = max(ans, cur+b[i]);
	}
	for(auto i : t) ans += i;
	cout << ans << '\n';
}
//a_l + b_r + c(l, r)
//dp[r][l] = dp[r-1][i] + c(r, i)
//wtf this is basically the same as an old agc problem
// Problem: D. 
// Contest: Codeforces - Codeforces Round #612 (Div. 1)
// URL: https://codeforces.com/contest/1286/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int mod = 998244353;
using mat = array<array<int, 2>, 2>;
mat def, ze;
mat e() { return def; };
mat mul(mat a, mat b) {
	mat c = ze;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			ll t = 0;
			for(int k = 0; k < 2; k++) {
				t += a[k][j]*1ll*b[i][k];
			}
			c[i][j] = t%mod;
		}
	}
	return c;
}
int inv(int a) {
	return a > 1 ? mod - (mod/a)*1ll*inv(mod%a)%mod : a;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	def = {1, 0, 0, 1};
	ze = {0, 0, 0, 0};
	int n;
	cin >> n;
	vector<int> x(n), v(n), p(n);
	vector<mat> cur(n-1);
	ll i100 = inv(100);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> v[i] >> p[i];
		p[i] = 100-p[i];
		if(i) {
			cur[i-1][0][1] = cur[i-1][0][0] = p[i]*i100%mod;
			cur[i-1][1][1] = cur[i-1][1][0] = (100-p[i])*i100%mod;
		}
	}

	atcoder::segtree<mat, mul, e> st(cur);
	vector<array<int, 4>> block;
	for(int i = 1; i < n; i++) {
		if(v[i] != v[i-1]) {
			//block LL or RR
			block.push_back({x[i]-x[i-1],abs(v[i]-v[i-1]), i-1, v[i] > v[i-1] ? 0 : 3});
		}
		//RL
		block.push_back({x[i]-x[i-1], v[i]+v[i-1], i-1, 2});
	}
	sort(all(block), [&](auto a, auto b) {
		if(a[0]*1ll*b[1] != b[0]*1ll*a[1])
			return a[0]*1ll*b[1] < b[0]*1ll*a[1];
		return a < b;
	});
	ll ans = 0;
	auto p0 = i100*1ll*p[0]%mod, p1 = i100*1ll*(100-p[0])%mod;
	for(auto &[A, B, i, tp] : block) {
		A = (A%mod)*1ll*inv(B)%mod;
	}
	int ps = 0;
	block.push_back({0, 0, -1, 0});
	for(auto [ti, B, i, tp] : block) {
		ll sm = 0;
		auto T = st.prod(0, n-1);
		sm = (sm+(T[0][0]+T[1][0])*1ll*p0)%mod;
		sm = (sm+(T[0][1]+T[1][1])*1ll*p1)%mod;
		ll Z = (mod + block[ps][0] - (ps?block[ps-1][0]:0))%mod;
		ans = (ans + Z*1ll*sm)%mod;
		if(i != -1) {
			cur[i][tp&1][tp/2] = 0;
			st.set(i, cur[i]);
		}
		ps++;
	}
	cout << ans << '\n';
}
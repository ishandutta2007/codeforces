// Problem: C. Max Mex
// Contest: Codeforces - Codeforces Round #526 (Div. 1)
// URL: https://codeforces.com/contest/1083/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
struct virtual_tree
{
	vector<int> tour, depth, pos, mp;
	vector<vector<int>> table;

	virtual_tree() {}
	virtual_tree(vector<vector<int>> &adj)
	{
		pos = mp = vector<int>(adj.size());
		function<void(int, int, int)> dfs = [&](int u, int p, int d)
		{
			pos[u] = tour.size();
			tour.push_back(u);
			depth.push_back(d);

			for (int v : adj[u])
				if (v != p)
				{
					dfs(v, u, d+1);
					tour.push_back(u);
					depth.push_back(d);
				}			
		};
		dfs(0, -1, 0);

		int t = tour.size(), lg = __lg(t);
		table.resize(lg+1, vector<int>(t));
		iota(table[0].begin(), table[0].end(), 0);
		for (int j = 0; j < lg; ++j)
			for (int i = 0; i + (1<<(j+1)) <= t; ++i)
				table[j+1][i] = argmin(table[j][i], table[j][i+(1<<j)]);
	}

	inline int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }

	inline int lca(int u, int v)
	{
		int i = pos[u], j = pos[v];
		if (i > j) swap(i, j);
		int l = __lg(j - i);
		return i == j ? u : tour[argmin(table[l][i], table[l][j-(1<<l)])];
	}

	inline int dist(int u, int v)
	{
		return depth[pos[u]] + depth[pos[v]] - 2*depth[pos[lca(u, v)]];
	}

	vector<vector<pair<int, int>>> compress(vector<int> c)
	{
		auto cmp = [&](const int &x, const int &y) { return pos[x] < pos[y]; };

		sort(c.begin(), c.end(), cmp);
		for (int i = 1, sz = c.size(); i < sz; ++i)
			c.push_back(lca(c[i-1], c[i]));

		sort(c.begin(), c.end(), cmp);
		c.erase(unique(c.begin(), c.end()), c.end());

		vector<vector<pair<int, int>>> g(c.size());
		vector<int> s;

		// u become mp[u]

		for (auto &u : c)
		{
			mp[u] = &u-&c[0];
			while (!s.empty() && lca(s.back(), u) != s.back())
				s.pop_back();

			if (!s.empty())
			{
				int d = dist(s.back(), u);
				g[mp[s.back()]].push_back({ mp[u], d });
				g[mp[u]].push_back({ mp[s.back()], d });
			}

			s.push_back(u);
		}

		return g;
	}
};
using S = array<int, 2>;
S e() { return S{-1, -1}; }
virtual_tree vt;
S op(S a, S b) {
		if(min(a[0], b[0]) == -2)
			return {-2, -2};
		if(min(a[0], b[0]) == -1)
			return a[0]==-1?b:a;
		array<int, 4> v {a[0], a[1], b[0], b[1]};
		int x = v[0], y = v[1], d = -1;
		for(int i = 0; i < 4; i++) {
			for(int t, j = 0; j < i; j++) {
				if((t=vt.dist(v[i], v[j])) > d)
					d = t, x = v[i], y = v[j];
			}
		}
		int ok = 1;
		for(int i = 0; i < 4; i++) {
			ok &= vt.dist(x, v[i])+vt.dist(v[i], y)==d;
		}
		if(!ok) return S{-2, -2};
		return {x, y};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, q;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> pos(n);
	for(auto &i : pos) cin >> i;
	for(int t, i = 1; i < n; i++) {
		cin >> t;t--;
		g[t].push_back(i);
	}
	vt = virtual_tree(g);
	vector<array<int, 2>> stin(n);
	for(int i = 0; i < n; i++)
		stin[pos[i]] = {i, i};
	atcoder::segtree<S, op, e> seg(stin);
	cin >> q;
	for(int t, u, v, i = 0; i < q; i++) {
		cin >> t;
		if(t == 2) {
			cout << seg.max_right(0, [&](S s) {
				return s[0] != -2;
			}) << '\n';
		} else {
			cin >> u >> v;u--,v--;
			swap(pos[u], pos[v]);
			seg.set(pos[u], S{u, u});
			seg.set(pos[v], S{v, v});
			stin[pos[u]] = S{u, u};
			stin[pos[v]] = S{v, v};
		}
	}
}
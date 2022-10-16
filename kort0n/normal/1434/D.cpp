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

struct EulerTourForVertex{
public:
  vector<int> ls,rs;
  int pos;

  void dfs(int v,int p){
    ls[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v);
    rs[v]=pos;
  }

  vector< vector<int> > G;

  EulerTourForVertex(){}
  EulerTourForVertex(int n):ls(n),rs(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    pos=0;
    dfs(r,-1);
  }

  int idx(int v){return ls[v];}

  template<typename F>
  void exec(int v,F f){
    f(ls[v],rs[v]);
  }
};
ll N;
ll a[501000], b[501000], t[501000];
ll dist[2][501000];
ll v[2];
vector<l_l> edges[501000];
ll ans[501000];
ll M;
ll e[501000];
ll color[501000];

void dfs1(ll idx, ll now, ll from) {
    for(auto tmp : edges[now]) {
        ll to = tmp.first;
        if(to == from) continue;
        dist[idx][to] = dist[idx][now] + 1;
        dfs1(idx, to, now);
    }
}

void dfs2(ll now, ll from) {
    for(auto tmp : edges[now]) {
        ll to = tmp.first;
        if(to == from) continue;
        color[to] = color[now] ^ tmp.second;
        dfs2(to, now);
    }
}

l_l op(l_l a, l_l b) {
    return {max(a.first, b.first), max(a.second, b.second)};
}

l_l E() {
    return {-INF, -INF};
}

l_l mapping(bool f, l_l a) {
    if(f) swap(a.first, a.second);
    return a;
}

bool composition(bool a, bool b) {
    return a ^ b;
}

bool id() {
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        cin >> a[i] >> b[i] >> t[i];
        a[i]--;
        b[i]--;
        edges[a[i]].push_back({b[i], t[i]});
        edges[b[i]].push_back({a[i], t[i]});
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        ans[i] = 0;
        cin >> e[i];
        e[i]--;
    }
    dfs1(0, 0, -1);
    for(int i = 0; i < N; i++) {
        if(dist[0][i] > dist[0][v[0]]) v[0] = i;
    }
    dfs1(1, v[0], -1);
    for(int i = 0; i < N; i++) {
        if(dist[1][i] > dist[1][v[1]]) v[1] = i;
    }
    dist[0][v[0]] = 0;
    dist[1][v[1]] = 0;
    dfs1(0, v[0], -1);
    dfs1(1, v[1], -1);
    dfs2(0, -1);
    atcoder::lazy_segtree<l_l, op, E, bool, mapping, composition, id> seg;
    for(int t = 0; t < 2; t++) {
        //cerr << "---" << v[t] << "---" << endl;
        EulerTourForVertex ET(N);
        for(int j = 0; j < N - 1; j++) {
            ET.add_edge(a[j], b[j]);
        }
        ET.build(v[t]);
        /*
        for(int i = 0; i < N; i++) {
            cerr << ET.ls[i] << " " << ET.rs[i] << endl;
        }
        */
        seg = atcoder::lazy_segtree<l_l, op, E, bool, mapping, composition, id>(N);
        for(int i = 0; i < N; i++) {
            ll pos = ET.ls[i];
            //cout << (color[i] ^ color[v[t]]) << " " << pos << " " << dist[t][i] << endl;
            if(color[i] == color[v[t]]) {
                seg.set(pos, {dist[t][i], -INF});
            } else {
                seg.set(pos, {-INF, dist[t][i]});
            }
        }
        //cerr << " " << seg.all_prod().first << " " << seg.all_prod().second << endl;
        for(int i = 0; i < M; i++) {
            ll p;
            if(dist[t][a[e[i]]] > dist[t][b[e[i]]]) p = a[e[i]];
            else p = b[e[i]];
            seg.apply(ET.ls[p], ET.rs[p], true);
            //cerr << ET.ls[p] << " " << ET.rs[p] << endl;
            //cerr << i << " " << seg.all_prod().first << " " << seg.all_prod().second << endl;
            chmax(ans[i], seg.all_prod().first);
        }
    }
    for(int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
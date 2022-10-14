//Heavy-Light Decomposition
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef ll T;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define A(a) (a).begin(), (a).end()
#define N 100010

vector<ll> tree[N];
T val[N];
ll dep[N], idx[N], sz[N], top[N], aa[N], par[N], st[N];

namespace sgtree { //modified for HLD operations
    T id = 0, t[2 * N];
    T f(T a, T b) { return a + b; }

    void modify(ll i, T v) { //set value v at vertex i
        for(t[i = idx[i] + N] = v; i /= 2;) t[i] = f(t[2 * i], t[2 * i + 1]);
    }

    T query(ll i, ll a) { //fold f on first a ancestors of i
        ll r = idx[i] + 1 + N, l = r - a;
        T res = id;
        for(; l < r; l /= 2, r /= 2) {
            if(l & 1) res = f(res, t[l++]);
            if(r & 1) res = f(res, t[--r]);
        }
        return res;
    }
}

ll dfs1(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    sz[i] = 1;
    for(ll j : tree[i]) if(j - p)
        sz[i] += dfs1(j, i);
    sort(A(tree[i]), [](ll j, ll k) { return sz[j] > sz[k]; });
    return sz[i];
}

ll pos = 0;
void dfs2(ll i, ll p, ll t, ll s) {
    top[i] = t;
    st[i] = s;
    idx[i] = pos++;
    sgtree::modify(i, val[i]);
    for(ll j : tree[i]) if(j - p)
        dfs2(j, i, t, t == i ? j : s), t = i;
}

#define UPD(i) max(abs(aa[i] + aa[par[i]]), abs(aa[i] - aa[par[i]]))

T query(ll a, ll b) { //only works for commutative operations - others very messy
    if(dep[a] - dep[b] == idx[a] - idx[b]) {
        if(dep[a] > dep[b]) swap(a, b);
        return sgtree::query(b, dep[b] - dep[a]); //remove +1 if querying vals at edges (not vertices)
    }
    sgtree::modify(st[a], UPD(st[a]));
    sgtree::modify(st[b], UPD(st[b]));
    if(dep[top[a]] > dep[top[b]]) swap(a, b);
    return sgtree::f(query(a, top[b]), sgtree::query(b, dep[b] - dep[top[b]]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    F(i, 1, n + 1) cin >> aa[i];
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs1(1, N - 1); //N - 1 is unused root vertex
    F(i, 2, n + 1) val[i] = UPD(i);
    dfs2(1, N - 1, N - 1, 1);
    while(q--) {
        G(t) G(u) G(v)
        if(t == 1) {
            aa[u] = v;
            sgtree::modify(u, UPD(u));
            for(ll j : tree[u]) if(j - par[u]) { sgtree::modify(j, UPD(j)); break; }
        } else cout << query(u, v) << '\n';
    }
}
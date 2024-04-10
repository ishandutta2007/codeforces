//Segment Tree
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 1000010

struct segtree {
    typedef pl T;
    T id = {0, 0}, t[2 * N];

    T f(T a, T b) { return {min(a.K, a.V + b.K), a.V + b.V}; }

    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
};

segtree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    F(i, 0, (ll)s.size())
        if(s[i] == '(') st.modify(i, {1, 1});
        else st.modify(i, {-1, -1});
    G(q) while(q--) {
        G(l) G(r)
        pl p = st.query(l - 1, r);
        cout << (r - l + 1) - (p.V - 2 * p.K) << '\n';
    }
}
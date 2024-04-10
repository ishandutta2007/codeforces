#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator << (ostream &o, T<A...> V) {
	o << '[';
	for(auto a : V) o << a << ", ";
	return o << ']';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define L 20

ll a[N], prime[N], nxt[N][L];

namespace sgtree {
    typedef ll T;
    T id = LLONG_MAX, t[2 * N];

    T f(T a, T b) { return min(a, b); }

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
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime[0] = prime[1] = 1;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = i;
        for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
    }
    G(n) G(q)
    F(i, 0, n) cin >> a[i];
    map<ll, ll> lst;
    FD(i, n - 1, -1) {
        nxt[i][0] = n;
        while(a[i] > 1) {
            ll p = prime[a[i]];
            while(!(a[i] % p)) a[i] /= p;
            if(lst.count(p)) nxt[i][0] = min(nxt[i][0], lst[p]);
            lst[p] = i;
        }
        sgtree::modify(i, nxt[i][0]);
        nxt[i][0] = sgtree::query(i, nxt[i][0]);
    }
    F(j, 0, L) nxt[n][j] = n;
    F(j, 1, L) F(i, 0, n) nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    while(q--) {
        G(l) G(r) l--; ll ans = 0;
        FD(j, L - 1, -1) if(nxt[l][j] < r) ans += (1 << j), l = nxt[l][j];
        cout << ans + 1 << '\n';
    }
}
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
#define N 300010

namespace sgtree {
    typedef pl T;
    T id = {LLONG_MAX, LLONG_MIN}, t[2 * N];

    T f(T a, T b) { return {min(a.K, b.K), max(a.V, b.V)}; }

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

namespace sgtreeO {
    typedef pl T;
    T id = {LLONG_MAX, LLONG_MIN}, t[2 * N];

    T f(T a, T b) { return {min(a.K, b.K), max(a.V, b.V)}; }

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

ll a[N];
map<ll, vector<ll>> pos;

bool works(ll k, ll i, ll j) {
    if(pos[k][i] + 1 >= pos[k][j]) return true;
    pl p = sgtree::query(pos[k][i] + 1, pos[k][j]);
    pl q = sgtreeO::query(pos[k][i] + 1, pos[k][j]);
    if(q.K == LLONG_MAX) q = {k, k};
    if(p.K == LLONG_MAX) p = {k, k};
    if(p.V > k && q.V > k) return false;
    if(p.K < k && q.K < k) return false;
    if(p.K < k && p.V > k) return false;
    if(q.K < k && q.V > k) return false;
    return true;
}

ll bsch(ll k, ll i, ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works(k, i, m) ? bsch(k, i, m, r) : bsch(k, i, l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> a[i];
        ll diff = 0;
        pos.clear();
        pos[0].push_back(-1);
        F(i, 0, n) if(i & 1) {
            diff -= a[i];
            pos[diff].push_back(i);
            sgtreeO::modify(i, {diff, diff});
            sgtree::modify(i, sgtree::id);
        } else {
            diff += a[i];
            pos[diff].push_back(i);
            sgtree::modify(i, {diff, diff});
            sgtreeO::modify(i, sgtree::id);
        }
        ll ans = 0;
        for(auto au : pos) F(i, 0, au.V.size()) ans += bsch(au.K, i, i, au.V.size() - 1) - i;
        cout << ans << '\n';
    }
}
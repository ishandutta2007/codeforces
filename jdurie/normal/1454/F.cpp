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
#define N 200010

namespace sgtree {
    typedef pl T;
    T id = {LLONG_MAX, LLONG_MIN}, t[2 * N];

    T f(T a, T b) { return { min(a.K, b.K), max(a.V, b.V) }; }

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

ll bSearch(ll l, ll r, ll i, ll v) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return sgtree::query(i + 1, m + 1).K >= v ? bSearch(m, r, i, v) : bSearch(l, m - 1, i, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 0, n) cin >> a[i], sgtree::modify(i, { a[i], a[i] });
        ll mx = 0;
        string ans = "NO\n";
        ll x = 0, y = 0, z = 0;
        F(i, 0, n - 1) {
            mx = max(mx, a[i]);
            ll j = bSearch(i + 1, n - 1, i + 1, mx);
            if(sgtree::query(i + 1, j + 1).K == mx) {
                if(sgtree::query(j + 1, n).V == mx) {
                    ans = "YES\n";
                    x = i + 1, y = j - i, z = n - j - 1;
                } else if(sgtree::query(j, n).V == mx && sgtree::query(i + 1, j).K == mx) {
                    ans = "YES\n";
                    x = i + 1, y = j - i - 1, z = n - j;
                }
            }
        }
        cout << ans;
        if(ans[0] - 'N') cout << x << ' ' << y << ' ' << z << '\n';
    }
}
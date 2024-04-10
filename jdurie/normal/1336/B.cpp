#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define SQ(x) ((x) * (x))

set<ll> s[3];
ll sz[3], a[3];

ll ceilV(ll x, ll k) {
    if(x > *s[k].rbegin()) return *s[k].rbegin();
    return *s[k].lower_bound(x);
}

ll floorV(ll x, ll k) {
    if(x < *s[k].begin()) return *s[k].begin();
    return *(--s[k].upper_bound(x));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        F(i, 0, 3) s[i].clear();
        F(i, 0, 3) cin >> sz[i];
        F(i, 0, 3) while(sz[i]--) { G(x) s[i].insert(x); }
        iota(a, a + 3, 0);
        ll ans = LLONG_MAX;
        do {
            for(ll y : s[a[1]]) {
                ll x = floorV(y, a[0]), z = ceilV(y, a[2]);
                ans = min(ans, SQ(x - y) + SQ(x - z) + SQ(y - z));
            }
        } while(next_permutation(a, a + 3));
        cout << ans << '\n';
    }
}
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

ll sm[N];

ll bsch(ll l, ll r, ll val, ll f, ll q) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return f * (sm[m] - sm[q]) >= f * val ? bsch(l, m, val, f, q) : bsch(m + 1, r, val, f, q);
}

ll getRod(ll l, ll r) {
    ll ans = sm[r] - sm[l - 1];
    ll f = ans > 0 ? 1 : -1;
    return bsch(l, r, ans / 2 + f, f, l - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(q) GS(s)
        F(i, 0, n) {
            ll v = s[i] == '+' ? 1 : -1;
            if(i & 1) v *= -1;
            sm[i + 1] = v + sm[i];
        }
        while(q--) {
            G(l) G(r)
            ll ans = sm[r] - sm[l - 1];
            if(!ans) cout << "0\n";
            else if(ans & 1) cout << "1\n" << getRod(l, r) << '\n';
            else cout << "2\n" << l << ' ' << getRod(l + 1, r) << '\n';
        }
    }
}
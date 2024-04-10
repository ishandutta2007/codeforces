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

ll muzz[N], nomuzz[N];

ll cl(ll n, ll d) { return (n + d - 1) / d; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(d) G(m)
    ll im = 0, inm = 0;
    F(i, 0, n) {
        G(x)
        if(x > m) muzz[im++] = x;
        else nomuzz[inm++] = x;
    }
    sort(muzz, muzz + im); sort(nomuzz, nomuzz + inm);
    reverse(muzz, muzz + im); reverse(nomuzz, nomuzz + inm);
    F(i, 1, im) muzz[i] += muzz[i - 1];
    F(i, 1, inm) nomuzz[i] += nomuzz[i - 1];
    ll ans = muzz[cl(n, d + 1) - 1];
    F(k, 1, inm + 1) ans = max(ans, nomuzz[k - 1] + muzz[cl(n - k, d + 1) - 1]);
    cout << ans << '\n';
}
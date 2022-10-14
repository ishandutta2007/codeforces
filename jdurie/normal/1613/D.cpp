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
#define M 998244353
#define N 500010

ll gmx[N], gmx2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        gmx[0] = gmx2[0] = 1;
        F(i, 0, n) {
            G(x)
            if(x) gmx[x - 1] = 2 * gmx[x - 1] % M;
            gmx[x + 1] = (2 * gmx[x + 1] + gmx2[x]) % M;
            gmx2[x + 1] = (2 * gmx2[x + 1] + gmx2[x]) % M;
        }
        cout << accumulate(gmx, gmx + n + 5, (ll)(M - 1)) % M << '\n';
        fill_n(gmx, n + 5, 0);
        fill_n(gmx2, n + 5, 0);
    }
}
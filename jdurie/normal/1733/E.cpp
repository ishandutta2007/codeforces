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
#define N 120

ll ct[N][N];

ll v(ll i, ll j) {
    return i >= 0 && j >= 0 ? ct[i][j] : 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(t) G(x) G(y)
        ll p = t - x - y;
        if(p < 0) cout << "NO\n";
        else {
            ct[0][0] = p;
            F(i, 0, N) F(j, 0, N) if(i || j) ct[i][j] = (v(i, j - 1) + 1) / 2 + v(i - 1, j) / 2;
            ll i = 0, j = 0;
            while(i + j < x + y) if(ct[i][j] & 1) i++; else j++;
            if(i == x && j == y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
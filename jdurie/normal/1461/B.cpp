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
#define N 510

ll spl[N][N];
string gr[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> gr[i];
        F(i, 0, n) F(j, 0, m) if(gr[i][j] == '*') spl[i][j] = 1;
        F(c, 2, n + 1) F(i, 0, n) F(j, 0, m)
            if(j && j + 1 - m && i + 1 - n && spl[i + 1][j - 1] >= c - 1 && spl[i + 1][j + 1] >= c - 1 && spl[i + 1][j] >= c - 1 && gr[i][j] == '*')
                spl[i][j] = c;
        ll ans = 0;
        F(i, 0, n) F(j, 0, m) ans += spl[i][j];
        cout << ans << '\n';
        F(i, 0, n) fill_n(spl[i], m, 0);
    }
}
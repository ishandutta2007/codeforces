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
#define N 1510

ll ct[26];
ll needm[26][N];

ll bsch(ll l, ll r, char c, ll m) {
    if(l == r) return l;
    ll q = (l + r + 1) / 2;
    return needm[c][q] <= m ? bsch(q, r, c, m) : bsch(l, q - 1, c, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    G(n) GS(s)
    F(i, 0, 26) fill_n(needm[i], N, LLONG_MAX);
    F(l, 0, n) {
        fill_n(ct, 26, 0);
        F(r, l, n) {
            ct[s[r] - 'a']++;
            F(c, 0, 26) needm[c][r - l + 1] = min(needm[c][r - l + 1], r - l + 1 - ct[c]);
        }
    }
    G(q) while(q--) {
        G(m) GS(t) int c = t[0] - 'a';
        cout << bsch(1, n, c, m) << '\n';
    }
}
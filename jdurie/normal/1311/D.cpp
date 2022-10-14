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

set<ll> facts[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 1, N) for(ll j = 1; j * j <= i; j++) if(!(i % j)) {
        facts[i].insert(j);
        facts[i].insert(i / j);
    }
    G(tc) while(tc--) {
        G(a) G(b) G(c)
        ll ans = a + b + c - 3, A = 1, B = 1, C = 1;
        F(tB, 1, N) {
            ll upperA = a > tB ? tB : *facts[tB].lower_bound(a);
            ll lowerA = *(--facts[tB].upper_bound(a));
            ll tA = abs(upperA - a) < abs(a - lowerA) ? upperA : lowerA;
            ll tC = c < tB ? tB : (c % tB < tB - c % tB ? c - c % tB : c + tB - c % tB);
            ll delt = abs(a - tA) + abs(b - tB) + abs(c - tC);
            if(delt < ans) ans = delt, A = tA, B = tB, C = tC;
        }
        cout << ans << '\n' << A << ' ' << B << ' ' << C << '\n';
    }
}
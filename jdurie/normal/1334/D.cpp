#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

ll sect[N];

ll bSearch(ll l, ll r, ll sz) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return sz < sect[m] ? bSearch(l, m, sz) : bSearch(m + 1, r, sz);
}

ll getShit(ll i, ll n) {
    if(i == n * (n - 1)) return 1;
    ll ind = bSearch(0, n - 1, i);
    ll newI = i - (ind ? sect[ind - 1] : 0);
    if(newI % 2) return newI / 2 + ind + 2;
    return ind + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n) G(l) G(r)
        sect[0] = 2 * (n - 1);
        F(i, 1, n - 1) sect[i] = sect[i - 1] + 2 * (n - i - 1);
        F(i, l - 1, r) cout << getShit(i, n) << " ";
        cout << endl;       
    }
}
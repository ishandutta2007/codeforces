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
#define N 100010

ll xr[3], ad[3], val[N];

ll query(string s, ll i, ll j) { cout << s << ' ' << i + 1 << ' ' << j + 1 << endl; G(res) return res; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    xr[0] = query("XOR", 0, 1);
    xr[1] = query("XOR", 1, 2);
    xr[2] = xr[0] ^ xr[1];
    ad[0] = query("AND", 0, 1);
    ad[1] = query("AND", 1, 2);
    ad[2] = query("AND", 0, 2);
    F(i, 0, 3) {
        ll j = (i + 1) % 3, k = (i + 2) % 3;
        val[i] = ad[i] | ad[k] | (xr[i] & (xr[i] ^ (xr[j] | ad[j])));
    }
    F(i, 3, n) val[i] = val[0] ^ query("XOR", 0, i);
    cout << '!';
    F(i, 0, n) cout << ' ' << val[i];
    cout << endl;
}
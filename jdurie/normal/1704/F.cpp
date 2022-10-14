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
#define N 500010

ll a[N];
bool x[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 2, N) {
        fill_n(x, 20, false);
        F(j, 0, min(100ll, i - 1)) x[a[j] ^ a[i - 2 - j]] = true;
        while(x[a[i]]) a[i]++;
    }
    G(tc) while(tc--) {
        G(n) GS(s)
        ll ca = count(A(s), 'R'), cb = n - ca;
        if(ca > cb) cout << "Alice\n";
        else if(cb > ca) cout << "Bob\n";
        else {
            ll st = 0, xr = 0;
            F(i, 0, n) if(i == n - 1 || s[i] == s[i + 1]) {
                xr ^= a[i - st + 1];
                st = i + 1;
            }
            cout << (xr ? "Alice\n" : "Bob\n");
        } 
    }
}
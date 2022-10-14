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
#define N 2010

ll dep[N], par[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    cout << "? 1" << endl;
    F(i, 1, n + 1) {
        cin >> dep[i];
        if(dep[i] == 1) par[i] = 1;
    }
    ll cev = 0, cod = 0;
    F(i, 2, n + 1) if(dep[i] & 1) cod++; else cev++;
    F(i, 2, n + 1) if(((dep[i] & 1) && cod < cev) || (!(dep[i] & 1) && cev <= cod)) {
        cout << "? " << i << endl;
        F(j, 1, n + 1) {
            G(d) if(d == 1) {
                if(dep[j] > dep[i]) par[j] = i;
                else par[i] = j;
            }
        }
    }
    cout << "!" << endl;
    F(i, 2, n + 1) cout << i << ' ' << par[i] << endl;
}
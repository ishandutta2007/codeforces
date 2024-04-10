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
//#define N 200010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(d12) G(d23) G(d13)
        ll s = d12 + d23 + d13;
        if(s % 2 || s / 2 >= n || d12 + d13 < d23 || d12 + d23 < d13 || d13 + d23 < d12) cout << "NO\n";
        else {
            cout << "YES\n";
            ll cur = 4, prv = 1;
            if(d13 + d23 == d12) {
                F(i, 0, d13 - 1) {
                    cout << prv << ' ' << cur << '\n';
                    prv = cur++;
                }
                cout << prv << " 3\n";
                prv = 3;
                F(i, 0, d23 - 1) {
                    cout << prv << ' ' << cur << '\n';
                    prv = cur++;
                }
                cout << prv << " 2\n";
            } else {
                F(i, 0, d12 - 1) {
                    cout << prv << ' ' << cur << '\n';
                    prv = cur++;
                }
                cout << prv << " 2\n";
                ll k = (d12 + d13 - d23) / 2;
                prv = k ? (k == d12 ? 2 : 3 + k) : 1;
                F(i, 0, d13 - k - 1) {
                    cout << prv << ' ' << cur << '\n';
                    prv = cur++;
                }
                cout << prv << " 3\n";
            }
            while(cur <= n)
                cout << "1 " << cur++ << '\n';
        }
    }
}
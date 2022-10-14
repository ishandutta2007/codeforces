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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m)
    if(n == 1) EX((m ? -1 : 1))
    ll k = (n / 2 - 1) * (n / 2);
    if(n % 2) k += n / 2;
    if(m > k) EX(-1)
    cout << "1 2";
    F(i, 3, n + 1) {
        if((i - 1) / 2 <= m) {
            cout << ' ' << i;
            m -= (i - 1) / 2;
        } else if(m) {
            cout << ' ' << 2 * (i - m) - 1;
            m = 0;
        } else {
            F(j, i, n + 1) cout << ' ' << (j - i + 1) * N + j - i;
            exit(0);
        }
    }
    cout << endl;
}
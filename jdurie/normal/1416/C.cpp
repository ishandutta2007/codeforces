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

#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 300010

ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) cin >> a[i];
    ll invs = 0, x = 0;
    FD(b, 30, -1) {
        ll c = (1 << b);
        ll invs0 = 0, invs1 = 0;
        gp_hash_table<ll, pl> ct;
        F(i, 0, n)
            if(a[i] & c) {
                invs1 += ct[a[i] / c / 2].K;
                ct[a[i] / c / 2].V++;
            } else {
                invs0 += ct[a[i] / c / 2].V;
                ct[a[i] / c / 2].K++;
            }
        invs += min(invs0, invs1);
        if(invs1 < invs0) x ^= c;
    }
    cout << invs << ' ' << x << '\n';
}
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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

map<ll, ll> rs;
pl ints[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(x) G(y)
    F(i, 0, n) cin >> ints[i].K >> ints[i].V;
    sort(ints, ints + n);
    ll ans = 0;
    F(i, 0, n) {
        ll newAns = x + (ints[i].V - ints[i].K) * y;
        if(rs.size() && rs.begin()->K < ints[i].K) {
            ll ceilR = (--rs.lower_bound(ints[i].K))->K;
            rs[ceilR]--;
            if(!rs[ceilR]) rs.erase(ceilR);
            newAns = min(newAns, y * (ints[i].V - ceilR));
        }
        ans = (ans + newAns % M) % M;
        rs[ints[i].V]++;
    }
    cout << ans << '\n';
}
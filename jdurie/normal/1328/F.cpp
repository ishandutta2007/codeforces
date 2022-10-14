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

map<ll, ll> mp;
vector<pl> v, bef, aft;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k)
    F(i, 0, n) { G(a) mp[a]++; }
    for(auto a : mp) v.push_back(a);
    ll sm = 0, ct = 0;
    for(pl x : v) {
        bef.emplace_back(sm, ct);
        sm += x.K * x.V, ct += x.V;
    }
    reverse(A(v));
    sm = ct = 0;
    for(pl x : v) {
        aft.emplace_back(sm, ct);
        sm += x.K * x.V, ct += x.V;
    }
    reverse(A(v)), reverse(A(aft));
    ll ans = LLONG_MAX;
    F(i, 0, mp.size()) {
        if(v[i].V >= k) ans = 0;
        else {
            ll aL = bef[i].V * (v[i].K - 1) - bef[i].K + k - v[i].V;
            if(v[i].V + bef[i].V >= k) ans = min(ans, aL);
            ll aR = aft[i].K - aft[i].V * (v[i].K + 1) + k - v[i].V;
            if(v[i].V + aft[i].V >= k) ans = min(ans, aR);
            ll aB = aL + aR - k + v[i].V;
            ans = min(ans, aB);
        }
    }
    cout << ans << '\n';
}
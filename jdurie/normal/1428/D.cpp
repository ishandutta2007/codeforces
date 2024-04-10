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

ll a[N];
vector<ll> mp1, mp2;
vector<pl> targs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n) cin >> a[i];
    FD(i, n - 1, -1) {
        if(a[i] == 0) continue;
        else if(a[i] == 1) targs.emplace_back(i, i), mp1.push_back(i);
        else if(a[i] == 2) {
            if(mp1.empty()) EX(-1)
            ll r = mp1.back(); mp1.pop_back();
            targs.emplace_back(r, i);
            mp2.push_back(i);
        } else {
            ll r = 0;
            if(mp2.size()) r = mp2.back(), mp2.pop_back();
            else if(mp1.size()) r = mp1.back(), mp1.pop_back();
            else EX(-1)
            targs.emplace_back(i, i);
            targs.emplace_back(i, r);
            mp2.push_back(i);
        }
    }
    cout << targs.size() << '\n';
    for(pl p : targs) cout << p.K + 1 << ' ' << p.V + 1 << '\n';
}
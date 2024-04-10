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

ll a[6], b[N];
set<ll> st[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 0, 6) cin >> a[i];
    G(n) F(i, 0, n) cin >> b[i], st[i].insert(M);
    vector<pl> delts;
    F(i, 0, n) F(j, 0, 6) delts.emplace_back(b[i] - a[j], i);
    sort(A(delts));
    F(i, 0, (ll)delts.size()) st[delts[i].V].insert(i);
    set<pl> cur;
    F(i, 0, n) cur.insert({*st[i].begin(), i});
    ll ans = LLONG_MAX;
    F(i, 0, (ll)delts.size()) {
        if(cur.rbegin()->K == M) break;
        ans = min(ans, delts[cur.rbegin()->K].K - delts[i].K);
        cur.erase({i, delts[i].V});
        cur.insert({*st[delts[i].V].upper_bound(i), delts[i].V});
    }
    EX(ans)
}
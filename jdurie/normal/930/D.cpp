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

ll solve(vector<pl> pos) {
    map<ll, vector<ll>> m;
    multiset<ll> above, below;
    for(pl p : pos) below.insert(p.K), m[p.V].push_back(p.K);
    ll ans = 0;
    FD(i, 1000000, -1000000) {
        for(ll x : m[i]) below.erase(below.find(x)), above.insert(x);
        if(above.size() && below.size()) ans += max(0ll, min(*below.rbegin(), *above.rbegin()) - max(*below.begin(), *above.begin()));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    vector<pl> v1, v2;
    while(n--) {
        G(x) G(y)
        if(!((x + y) & 1)) v1.emplace_back((x + y) / 2, (x - y) / 2); else v2.emplace_back((x - 1 + y) / 2, (x - 1 - y) / 2);
    }
    cout << solve(v1) + solve(v2) << '\n';
}
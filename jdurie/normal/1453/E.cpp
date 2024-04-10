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
#define N 200010

vector<ll> tree[N];
ll k;

ll getK(ll i, ll p) {
    vector<ll> v;
    for(ll j : tree[i]) if(j - p) v.push_back(getK(j, i));
    sort(A(v));
    if(v.empty()) { k = max(k, 1ll); return 1; }
    if(v.size() == 1) { k = max(k, v[0]); return v[0] + 1; }
    if(i == p) { k = max({ k, v[v.size() - 2] + 1, v.back() }); return 2399572836246327ll; }
    k = max(k, v.back() + 1);
    return v[0] + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) k = 0;
        F(i, 0, n - 1) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        getK(1, 1);
        cout << k << '\n';
        F(i, 1, n + 1) tree[i].clear();
    }
}
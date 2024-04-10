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

bool done[N];
ll ans = 0;

pair<bool, bool> dfs(ll i, ll p) {
    bool takenAll = true, takenOne = false, coveredAll = true;
    for(ll j : tree[i]) if(j - p) {
        pair<bool, bool> pp = dfs(j, i);
        //cout << j << pp << '\n';
        if(!pp.K) takenAll = false;
        if(!pp.V) coveredAll = false;
        if(pp.K) takenOne = true;
    }
    if(!coveredAll) { ans++; return {true, true}; }
    if(takenOne || done[i]) return {false, true};
    return {false, false};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(ll v : tree[1]) {
        done[v] = true;
        for(ll u : tree[v]) done[u] = true;
    }
    dfs(1, 1); 
    cout << ans << '\n';
}
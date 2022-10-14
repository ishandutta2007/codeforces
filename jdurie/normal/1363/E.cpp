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
#define N 200010

ll a[N], val[N];
vector<ll> tree[N];

ll ans = 0;
pl dfs(ll i, ll p, ll c) {
    a[i] = min(c, a[i]);
    pl pi = {0, 0};
    if(val[i] == 1) pi.K++; 
    else if(val[i] == 2) pi.V++;
    for(ll j : tree[i]) if(j - p) {
        pl pj = dfs(j, i, a[i]);
        pi.K += pj.K; pi.V += pj.V;
    }
    ll mn = min(pi.K, pi.V);
    ans += 2 * a[i] * mn;
    return {pi.K - mn, pi.V - mn};
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) {
        cin >> a[i];
        G(b) G(c)
        val[i] = 2 * b + c;
    }
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    pl p = dfs(1, -1, LLONG_MAX);
    cout << (!p.K && !p.V ? ans : -1) << '\n';
}
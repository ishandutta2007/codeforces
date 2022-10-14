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
ll a[N], ans[N];

void dfs(ll i, ll p, ll g, ll c) {
    if(a[i] % g) c++;
    if(c > 1) return;
    ans[i] = max(ans[i], g);
    for(ll j : tree[i]) if(j - p) dfs(j, i, g, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) cin >> a[i];
    F(i, 0, n - 1) { 
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    set<ll> divs;
    F(i, 1, a[1] + 1) if(!(a[1] % i)) divs.insert(i);
    for(ll i : tree[1]) {
        for(ll x = 2; x * x <= a[i]; ++x) if(!(a[i] % x)) {
            if(a[1] % x) dfs(i, 1, x, 1);
            if(a[1] % (a[i] / x)) dfs(i, 1, a[i] / x, 1);
        }
        if(a[1] % a[i]) dfs(i, 1, a[i], 1);
        for(ll x : divs) dfs(i, 1, x, 0);
    }
    ans[1] = a[1];
    F(i, 1, n + 1) cout << ans[i] << ' ';
    cout << '\n';
}
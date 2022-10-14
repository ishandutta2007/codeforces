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

ll h[N], ans = 0;
vector<ll> tree[N];

ll dfs(ll i, ll p) {
    if(i == p) {
        vector<ll> mxs;
        for(ll j : tree[i]) mxs.push_back(dfs(j, i));
        if(mxs.size() == 1) ans += max(0ll, h[i] - mxs[0]) + h[i];
        else {
            sort(mxs.rbegin(), mxs.rend());
            ans += max(0ll, h[i] - mxs[0]) + max(0ll, h[i] - mxs[1]);
        }
        return 0;
    }
    if(tree[i].size() == 1) {
        ans += h[i];
        return h[i];
    }
    ll mx = 0;
    for(ll j : tree[i]) if(j - p) mx = max(mx, dfs(j, i));
    if(mx < h[i]) { ans += h[i] - mx; mx = h[i]; }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 1, n + 1) cin >> h[i];
    F(i, 1, n) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ll r = 1;
    F(i, 2, n + 1) if(h[i] > h[r]) r = i;
    dfs(r, r);
    cout << ans << '\n';
}
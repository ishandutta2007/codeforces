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
#define N 300010

vector<ll> tree[N];
ll sz[N], dp[N];

ll s(ll i, ll p) {
    if(~sz[i]) return sz[i];
    sz[i] = 1;
    for(ll j : tree[i]) if(j - p) sz[i] += s(j, i);
    return sz[i];
}

ll r(ll i, ll p) {
    if(~dp[i]) return dp[i];
    vector<ll> ch;
    for(ll j : tree[i]) if(j - p) ch.push_back(j);
    if(ch.empty()) return dp[i] = 0;
    if(ch.size() == 1) return dp[i] = s(ch[0], i) - 1;
    return dp[i] = max(s(ch[0], i) - 1 + r(ch[1], i), s(ch[1], i) - 1 + r(ch[0], i));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(sz, -1, sizeof sz);
    memset(dp, -1, sizeof dp);
    G(tc) while(tc--) {
        G(n)
        F(i, 1, n) {
            G(u) G(v)
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        cout << r(1, 1) << '\n';
        F(i, 1, n + 1) dp[i] = sz[i] = -1, tree[i].clear();
    }
}
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

ll a[N], b[N];
vector<ll> graph[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    while(m--) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    F(i, 1, n + 1) cin >> a[i];
    vector<ll> q, ans;
    F(i, 1, n + 1) if(!a[i]) q.push_back(i);
    F(i, 0, q.size()) {
        if(a[q[i]] != b[q[i]]) continue;
        ans.push_back(q[i]);
        b[q[i]]++;
        for(ll j : graph[q[i]]) if(++b[j] == a[j]) q.push_back(j);
    }
    cout << ans.size() << '\n';
    for(ll x : ans) cout << x << ' ';
    cout << '\n';
}
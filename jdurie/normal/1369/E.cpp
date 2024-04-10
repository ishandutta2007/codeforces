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
#define EX(x) { cout << x << '\n'; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

vector<pl> graph[N];
vector<ll> ans;
ll w[N], used[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 1, n + 1) cin >> w[i];
    F(i, 1, m + 1) {
        G(u) G(v)
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
        w[u]--;
        w[v]--;
    }
    vector<ll> comp;
    F(i, 1, n + 1) if(w[i] >= 0) comp.push_back(i);
    ll idx = -1;
    while(++idx < comp.size()) {
        ll u = comp[idx];
        for(pl v : graph[u]) if(!used[v.V]) {
            used[v.V] = true;
            ans.push_back(v.V);
            w[v.K]++;
            if(w[v.K] == 0) comp.push_back(v.K);
        }
    }
    if(ans.size() < m) EX("DEAD")
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for(ll a : ans) cout << a << ' ';
    cout << '\n';
}
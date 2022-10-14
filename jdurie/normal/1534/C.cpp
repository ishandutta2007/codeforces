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
#define N 400010

pl a[N];
bool used[N];
vector<ll> graph[N];

void dfs(ll i) {
    used[i] = true;
    for(ll j : graph[i]) if(!used[j]) dfs(j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 0, n) cin >> a[i].K;
        F(i, 0, n) cin >> a[i].V;
        F(i, 0, n) {
            graph[a[i].K].push_back(a[i].V);
            graph[a[i].V].push_back(a[i].K);
        }
        ll ans = 1;
        F(i, 1, n + 1) if(!used[i]) dfs(i), ans = ans * 2 % M;
        fill_n(used, n + 1, false);
        F(i, 1, n + 1) graph[i].clear();
        cout << ans << '\n';
    }
}
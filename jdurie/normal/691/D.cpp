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
#define N 1000010

vector<ll> graph[N], cur;

ll p[N], ans[N];
bool used[N];

void dfs(ll i) {
    used[i] = true;
    cur.push_back(i);
    for(ll j : graph[i]) if(!used[j]) dfs(j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    G(n) G(m)
    F(i, 1, n + 1) cin >> p[i];
    while(m--) {
        G(a) G(b)
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    F(i, 1, n + 1) if(!used[i]) {
        cur.clear();
        dfs(i);
        vector<ll> vals;
        for(ll x : cur) vals.push_back(p[x]);
        sort(A(vals)); reverse(A(vals)); sort(A(cur));
        F(j, 0, cur.size()) ans[cur[j]] = vals[j];
    }
    F(i, 1, n + 1) cout << ans[i] << ' ';
    cout << '\n';
}
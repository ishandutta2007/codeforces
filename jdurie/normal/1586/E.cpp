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

vector<ll> graph[N], backIn[N], backOut[N], tree[N];
ll dep[N], par[N], ct[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(ll j : graph[i]) if(!dep[j]) {
        tree[i].push_back(j);
        dfs(j, i);
    } else if(dep[j] < dep[i] - 1) {
        backIn[j].push_back(i);
        backOut[i].push_back(j);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    while(m--) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 1);
    vector<vector<ll>> paths;
    G(q) while(q--) {
        G(a) G(b) ct[a]++; ct[b]++;
        set<ll> anca;
        ll tmp = a;
        while(1) {
            anca.insert(tmp);
            if(tmp == 1) break; else tmp = par[tmp];
        }
        ll lca = b; while(!anca.count(lca)) lca = par[lca];
        vector<ll> v1, v2;
        tmp = a; while(tmp - lca) v1.push_back(tmp), tmp = par[tmp];
        tmp = b; while(tmp - lca) v2.push_back(tmp), tmp = par[tmp];
        reverse(A(v2)); v1.push_back(lca); for(ll x : v2) v1.push_back(x);
        paths.push_back(v1);
    }
    ll c = 0; F(i, 1, n + 1) if(ct[i] & 1) c++;
    if(c) { cout << "NO\n" << c / 2 << '\n'; }
    else {
        cout << "YES\n";
        for(auto a : paths) {
            cout << a.size() << '\n';
            for(ll x : a) cout << x << ' ';
            cout << '\n';
        }
    }
}
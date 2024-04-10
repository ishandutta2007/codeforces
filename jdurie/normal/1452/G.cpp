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

ll n, k, v[N];
vector<ll> tree[N];
vector<ll> eeee[N];
ll oooo[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    F(i, 0, n - 1) {
        G(u) G(w)
        tree[u].push_back(w);
        tree[w].push_back(u);
    }
    vector<pl> srcs;
    cin >> k;
    F(i, 0, k) { G(x) srcs.emplace_back(x, 0); }
    for(ll idx = 0; idx < srcs.size(); ++idx) {
        pl p = srcs[idx];
        if(!used[p.K]) {
            used[p.K] = true;
            v[p.K] = p.V;
            for(ll j : tree[p.K]) if(!used[j]) srcs.emplace_back(j, p.V + 1);
        }
    }
    vector<pl> lst;
    F(i, 1, n + 1) eeee[v[i]].push_back(i);
    F(i, 0, n + 1) sort(A(eeee[i])), reverse(A(eeee[i]));
    FD(x, n, 0) {
        vector<pl> bfs;
        for(ll i : eeee[x]) if(x > oooo[i]) bfs.emplace_back(x, i);
        for(ll idx = 0; idx < bfs.size(); ++idx) {
            pl q = bfs[idx];
            if(v[q.V] && q.K && q.K > oooo[q.V]) {
                used[q.V] = true;
                oooo[q.V] = q.K;
                v[q.V] = max(v[q.V], x);
                for(ll j : tree[q.V]) bfs.emplace_back(q.K - 1, j);
            }
        }
    }
    F(i, 1, n + 1) cout << v[i] << ' ';
    cout << '\n';
}
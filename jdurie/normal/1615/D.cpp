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

vector<pl> graph[N];
pair<pl, ll> edges[N];
vector<ll> tree[N];
ll bip[N];
map<pl, ll> wt;
bool ok;

void dfsbip(ll i, ll c) {
    bip[i] = c;
    for(pl p : graph[i]) if(!bip[p.K]) dfsbip(p.K, c ^ p.V);
    else if(bip[p.K] != (c ^ p.V)) ok = false;
}

void dfsfill(ll i, ll p) {
    for(ll j : tree[i]) if(j - p) {
        wt[{i, j}] = wt[{j, i}] = bip[i] ^ bip[j];
        dfsfill(j, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n - 1) {
            G(u) G(v) G(w)
            edges[i] = {{u, v}, w};
            tree[u].push_back(v);
            tree[v].push_back(u);
            if(~w) {
                graph[u].emplace_back(v, __builtin_popcountll(w) & 1);
                graph[v].emplace_back(u, __builtin_popcountll(w) & 1);
            }
        }
        while(m--) {
            G(u) G(v) G(w)
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        ok = true;
        F(i, 1, n + 1) if(!bip[i]) dfsbip(i, 2);
        dfsfill(1, 1);
        if(ok) {
            cout << "YES\n";
            F(i, 0, n - 1) cout << edges[i].K.K << ' ' << edges[i].K.V << ' ' << (~edges[i].V ? edges[i].V : wt[edges[i].K]) << '\n';
        } else cout << "NO\n";
        fill_n(bip, n + 1, 0);
        wt.clear();
        F(i, 1, n + 1) graph[i].clear(), tree[i].clear();
    }
}
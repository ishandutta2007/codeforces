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

vector<ll> graph[N], backIn[N], backOut[N], tree[N];
ll dep[N], par[N];
pl edges[N];

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
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, m) {
            G(u) G(v)
            edges[i] = {u, v};
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 1);
        if(m < n + 2) {
            F(i, 0, m) cout << (edges[i].K == par[edges[i].V] || edges[i].V == par[edges[i].K]);
            cout << '\n';
        } else {
            set<ll> verts;
            F(i, 1, n + 1) for(ll j : backOut[i]) verts.insert(i), verts.insert(j);
            if(verts.size() > 3) {
                F(i, 0, m) cout << (edges[i].K == par[edges[i].V] || edges[i].V == par[edges[i].K]);
                cout << '\n';
            } else {
                vector<ll> vertv; for(ll x : verts) vertv.push_back(x);
                sort(A(vertv), [](ll a, ll b) { return dep[a] < dep[b]; });
                ll k = vertv[2]; while(par[k] != vertv[1]) k = par[k];
                ll l = vertv[1]; while(par[l] != vertv[0]) l = par[l];
                F(i, 0, m)
                    if(edges[i].K == par[edges[i].V])
                        cout << (edges[i].V != k && edges[i].V != l);
                    else if(edges[i].V == par[edges[i].K])
                        cout << (edges[i].K != k && edges[i].K != l);
                    else cout << (edges[i].K + edges[i].V != vertv[0] + vertv[2]);
                cout << '\n';
            }
        }
        fill_n(dep, n + 1, 0);
        F(i, 1, n + 1) graph[i].clear(), tree[i].clear(), backIn[i].clear(), backOut[i].clear();
    }
}
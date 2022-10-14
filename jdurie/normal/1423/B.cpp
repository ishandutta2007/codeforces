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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define S 20010

struct dinic {
    struct edge { ll b, cap, flow, flip; };
    vector<edge> g[S + 2];
    ll ans = 0, d[S + 2], ptr[S + 2];

    void add_edge(ll a, ll b, ll cap) {
        g[a].push_back({b, cap, 0, g[b].size()});
        g[b].push_back({a, 0, 0, g[a].size() - 1});
    }

    ll dfs(ll v, ll flow = LLONG_MAX) {
        if(v == S + 1 || !flow) { ans += flow; return flow; }
        while(++ptr[v] < g[v].size()) {
            edge &e = g[v][ptr[v]];
            if(d[e.b] != d[v] + 1) continue;
            if(ll p = dfs(e.b, min(flow, e.cap - e.flow))) {
                e.flow += p;
                g[e.b][e.flip].flow -= p;
                return p;
            }
        }
        return 0;
    }

    ll calc() {
        while(1) {
            vector<ll> q{S};
            memset(d, 0, sizeof d);
            ll i = -(d[S] = 1);
            while(++i < q.size() && !d[S + 1])
                for(auto e: g[q[i]])
                    if(!d[e.b] && e.flow < e.cap) {
                        q.push_back(e.b);
                        d[e.b] = d[q[i]]+1;
                    }
            if(!d[S + 1]) return ans;
            memset(ptr, -1, sizeof ptr);
            while(dfs(S));
        }
    }
};

pair<pl, ll> edges[10 * N];
ll n, m;

bool works(ll d) {
    dinic flow;
    F(i, 1, n + 1) {
        flow.add_edge(S, i, 1);
        flow.add_edge(i + n, S + 1, 1);
    }
    F(i, 0, m) if(edges[i].V <= d)
        flow.add_edge(edges[i].K.K, edges[i].K.V + n, 1);
    return flow.calc() == n;
}

ll bSearch(ll l, ll r) {
    if(l == r) return l;
    ll mm = (l + r) / 2;
    return works(mm) ? bSearch(l, mm) : bSearch(mm + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    F(i, 0, m) cin >> edges[i].K.K >> edges[i].K.V >> edges[i].V;
    ll k = bSearch(0, M);
    cout << (k == M ? -1 : k) << '\n';
}
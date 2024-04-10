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
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

ll p[N], d[3][N];
vector<ll> graph[N];

void bfs(ll k, ll a) {
    vector<pl> qu = {{a, 0}};
    ll i = -1;
    while(++i < qu.size()) if(d[k][qu[i].K] == -1) {
        d[k][qu[i].K] = qu[i].V;
        for(ll j : graph[qu[i].K]) if(d[k][j] == -1) qu.emplace_back(j, qu[i].V + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n) G(m) G(a) G(b) G(c)
        F(i, 1, n + 1) {
            graph[i].clear();
            d[0][i] = d[1][i] = d[2][i] = -1;
        }
        F(i, 1, m + 1) cin >> p[i];
        sort(p + 1, p + 1 + m);
        F(i, 2, m + 1) p[i] += p[i - 1];
        F(i, 0, m) {
            G(u) G(v)
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs(0, a); bfs(1, b); bfs(2, c);
        ll ans = LLONG_MAX;
        F(i, 1, n + 1) if(d[0][i] + d[1][i] + d[2][i] <= m)
            ans = min(ans, p[d[0][i] + d[1][i] + d[2][i]] + p[d[1][i]]);
        cout << ans << '\n';
    }
}
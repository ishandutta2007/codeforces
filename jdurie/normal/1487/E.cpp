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
#define N 150010

pl a[4][N];
ll sz[4], ind[4][N];
vector<ll> graph[4][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 0, 4) cin >> sz[i];
    F(i, 0, 4) F(j, 0, sz[i]) cin >> a[i][j].K, a[i][j].V = j + 1;
    F(i, 1, 4) {
        sort(a[i - 1], a[i - 1] + sz[i - 1]);
        F(j, 0, sz[i - 1]) ind[i - 1][a[i - 1][j].V] = j;
        G(m) while(m--) {
            G(x) G(y)
            graph[i][y - 1].push_back(ind[i - 1][x]);
        }
        F(j, 0, sz[i]) {
            sort(A(graph[i][j]));
            ll k = 0;
            while(k < graph[i][j].size() && graph[i][j][k] == k) k++;
            if(k == sz[i - 1] || a[i - 1][k].K == LLONG_MAX) a[i][j].K = LLONG_MAX;
            else a[i][j].K += a[i - 1][k].K;
        }
    }
    ll ans = min_element(a[3], a[3] + sz[3])->K;
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}
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

typedef int ll;
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
#define N 2010

string ans[N];
ll a[N][N];
pl coord[N * N];
bool ok[N * N];
vector<pl> md[2][6100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k)
    F(i, 0, n) F(j, 0, n) {
        ans[i].push_back('G');
        cin >> a[i][j];
        coord[a[i][j]] = {i, j};
        md[0][i + j + N].push_back({i, j});
        md[1][i - j + N].push_back({i, j});
    }
    fill_n(ok, N * N, true);
    ll mn1 = 0, mx1 = 6099, mn2 = 0, mx2 = 6099, cur = n * n;
    while(1) {
        while(cur > 0 && !ok[cur]) cur--;
        if(cur <= 0) break;
        pl p = coord[cur];
        ans[p.K][p.V] = 'M';
        ok[cur] = false;
        ll nmn1 = max(mn1, p.K + p.V - k + N);
        ll nmx1 = min(mx1, p.K + p.V + k + N);
        ll nmn2 = max(mn2, p.K - p.V - k + N);
        ll nmx2 = min(mx2, p.K - p.V + k + N);
        for(; mn1 < nmn1; mn1++) for(pl q : md[0][mn1]) ok[a[q.K][q.V]] = false;
        for(; mx1 > nmx1; mx1--) for(pl q : md[0][mx1]) ok[a[q.K][q.V]] = false;
        for(; mn2 < nmn2; mn2++) for(pl q : md[1][mn2]) ok[a[q.K][q.V]] = false;
        for(; mx2 > nmx2; mx2--) for(pl q : md[1][mx2]) ok[a[q.K][q.V]] = false;
    }
    F(i, 0, n) cout << ans[i] << '\n';
}
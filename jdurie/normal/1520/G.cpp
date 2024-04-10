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
#define N 4000000
#define S 2000

typedef pair<ll, pair<int, int>> fuckoffcf;

vector<int> graph[N];
int a[S][S];
ll d[S][S];
ll w, n, m;

ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

void dijk(int si, int sj) {
    F(i, 0, n) F(j, 0, m) d[i][j] = LLONG_MAX;
    d[si][sj] = 0;
    priority_queue<fuckoffcf, vector<fuckoffcf>, greater<fuckoffcf>> q;
    q.push({0, {si, sj}});
    while(q.size()) {
        ll du = q.top().K;
        pl u = q.top().V;
        q.pop();
        if(du == d[u.K][u.V]) F(k, 0, 4) {
            ll newi = u.K + dx[k], newj = u.V + dy[k];
            if(newi >= 0 && newj >= 0 && newi < n && newj < m && ~a[newi][newj]) {
                ll dv = du + w;
                if(dv < d[newi][newj]) d[newi][newj] = dv, q.push({dv, {newi, newj}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> w;
    F(i, 0, n) F(j, 0, m) cin >> a[i][j];
    dijk(0, 0);
    ll ans = d[n - 1][m - 1]; 
    ll mnp = LLONG_MAX / 10;
    F(i, 0, n) F(j, 0, m) if(a[i][j] && ~a[i][j] && d[i][j] != LLONG_MAX) mnp = min(mnp, d[i][j] + a[i][j]);
    dijk(n - 1, m - 1);
    ll mnp2 = LLONG_MAX / 10;
    F(i, 0, n) F(j, 0, m) if(a[i][j] && ~a[i][j] && d[i][j] != LLONG_MAX) mnp2 = min(mnp2, d[i][j] + a[i][j]);
    ans = min(ans, mnp + mnp2);
    cout << (ans >= LLONG_MAX / 10 ? -1 : ans) << '\n';
}
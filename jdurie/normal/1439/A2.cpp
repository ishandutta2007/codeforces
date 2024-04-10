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
#define N 110

string s[N];
vector<vector<pl>> ans;
ll dr[4] = {0, 0, 1, 1}, dc[4] = {0, 1, 0, 1};

ll ct(ll a, ll b) {
    ll c = 0;
    F(i, 0, 2) F(j, 0, 2) if(s[a + i][b + j] == '1') c++;
    return min(3ll, c);
}

void flip(ll a, ll b, vector<ll> v, ll c) {
    vector<pl> swps;
    F(k, 0, 4) {
        ll x = a + dr[v[k]], y = b + dc[v[k]];
        if(s[x][y] == '1' && swps.size() < c) swps.emplace_back(x, y);
    }
    FD(k, 3, -1) {
        ll x = a + dr[v[k]], y = b + dc[v[k]];
        if(s[x][y] == '0' && swps.size() < 3) swps.emplace_back(x, y);
    }
    for(pl p : swps) s[p.K][p.V] = '1' + '0' - s[p.K][p.V];
    ans.push_back(swps);
}

void solve(ll a, ll b, ll thR, ll thC) {
    if(thR && thC && s[a][b] == '1')
        flip(a, b, {0, 1, 2, 3}, ct(a, b));
    if(thR && (s[a][b + thC] == '1' || s[a][b + thC + 1] == '1'))
        flip(a, b + thC, {0, 1, 2, 3}, ct(a, b + thC));
    if(thC && (s[a + thR][b] == '1' || s[a + thR + 1][b] == '1'))
        flip(a + thR, b, {0, 2, 1, 3}, ct(a + thR, b));
    ll c = ct(a + thR, b + thC);
    while(c) {
        flip(a + thR, b + thC, {0, 1, 2, 3}, c == 2 ? 1 : c);
        c = ct(a + thR, b + thC);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        ans.clear();
        F(i, 0, n) cin >> s[i];
        for(ll i = 0; i + 1 < n; i += 2)
            for(ll j = 0; j + 1 < m; j += 2)
                solve(i, j, i + 3 == n, j + 3 == m);
        cout << ans.size() << '\n';
        for(auto a : ans) {
            for(pl p : a) cout << p.K + 1 << ' ' << p.V + 1 << ' ';
            cout << '\n';
        }
    }
}
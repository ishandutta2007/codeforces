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
#define N 1000010

#define OK(x, y, k) (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < m)

string grid[N];
ll n, m;
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

void dfs(ll i, ll j) {
    ll x = -1, y = -1;
    F(k, 0, 4) if(OK(i, j, k)) {
        ll i2 = i + dx[k], j2 = j + dy[k];
        if(grid[i2][j2] == '.') {
            if(~x) return;
            else x = i2, y = j2;
        } 
    }
    grid[i][j] = '+';
    if(~x) dfs(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> grid[i];
        ll lx = 0, ly = 0;
        F(i, 0, n) F(j, 0, m) if(grid[i][j] == 'L') lx = i, ly = j;
        F(k, 0, 4) if(OK(lx, ly, k) && grid[lx + dx[k]][ly + dy[k]] == '.') dfs(lx + dx[k], ly + dy[k]);
        F(i, 0, n) cout << grid[i] << '\n', grid[i].clear();
    }
}
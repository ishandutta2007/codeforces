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
#define N 110
#define OK(r, c) (r >= 0 && c >= 0 && r < n && c < m)

string grid[N];
ll n, m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool used[N][N];

void dfs(ll i, ll j) {
    used[i][j] = true;
    F(k, 0, 4) {
        ll i2 = i + dx[k], j2 = j + dy[k];
        if(OK(i2, j2) && !used[i2][j2] && grid[i2][j2] != '#') dfs(i2, j2); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> grid[i];
        F(i, 0, n) F(j, 0, m) used[i][j] = false;
        F(i, 0, n) F(j, 0, m) if(grid[i][j] == 'B') F(k, 0, 4) {
            ll i2 = i + dx[k], j2 = j + dy[k];
            if(OK(i2, j2) && grid[i2][j2] == '.') grid[i2][j2] = '#'; 
        }
        if(grid[n - 1][m - 1] != '#') dfs(n - 1, m - 1);
        string ans = "Yes\n";
        F(i, 0, n) F(j, 0, m) 
            if(used[i][j] && grid[i][j] == 'B') ans = "No\n";
            else if(!used[i][j] && grid[i][j] == 'G') ans = "No\n";
        cout << ans;
    }
}
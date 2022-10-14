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

string grid[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> grid[i];
        if(grid[0][0] == '1') { cout << "-1\n"; continue; }
        vector<pair<pl, pl>> ops;
        FD(i, n - 1, 0) F(j, 0, m)
            if(grid[i][j] == '0') ops.push_back({{i, j}, {i, j}});
            else ops.push_back({{i - 1, j}, {i, j}});
        FD(j, m - 1, 0)
            if(grid[0][j] == '0') ops.push_back({{0, j}, {0, j}});
            else ops.push_back({{0, j - 1}, {0, j}});
        cout << ops.size() << '\n';
        for(auto a : ops)
            cout << a.K.K + 1 << ' ' << a.K.V + 1 << ' '<< a.V.K + 1 << ' ' << a.V.V + 1 << '\n';
    }
}
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
vector<vector<pl>> ops;

ll ct(ll i, ll j) {
    ll ans = 0;
    F(x, 0, 2) F(y, 0, 2) if(s[i + x][j + y] == '1') ans++;
    return ans;
}

void doswap(ll i, ll j, ll ct1) {
    ll ct0 = 3 - ct1;
    ops.push_back({});
    F(x, 0, 2) F(y, 0, 2)
        if(s[i + x][j + y] == '1' && ct1) {
            ct1--;
            s[i + x][j + y] = '0';
            ops.back().push_back({i + x + 1, j + y + 1});
        } else if(s[i + x][j + y] == '0' && ct0) {
            ct0--;
            s[i + x][j + y] = '1';
            ops.back().push_back({i + x + 1, j + y + 1});
        }
}

void fix(ll i, ll j) {
    ll k = ct(i, j);
    if(k == 1) {
        doswap(i, j, 1);
        doswap(i, j, 1);
        doswap(i, j, 3);
    } else if(k == 2) {
        doswap(i, j, 1);
        doswap(i, j, 3);
    } else if(k == 3)
        doswap(i, j, 3);
    else if(k == 4) {
        doswap(i, j, 3);
        doswap(i, j, 1);
        doswap(i, j, 1);
        doswap(i, j, 3);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        ops.clear();
        G(n) G(m)
        F(i, 0, n) cin >> s[i];
        for(ll i = 0; i + 1 < n; i += 2)
            for(ll j = 0; j + 1 < m; j += 2)
                fix(i, j);
        for(ll j = 0; j + 1 < m; j += 2) fix(n - 2, j);
        for(ll i = 0; i + 1 < n; i += 2) fix(i, m - 2);
        fix(n - 2, m - 2);
        cout << ops.size() << '\n';
        for(auto a : ops) {
            for(pl p : a)
                cout << p.K << ' ' << p.V << ' ';
            cout << '\n';
        }
    }
}
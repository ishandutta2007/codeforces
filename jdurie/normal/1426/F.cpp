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
#define N 200010

ll n, k, ans = 0;
string s, t = "abc?";
ll p3[N], pr[4][N], su[4][N];

void doCT(ll i1, ll i2, ll i3, ll c) { F(i, 1, n - 1) if(s[i] == t[i2]) ans = (ans + pr[i1][i - 1] * su[i3][i + 1] % M * p3[max(0ll, k - c)]) % M; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p3[0] = 1;
    F(i, 1, N) p3[i] = 3 * p3[i - 1] % M;
    cin >> n >> s;
    k = count(A(s), '?');
    F(i, 0, n) F(j, 0, 4) {
        if(s[i] == t[j]) pr[j][i] = 1;
        if(i) pr[j][i] += pr[j][i - 1];
    }
    FD(i, n - 1, -1) F(j, 0, 4) {
        if(s[i] == t[j]) su[j][i] = 1;
        if(i - n + 1) su[j][i] += su[j][i + 1];
    }
    doCT(0, 1, 2, 0);
    doCT(3, 1, 2, 1);
    doCT(0, 3, 2, 1);
    doCT(0, 1, 3, 1);
    doCT(0, 3, 3, 2);
    doCT(3, 1, 3, 2);
    doCT(3, 3, 2, 2);
    doCT(3, 3, 3, 3);
    cout << ans << '\n';
}
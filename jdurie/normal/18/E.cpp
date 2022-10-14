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

typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 510

pair<ll, pair<char, char>> dp[N][27][27];
ll n, m, cts[N][2][26];

ll r(ll i, ll c1, ll c2) {
    if(i == n) return 0;
    if(dp[i][c1][c2].K != INT_MAX) return dp[i][c1][c2].K;
    F(a, 0, 26) F(b, 0, 26) if(a != c1 && b != c2 && a != b) {
        ll cost = m - cts[i][0][a] - cts[i][1][b] + r(i + 1, a, b);
        if(cost < dp[i][c1][c2].K) dp[i][c1][c2] = {cost, {a + 'a', b + 'a'}};
    }
    return dp[i][c1][c2].K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d %d\n", &n, &m);
    F(i, 0, n) {
        char c;
        F(j, 0, m) {
            scanf("%c", &c);
            cts[i][j & 1][c - 'a']++;
        }
        scanf("%c", &c);
    }
    F(i, 0, N) F(j, 0, 27) F(k, 0, 27) dp[i][j][k] = {INT_MAX, {26, 26}};
    printf("%d\n", r(0, 26, 26));
    ll x1 = 26, x2 = 26;
    F(i, 0, n) {
        auto c = dp[i][x1][x2].V;
        F(j, 0, m) printf("%c", j & 1 ? c.V : c.K);
        printf("\n");
        x1 = c.K - 'a'; x2 = c.V - 'a';
    }
}
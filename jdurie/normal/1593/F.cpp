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
#define N 42

char dp[N][N][N][N];
ll n, x[N], a, b;

#define DP dp[i][rm][bm][rd]
char r(ll i, ll rm, ll bm, ll rd) {
    if(DP - 'u') return DP;
    if(i == n) {
        if(rm || bm || !rd || rd == n) return DP = 'x';
        return DP = abs(rd - (n - rd));
    }
    char cr = r(i + 1, (rm * 10 + x[i]) % a, bm, rd + 1);
    char cb = r(i + 1, rm, (bm * 10 + x[i]) % b, rd);
    return DP = min(cr, cb);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> a >> b; GS(s)
        F(i, 0, n) x[i] = s[i] - '0';
        memset(dp, 'u', sizeof dp);
        char c = r(0, 0, 0, 0);
        if(c == 'x') cout << "-1\n";
        else {
            ll rm = 0, bm = 0, rd = 0;
            string ans = "";
            F(i, 0, n) {
                char cr = r(i + 1, (rm * 10 + x[i]) % a, bm, rd + 1);
                char cb = r(i + 1, rm, (bm * 10 + x[i]) % b, rd);
                if(cr < cb) {
                    ans = ans + "R";
                    rm = (rm * 10 + x[i]) % a;
                    rd++;
                } else {
                    ans = ans + "B";
                    bm = (bm * 10 + x[i]) % b;
                }
            }
            cout << ans << '\n';
        }
    }
}
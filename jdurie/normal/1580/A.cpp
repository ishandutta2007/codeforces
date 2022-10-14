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
#define N 410

ll a[N][N], rs[N][N], cs[N][N], s[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) {
            GS(st)
            F(j, 0, m) a[i][j] = st[j] - '0';
        }
        s[0][0] = a[0][0];
        F(i, 1, n) s[i][0] = a[i][0] + s[i - 1][0];
        F(i, 1, m) s[0][i] = a[0][i] + s[0][i - 1];
        F(i, 1, n) F(j, 1, m) s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        F(i, 0, n) {
            rs[i][0] = !a[i][0];
            F(j, 1, m) rs[i][j] = !a[i][j] + rs[i][j - 1];
        }
        F(j, 0, m) {
            cs[j][0] = !a[0][j];
            F(i, 1, n) cs[j][i] = !a[i][j] + cs[j][i - 1];
        }
        ll ans = 16;
        F(i, 0, n) F(j, 0, m) {
            F(i2, i + 4, n) {
                F(j2, j + 3, m) {
                    ll md = s[i2 - 1][j2 - 1] - s[i][j2 - 1] - s[i2 - 1][j] + s[i][j];
                    ll t = rs[i][j2 - 1] - rs[i][j], l = cs[j][i2 - 1] - cs[j][i];
                    if(md + t + l >= ans) goto loop;
                    ll b = rs[i2][j2 - 1] - rs[i2][j], r = cs[j2][i2 - 1] - cs[j2][i];
                    ans = min(ans, md + t + l + b + r);
                }
            loop:;
            }
        }
        cout << ans << '\n';
    }
}
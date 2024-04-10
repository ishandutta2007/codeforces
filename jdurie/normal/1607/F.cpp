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

typedef int ll;
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
#define N 4000010
#define S 2010

ll nxt[N], dp[N];
string s[S];

ll r(ll j) {
    vector<ll> path;
    set<ll> seen;
    ll i = j;
    while(1) {
        if(!~j) {
            F(i, 0, path.size()) dp[path[i]] = path.size() - i;
            break;
        }
        if(seen.count(j)) {
            ll ij = -1;
            F(i, 0, path.size()) {
                if(path[i] == j) ij = i;
                dp[path[i]] = ~ij ? path.size() - ij : path.size() - i;
            }
            break;
        }
        if(~dp[j]) {
            F(i, 0, path.size()) dp[path[i]] = dp[j] + path.size() - i;
            break;
        }
        path.push_back(j), seen.insert(j);
        j = nxt[j];
    }
    return dp[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> s[i];
        F(i, 0, n) F(j, 0, m) {
            ll i2 = i, j2 = j;
            if(s[i][j] == 'U') i2--; else if(s[i][j] == 'D') i2++; else if(s[i][j] == 'L') j2--; else j2++;
            if(i2 < 0 || j2 < 0 || i2 >= n || j2 >= m) nxt[i * m + j] = -1;
            else nxt[i * m + j] = i2 * m + j2;
        }
        fill_n(dp, n * m, -1);
        pl ans;
        F(i, 0, n * m) ans = max(ans, {r(i), i});
        cout << ans.V / m + 1 << ' ' << ans.V % m + 1 << ' ' << ans.K << '\n';
    }
}
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
#define N 5010

ll n, m, maxpref[N], minsuff[N], lcp[N][N];
string s, t;

ll glcp(ll i, ll j) {
    if(i == n || j == m) return 0;
    if(~lcp[i][j]) return lcp[i][j];
    return lcp[i][j] = s[i] == t[j] ? glcp(i + 1, j + 1) + 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m >> s >> t;
        F(i, 0, n + 1) F(j, 0, m + 1) lcp[i][j] = -1;
        ll id = 0, ans = n;
        F(i, 0, n) {
            if(id < m && s[i] == t[id]) id++;
            maxpref[i] = id;
            if(maxpref[i] == i + 1) ans = n - 1 - i;
        }
        id = 0;
        FD(i, n - 1, -1) {
            if(id < m && s[i] == t[m - 1 - id]) id++;
            minsuff[i] = id;
        }
        F(i, 1, n) F(j, 0, m) if(maxpref[i - 1] >= j && minsuff[i] >= m - j)
            ans = min(ans, n - glcp(i, j) + i - j + 1);
        cout << (maxpref[n - 1] == m ? ans : -1) << '\n';
    }
}
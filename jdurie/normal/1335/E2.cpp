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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010
#define A 200

ll a[N], pSum[N][A];
vector<ll> pos[A];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        ll ans = 0;
        F(i, 0, A) pos[i].clear();
        G(n) F(i, 1, n + 1) { 
            cin >> a[i]; a[i]--;
            F(j, 0, A) pSum[i][j] = pSum[i - 1][j];
            pSum[i][a[i]]++;
            pos[a[i]].push_back(i);
            ans = max(ans, (ll)pos[a[i]].size());
        }
        F(j, 0, A) {
            ll ct = pos[j].size();
            F(x, 0, ct / 2) {
                ll pL = pos[j][x], pR = pos[j][ct - 1 - x], mx = 0;
                F(k, 0, A) mx = max(mx, pSum[pR - 1][k] - pSum[pL][k]);
                ans = max(ans, 2 * (x + 1) + mx);
            }
        }
        cout << ans << '\n';
    }
}
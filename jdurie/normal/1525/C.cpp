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
#define N 300010

pair<pl, ll> a[N];
ll n, m, ans[N];

void solve(vector<pair<pl, ll>> v) {
    vector<pair<pl, ll>> v2;
    for(auto a : v) {
        if(v2.size() && a.K.V == 'L' && v2.back().K.V == 'R') {
            ans[a.V] = ans[v2.back().V] = (a.K.K - v2.back().K.K) / 2;
            v2.pop_back();
        } else if(v2.size() && a.K.V == 'L') {
            ans[a.V] = ans[v2.back().V] = (a.K.K + v2.back().K.K) / 2;
            v2.pop_back();
        } else v2.push_back(a);
    }
    for(ll i = (ll)v2.size() - 2; i >= 0; i -= 2)
        if(v2[i].K.V == 'R') ans[v2[i].V] = ans[v2[i + 1].V] = (2 * m - v2[i].K.K - v2[i + 1].K.K) / 2;
        else ans[v2[i].V] = ans[v2[i + 1].V] = (2 * m + v2[i].K.K - v2[i + 1].K.K) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> a[i].K.K, a[i].V = i, ans[i] = -1;
        F(i, 0, n) { GS(s) a[i].K.V = s[0]; }
        sort(a, a + n);
        vector<pair<pl, ll>> vo, ve;
        F(i, 0, n) if(a[i].K.K & 1) vo.push_back(a[i]); else ve.push_back(a[i]);
        solve(vo); solve(ve);
        F(i, 0, n) cout << ans[i] << ' ';
        cout << '\n';
    }
}
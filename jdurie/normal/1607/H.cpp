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

ll a[N], b[N], m[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        map<ll, vector<ll>> v;
        F(i, 0, n) { cin >> a[i] >> b[i] >> m[i]; v[a[i] + b[i] - m[i]].push_back(i); }
        ll tot = 0;
        for(auto& au : v) {
            sort(A(au.V), [&](ll i, ll j) {
                return (a[i] - max(0ll, m[i] - b[i])) < (a[j] - max(0ll, m[j] - b[j]));
            });
            ll cur = -M;
            for(ll i : au.V) {
                if(a[i] - cur > m[i]) {
                    tot++; ans[i] = max(0ll, m[i] - b[i]);
                    cur = a[i] - ans[i];
                } else ans[i] = a[i] - cur;
            }
        }
        cout << tot << '\n';
        F(i, 0, n) cout << ans[i] << ' ' << m[i] - ans[i] << '\n';
    }
}
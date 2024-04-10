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
#define N 100010
#define S 317ll

ll a[N], upd[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) ll mx = 0, ans = LLONG_MAX;
        F(i, 0, n) {
            cin >> a[i];
            vector<ll> opts;
            F(p, 1, min(k, S) + 1) if(a[i] / p >= S) opts.push_back(a[i] / p);
            F(v, 0, S) if(a[i] / min(k, (a[i] / (v + 1)) + 1) == v) opts.push_back(v);
            sort(A(opts));
            opts.push_back(LLONG_MAX);
            mx = max(mx, opts[0]);
            F(j, 0, (ll)opts.size() - 1) upd[opts[j]] = max(upd[opts[j]], opts[j + 1]);
        }
        F(mn, 0, N) {
            ans = min(ans, mx - mn);
            mx = max(mx, upd[mn]);
        }
        cout << ans << '\n';
        fill_n(upd, N, 0);
    }
}
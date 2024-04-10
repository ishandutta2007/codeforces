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
        G(n) G(mm) ll bal = 0;
        F(i, 0, n) {
            cin >> a[i] >> b[i];
            bal += a[i] - b[i];
            m[i] = mm;
            if(a[i] < mm) m[i] -= mm - a[i], bal += mm - a[i];
            if(b[i] < mm) m[i] -= mm - b[i], ans[i] += mm - b[i], bal -= mm - b[i];
        }
        //P(ans, n)
        //P(m, n)
        //cout << bal << '\n';
        F(i, 0, n) {
            ll k = (m[i] + bal) / 2;
            if(k < 0) k = 0; if(k > m[i]) k = m[i];
            ans[i] += k;
            bal -= k - (m[i] - k);
            //cout << k << ' ';
        }
        cout << abs(bal) << '\n';
        F(i, 0, n) cout << ans[i] << ' ' << mm - ans[i] << '\n', ans[i] = 0;
    }
}
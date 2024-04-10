//Codeforces Template
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

ll a[N], b[N], one[N], two[N], o, t, n, m;

ll bSearch(ll l, ll r, ll x) {
    if(l == r) return l;
    ll mm = (l + r) / 2;
    ll val = mm ? two[mm - 1] : 0;
    return val + x >= m ? bSearch(l, mm, x) : bSearch(mm + 1, r, x);
}

ll getAns(ll x) {
    if((t ? two[t - 1] : 0) + x < m) return LLONG_MAX / 100;
    return 2 * bSearch(0, t, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> a[i];
        F(i, 0, n) cin >> b[i];
        o = count(b, b + n, 1); t = n - o;
        ll oi = 0, ti = 0;
        F(i, 0, n) if(b[i] == 1) one[oi++] = a[i]; else two[ti++] = a[i];
        sort(one, one + o); sort(two, two + t);
        reverse(one, one + o); reverse(two, two + t);
        F(i, 1, t) two[i] += two[i - 1];
        ll ans = getAns(0), cur = 0;
        F(i, 0, o) {
            cur += one[i];
            ans = min(ans, i + 1 + getAns(cur));
        }
        cout << (ans >= LLONG_MAX / 100 ? -1 : ans) << '\n';
    }
}
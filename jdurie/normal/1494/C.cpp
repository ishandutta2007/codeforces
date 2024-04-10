#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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

typedef tree<ll, null_type, less<ll>,
rb_tree_tag, tree_order_statistics_node_update> set_t;

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
//#define N 100010

set_t sn[2], sm[2], d[2];

#define SN sn[idx]
#define SM sm[idx]
#define D d[idx]

bool works(ll idx, ll st, ll m) {
    return SN.order_of_key(st + m) >= m;
}

ll bsch(ll idx, ll st, ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works(idx, st, m) ? bsch(idx, st, m, r) : bsch(idx, st, l, m - 1);
}

ll getAns(ll idx) {
    ll ans = 0;
    for(ll x : SN) if(SM.find(x) != SM.end()) D.insert(x);
    for(ll x : SM) {
        ll ct = bsch(idx, x, 0, M);
        ans = max(ans, (ll)SM.order_of_key(x + ct) - SM.order_of_key(x) + D.size() - D.order_of_key(x + ct));
    }
    SN.clear(); SM.clear(); D.clear();
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) { G(x) if(x < 0) sn[0].insert(-x); else sn[1].insert(x); }
        F(i, 0, m) { G(x) if(x < 0) sm[0].insert(-x); else sm[1].insert(x); }
        cout << getAns(0) + getAns(1) << '\n';
    }
}
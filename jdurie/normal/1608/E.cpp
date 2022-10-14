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
typedef tree<pl, null_type, less<pl>,
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

set_t s[2][4];
vector<pl> q[2][4];
ll n;

bool worksSTK(ll k, ll t, ll a, ll b, ll c) {
    ll mnx = s[t][a].find_by_order(k - 1)->K;
    ll mxx = s[t][c].find_by_order(n / 3 - k)->K;
    return (ll)s[t][b].order_of_key({mxx, -M}) - (ll)s[t][b].order_of_key({mnx, M}) >= k;
}

ll stk(ll l, ll r, ll t, ll a, ll b, ll c) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return worksSTK(m, t, a, b, c) ? stk(m, r, t, a, b, c) : stk(l, m - 1, t, a, b, c);
}

bool works1(ll m, ll t, ll a, ll b, ll c) {
    ll mny = s[1 ^ t][a].find_by_order(m - 1)->K;
    vector<ll> sb, sc;
    for(pl p : q[t][b]) if(p.V > mny) sb.push_back(p.K);
    for(pl p : q[t][c]) if(p.V > mny) sc.push_back(p.K);
    if((ll)sb.size() < m || (ll)sc.size() < m) return false;
    return sb[m - 1] < sc[sc.size() - m];
}


ll bsch1(ll l, ll r, ll t, ll a, ll b, ll c) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works1(m, t, a, b, c) ? bsch1(m, r, t, a, b, c) : bsch1(l, m - 1, t, a, b, c);
}

bool works2(ll m, ll t, ll a, ll b, ll c) {
    ll mxy = s[1 ^ t][a].find_by_order(n / 3 - m)->K;
    vector<ll> sb, sc;
    for(pl p : q[t][b]) if(p.V < mxy) sb.push_back(p.K);
    for(pl p : q[t][c]) if(p.V < mxy) sc.push_back(p.K);
    if((ll)sb.size() < m || (ll)sc.size() < m) return false;
    return sb[m - 1] < sc[sc.size() - m];
}

ll bsch2(ll l, ll r, ll t, ll a, ll b, ll c) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works2(m, t, a, b, c) ? bsch2(m, r, t, a, b, c) : bsch2(l, m - 1, t, a, b, c);
}

ll dt(ll t, ll a, ll b, ll c) {
    return max(bsch1(0, n / 3, t, a, b, c), bsch2(0, n / 3, t, a, b, c));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; F(i, 0, n) {
        G(x) G(y) G(c)
        s[0][c].insert({x, y});
        s[1][c].insert({y, x});
    }
    F(t, 0, 2) F(c, 1, 4) for(pl x : s[t][c]) q[t][c].push_back(x);
    ll ans = 0;
    F(t, 0, 2) F(a, 1, 4) F(b, 1, 4) F(c, 1, 4)
        if(a - b && a - c && b - c) ans = max({ans, dt(t, a, b, c), stk(0, n / 3, t, a, b, c)});
    cout << 3 * ans << '\n';
}
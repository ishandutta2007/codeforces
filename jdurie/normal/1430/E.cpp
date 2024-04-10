#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

typedef tree<ll, null_type, less<ll>,
rb_tree_tag, tree_order_statistics_node_update> set_t;

vector<ll> a[256], b[256];
ll idx[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) GS(s)
    F(i, 0, n) a[s[i]].push_back(i), b[s[i]].push_back(n - 1 - i);
    F(i, 0, 256) reverse(A(b[i]));
    F(i, 'a', 'z' + 1) F(j, 0, a[i].size()) idx[b[i][j]] = a[i][j];
    ll ans = 0;
    set_t oset;
    F(i, 0, n) {
        ans += (oset.size() - oset.order_of_key(idx[i]));
        oset.insert(idx[i]);
    }
    cout << ans << '\n';
}
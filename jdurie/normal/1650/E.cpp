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

ll n, d, a[N];

bool works1(ll m) {
    bool tak = false; vector<ll> v = {0};
    F(i, 1, n + 1) if(!tak && a[i] - a[i - 1] - 1 < m) tak = true; else v.push_back(a[i]);
    bool spt = false;
    F(i, 1, v.size()) if(v[i] - v[i - 1] - 1 < m) return false;
    else if(v[i] - v[i - 1] - 1 >= 2 * m + 1) spt = true;
    if(d - v.back() > m) spt = true;
    return !tak || spt;
}

bool works2(ll m) {
    bool tak = false; vector<ll> v = {0};
    F(i, 1, n + 1) if(i - n && !tak && a[i + 1] - a[i] - 1 < m) tak = true; else v.push_back(a[i]);
    bool spt = false;
    F(i, 1, v.size()) if(v[i] - v[i - 1] - 1 < m) return false;
    else if(v[i] - v[i - 1] - 1 >= 2 * m + 1) spt = true;
    if(d - v.back() > m) spt = true;
    return !tak || spt;
}

ll bsch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return works1(m) || works2(m) ? bsch(m, r) : bsch(l, m - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> d;
        F(i, 1, n + 1) cin >> a[i];
        cout << bsch(0, d) << '\n';
    }
}
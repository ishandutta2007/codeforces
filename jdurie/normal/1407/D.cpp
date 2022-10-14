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
#define N 300010

ll n, h[N], ans[N];
vector<ll> stkG, stkL;

void process(vector<ll>& stk, ll i, ll k) {
    bool ok = true;
    while(stk.size() && k * h[stk.back()] >= k * h[i]) {
        ok = h[stk.back()] != h[i];
        ans[i] = min(ans[i], ans[stk.back()] + 1);
        stk.pop_back();
    }
    if(ok && stk.size()) ans[i] = min(ans[i], ans[stk.back()] + 1);
    stk.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    F(i, 0, n) cin >> h[i];
    stkG = {n - 1};
    stkL = {n - 1};
    FD(i, n - 2, -1) {
        ans[i] = n;
        process(stkG, i, 1);
        process(stkL, i, -1);
    }
    cout << ans[0] << '\n';
}
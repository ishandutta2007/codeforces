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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 10010

vector<ll> chil[N];
ll par[N], v[N], sz[N];
pl dp[N][110];
bool psmall = false;

#define ADD(pr, ch) chil[pr].push_back(ch), par[ch] = pr, ch++;

ll fillSz(ll i) {
    if(v[i]) return sz[i] = 0;
    return sz[i] = fillSz(chil[i][0]) + 1 + fillSz(chil[i][1]);
}

#define DP dp[i][mn]

pl getAns(ll i, ll mn);

void doThing(ll i, ll mn, ll nmn, bool b) {
    F(z, 0, nmn + 1) if(z <= sz[chil[i][0]] && nmn - z <= sz[chil[i][1]]) {
        pl lf = getAns(chil[i][0], z), rt = getAns(chil[i][1], nmn - z);
        if(b) DP.K = max(DP.K, lf.K + rt.K), DP.V = min(DP.V, lf.V + rt.V);
        else DP.K = max(DP.K, lf.K - rt.V), DP.V = min(DP.V, lf.V - rt.K);
    }
}

pl getAns(ll i, ll mn) {
    if(~DP.K || ~DP.V) return DP;
    if(v[i]) return DP = {v[i], v[i]};
    ll pls = psmall ? mn : sz[i] - mn, mns = sz[i] - pls;
    DP = {LLONG_MIN, LLONG_MAX};
    if(pls) doThing(i, mn, psmall ? mn - 1 : mn, true);
    if(mns) doThing(i, mn, psmall ? mn : mn - 1, false);
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    GS(s) G(p) G(m)
    psmall = p < m;
    if(!(p + m)) EX(s)
    ll n = s.size() - 2;
    s = s.substr(1, n);
    ll nd = 2, cur = 1;
    for(char c : s) {
        if(c == '?') continue;
        if(c == '(') { ADD(cur, nd) cur = nd - 1; }
        else if(c == ')') cur = par[cur];
        else { ADD(cur, nd) v[nd - 1] = c - '0'; }
    }
    fillSz(1);
    cout << getAns(1, min(m, p)).K << '\n';
}
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
#define N 3010

vector<ll> inds[N];
ll lsum[2][N], rsum[2][N], aaaa[N];

ll a(vector<ll>& v) {
    ll m = v.size();
    F(k, 0, 2) fill_n(lsum[k], m, 0), fill_n(rsum[k], m, 0);
    fill_n(aaaa, v.size(), 0);
    F(i, 0, m) {
        lsum[i & 1][i] += v[i];
        if(i) F(k, 0, 2) lsum[k][i] += lsum[k][i - 1];
    }
    FD(i, m - 1, -1) {
        rsum[i & 1][i] = v[i];
        if(i != m - 1) F(k, 0, 2) rsum[k][i] += rsum[k][i + 1];
    }
    FD(i, m - 1, -1) {
        aaaa[i] = rsum[1 - (i & 1)][i] * v[i];
        if(i < m - 2) aaaa[i] += aaaa[i + 2];
    }
    ll ans = 0;
    F(i, 0, m - 1) ans += lsum[1 - (1 & i)][i] * v[i] * aaaa[i + 1];
    return ans;
}

ll ch4(ll x) { return x * (x - 1) * (x - 2) * (x - 3) / 24; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 0, n) { G(x) inds[x].push_back(i); }
        ll ans = 0;
        F(i, 1, n + 1) ans += ch4(inds[i].size());
        F(i, 1, n + 1) F(j, 1, i) {
            vector<ll> v;
            ll iI = 0, iJ = 0, lst = -1;
            while(iI < inds[i].size() || iJ < inds[j].size()) {
                ll iCt = 0;
                while(iI < inds[i].size() && (iJ == inds[j].size() || inds[i][iI] < inds[j][iJ])) iCt++, iI++;
                if(iCt) {
                    if(lst == 0) v.back() += iCt;
                    else lst = 0, v.push_back(iCt);
                }
                ll jCt = 0;
                while(iJ < inds[j].size() && (iI == inds[i].size() || inds[j][iJ] < inds[i][iI])) jCt++, iJ++;
                if(jCt) {
                    if(lst == 1) v.back() += jCt;
                    else lst = 1, v.push_back(jCt);
                }
            }
            if(v.size()) ans += a(v);
        }
        cout << ans << '\n';
        F(i, 1, n + 1) inds[i].clear();
    }
}
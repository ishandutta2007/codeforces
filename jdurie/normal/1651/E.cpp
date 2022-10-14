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
#define N 3010
#define TRI(x) (((x) * ((x) + 1)) / 2)
#define OTH(x, v) (gr[x][0] + gr[x][1] - v)

vector<ll> gr[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, 2 * n) {
        G(u) G(v)
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    ll ans = 0;
    F(i, 1, n + 1) {
        ans += TRI(n) * i * (n - i + 1);
        sort(A(gr[i]));
        ans -= (TRI(gr[i][0] - n - 1) + TRI(gr[i][1] - gr[i][0] - 1) + TRI(2 * n - gr[i][1])) * i * (n - i + 1);
        F(k, 0, 2) {
            ll ci = i, mni = i, mxi = i, mnj = gr[i][k ^ 1], mxj = gr[i][k ^ 1], b = gr[i][k], l = gr[i][k];
            while(1) {
                ll nxtj = OTH(ci, l);
                mnj = min(mnj, nxtj), mxj = max(mxj, nxtj);
                if(b >= mnj && b <= mxj) break;
                ll nxti = OTH(nxtj, ci);
                mni = min(mni, nxti), mxi = max(mxi, nxti);
                ll b2 = OTH(nxti, nxtj);
                if((b2 < mnj || b2 > mxj) && i < nxti) {
                    ll lfe = n, rte = 2 * n + 1;
                    if(b < mnj) lfe = max(lfe, b); else rte = min(rte, b);
                    if(b2 < mnj) lfe = max(lfe, b2); else rte = min(rte, b2);
                    ans -= (mnj - lfe) * (rte - mxj) * mni * (n - mxi + 1);
                }
                ci = nxti; l = nxtj;
            }
        }
    }
    cout << ans << '\n';
}
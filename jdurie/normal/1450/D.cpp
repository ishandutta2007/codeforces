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
#define N 300010

ll a[N], mxp[N], prl[N], sfl[N], ans[N];
bool seen[N];
vector<ll> rmxp[N];
set<ll> okvals[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) 
        fill_n(ans, n + 1, 0); ans[1] = 1;
        fill_n(seen, n + 1, false);
        F(i, 0, n + 1) rmxp[i].clear();
        fill_n(mxp, n + 1, 0);
        F(i, 0, n + 1) okvals[i].clear();
        F(i, 0, n) {
            cin >> a[i];
            if(seen[a[i]]) ans[1] = 0;
            else seen[a[i]] = true;
        }
        prl[0] = -1;
        F(i, 1, n) {
            ll j = i - 1;
            while(~j && a[j] >= a[i]) j = prl[j];
            prl[i] = j;
        }
        sfl[n - 1] = n;
        FD(i, n - 2, -1) {
            ll j = i + 1;
            while(j - n && a[j] >= a[i]) j = sfl[j];
            sfl[i] = j;
        }
        F(i, 0, n) {
            if(prl[i] + 1 - i && i + 1 - sfl[i]) okvals[a[i]].insert(sfl[i] - prl[i] - 1);
            else if(prl[i] + 1 - i || i + 1 - sfl[i]) mxp[a[i]] = max(mxp[a[i]], abs(i - sfl[i]) + abs(i - prl[i]) - 1); 
        }
        F(i, 1, n + 1) rmxp[mxp[i]].push_back(i); 
        set<ll> bads, goods;
        FD(k, n, 1) {
            for(ll ai : rmxp[k]) bads.erase(ai), goods.insert(ai);
            if(!goods.count(n - k + 1)) bads.insert(n - k + 1);
            bool x = true;
            for(ll b : bads) if(!okvals[b].count(k)) { x = false; break; }
            ans[k] = x ? 1 : 0;
        }
        F(i, 1, n + 1) cout << ans[i];
        cout << '\n';
    }
}
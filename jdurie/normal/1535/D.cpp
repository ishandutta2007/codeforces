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

ll par[N], ans[N], lch[N], rch[N];
string s;

void upd(ll i) {
    if(s[i] == '?') ans[i] = ans[lch[i]] + ans[rch[i]];
    else if(s[i] == '0') ans[i] = ans[lch[i]];
    else ans[i] = ans[rch[i]];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(lch, N, N - 1);
    fill_n(rch, N, N - 1);
    G(k) cin >> s;
    vector<ll> lst(1 << (k - 1));
    iota(A(lst), 0ll);
    FD(i, k - 2, -1) {
        vector<ll> nxt(1 << i);
        iota(A(nxt), lst.back() + 1);
        F(j, 0, nxt.size()) {
            par[lst[2 * j]] = par[lst[2 * j + 1]] = nxt[j];
            lch[nxt[j]] = lst[2 * j];
            rch[nxt[j]] = lst[2 * j + 1];
        }
        lst = nxt;
    }
    fill_n(ans, N, 1);
    F(i, 0, (1 << k) - 1) upd(i);
    G(q) while(q--) {
        G(i) GS(c) i--;
        s[i] = c[0];
        while(1) {
            upd(i);
            if(i == (1 << k) - 2) break;
            i = par[i];
        }
        cout << ans[i] << '\n';
    }
}
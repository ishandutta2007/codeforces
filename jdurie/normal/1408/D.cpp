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
#define N 2010

pl r[N], s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) cin >> r[i].K >> r[i].V;
    F(i, 0, m) cin >> s[i].K >> s[i].V;
    sort(s, s + m); reverse(s, s + m);
    vector<pl> sl = {s[0]};
    F(i, 1, m) if(s[i].V > sl.back().V) sl.push_back(s[i]);
    sl.emplace_back(-1, 10000000);
    map<ll, ll> ans;
    ans[0] = 10;
    vector<pair<ll, pl>> events;
    F(j, 0, n) {
        bool b = false;
        F(i, 0, sl.size() - 1) if(r[j].V <= sl[i].V && r[j].K <= sl[i].K) {
            ll D = sl[i].K - r[j].K + 1;
            if(!b) ans[D]++, b = true;
            events.emplace_back(sl[i].V - r[j].V + 1, make_pair(D, max(0ll, sl[i + 1].K - r[j].K + 1)));
        }
    }
    sort(A(events));
    ll mx = ans.rbegin()->K, idx = 0;
    F(i, 1, 1000001) {
        while(idx < events.size() && events[idx].K == i) {
            if(!--ans[events[idx].V.K]) ans.erase(events[idx].V.K);
            ans[events[idx].V.V]++;
            idx++;
        }
        mx = min(i + ans.rbegin()->K, mx);
    }
    cout << mx << '\n';
}
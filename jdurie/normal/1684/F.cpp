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
 
ll n, m, a[N], rbd[N], lbd[N], l[N], r[N], nxt[N];
 
ll solve() {
    map<ll, ll> lst;
    rbd[n] = n;
    FD(i, n - 1, -1) {
        rbd[i] = rbd[i + 1]; nxt[i] = n;
        if(lst.count(a[i])) rbd[i] = min(rbd[i], lst[a[i]]), nxt[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    lbd[0] = -1; lst.clear();
    F(i, 1, n) {
        lbd[i] = lbd[i - 1];
        if(lst.count(a[i])) lbd[i] = max(lbd[i], lst[a[i]]);
        lst[a[i]] = i;
    }
    ll mxs = n, mxb = -1;
    vector<pl> bad; multiset<ll> ms;
    F(i, 0, m)
        if(rbd[l[i]] <= r[i]) {
            mxs = min(mxs, rbd[l[i]] + 1);
            bad.emplace_back(l[i], r[i]);
            mxb = max(mxb, lbd[r[i]]);
        }
    if(bad.empty()) return 0;
    sort(A(bad));
    ll idx = 0, mxr = 0, ans = n;
    map<ll, ll> pos;
    F(st, 0, mxs) {
        mxb = max(mxb, st);
        while(bad[idx].K == st) {
            mxr = max(mxr, bad[idx].V);
            idx++;
        }
        ans = min(ans, mxb - st + 1);
        pos[a[st]] = max(pos[a[st]], st);
        while(nxt[pos[a[st]]] <= mxr) { pos[a[st]] = nxt[pos[a[st]]]; mxb = max(mxb, pos[a[st]]); }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 0, n) cin >> a[i];
        F(i, 0, m) cin >> l[i] >> r[i], l[i]--, r[i]--;
        ll ans = solve();
        reverse(a, a + n);
        F(i, 0, m) { l[i] = n - 1 - l[i]; r[i] = n - 1 - r[i]; swap(l[i], r[i]); }
        cout << min(ans, solve()) << '\n';
    }
}
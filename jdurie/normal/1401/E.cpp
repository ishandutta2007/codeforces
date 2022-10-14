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
#define N 1000010

vector<pl> events;
typedef ll T;
pair<ll, pl> qs[N];
T id = 0, t[2 * N];
T f(T a, T b) { return a + b; }

void modify(ll p, T value) {  // set value at position p
    for (t[p += N] += value; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
}

T query(ll l, ll r) { // query on interval [l, r)
    T resl = id, resr = id;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) resl = f(resl, t[l++]);
        if (r & 1) resr = f(t[--r], resr);
    }
    return f(resl, resr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    ll ans = 1;
    F(i, 0, n) {
        G(y) G(l) G(r)
        if(!l && r == 1000000) ans++;
        events.emplace_back(l, y);
        events.emplace_back(r, -y);
    }
    sort(A(events));
    ll idx = 0;
    F(i, 0, m) cin >> qs[i].K >> qs[i].V.K >> qs[i].V.V;
    sort(qs, qs + m);
    F(i, 0, m) {
        if(!qs[i].V.K && qs[i].V.V == 1000000) ans++;
        vector<ll> temp;
        while(idx < events.size() && events[idx].K <= qs[i].K) {
            if(events[idx].V > 0) modify(events[idx].V, 1);
            else if(events[idx].K == qs[i].K) temp.push_back(-events[idx].V);
            else modify(-events[idx].V, -1);
            idx++;
        }
        ans += query(qs[i].V.K, qs[i].V.V + 1);
        for(ll x : temp) modify(x, -1);
    }
    cout << ans << '\n';
}
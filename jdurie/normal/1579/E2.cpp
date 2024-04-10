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
typedef pair<ll, ll> pl;

namespace sgtree {
    typedef ll T; //type
    #define N 200010 //size
    
    T id = 0, t[2 * N];

    T f(T a, T b) { return a + b; }

    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll a[n], b[n];
        for(int i = 0; i < n; i++) { cin >> a[i]; b[i] = a[i]; }
        sort(b, b + n);
        map<ll, ll> id;
        for(int i = 0; i < n; i++) id[b[i]] = i + 1;
        map<ll, ll> oc;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll left = sgtree::query(1, id[a[i]]);
            ll right = sgtree::query(id[a[i]] + 1, n+1);
            ans += min(left, right);
            oc[id[a[i]]]++;
            sgtree::modify(id[a[i]], oc[id[a[i]]]);
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; i++) sgtree::modify(i, 0);
    }
}
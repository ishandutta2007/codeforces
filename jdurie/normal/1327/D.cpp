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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

bool used[N];
vector<ll> v;
ll p[N], c[N];

bool tst(ll x) {
    F(m, 0, x) {
        bool ok = true;
        for(ll i = m; i < v.size(); i += x) if(v[i] - v[m]) { ok = false; break; }
        if(ok) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        fill(used, used + n + 1, 0);
        F(i, 1, n + 1) cin >> p[i];
        F(i, 1, n + 1) cin >> c[i];
        ll ans = LLONG_MAX;
        F(i, 1, n + 1) if(!used[i]) {
            v.clear();
            ll temp = i;
            while(!used[temp]) {
                used[temp] = true;
                v.push_back(c[temp]);
                temp = p[temp];
            }
            ll k = v.size();
            for(ll x = 1; x * x <= k; x++) if(!(k % x)) {
                if(tst(x)) ans = min(ans, x);
                if(tst(k / x)) ans = min(ans, k / x);
            }
        }
        cout << ans << '\n';
    }
}
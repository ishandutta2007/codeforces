#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

ll a[N], lMax[N], rMax[N], lDist[N], rDist[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n)
        F(i, 0, n) cin >> a[i];
        set<ll> s;
        ll mx = 0;
        F(i, 0, n) {
            lMax[i] = mx = max(mx, a[i]);
            s.insert(a[i]);
            lDist[i] = s.size();
        }
        mx = 0;
        s.clear();
        FD(i, n - 1, -1) {
            rMax[i] = mx = max(mx, a[i]);
            s.insert(a[i]);
            rDist[i] = s.size();
        }
        vector<pl> ans;
        F(i, 0, n - 1) {
            if(lMax[i] == i + 1 && lDist[i] == i + 1 && rMax[i + 1] == n - i - 1 && rDist[i + 1] == n - i - 1)
                ans.push_back({i + 1, n - i - 1});
        }
        cout << ans.size() << endl;
        for(pl p : ans) cout << p.K << " " << p.V << endl;
    }
}
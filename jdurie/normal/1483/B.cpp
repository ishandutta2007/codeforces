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
#define N 100010

ll a[N], p[N];
ll dsu(ll i) { return p[i] == i ? i : p[i] = dsu(p[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> a[i];
        iota(p, p + n, 0);
        set<pl> s;
        set<ll> used;
        vector<ll> ans;
        F(i, 0, n) if(__gcd(a[i], a[(i + 1) % n]) == 1) s.insert({i, (i + 1) % n});
        ll cur = 0;
        while(s.size()) {
            pl x = {cur, 0};
            pl q = x > *s.rbegin() ? *s.begin() : *s.lower_bound(x);
            if(used.count(q.K) || used.count(q.V) || __gcd(a[q.K], a[q.V]) - 1) s.erase(q);
            else {
                used.insert(q.V);
                s.erase(q);
                p[q.V] = p[(q.V + 1) % n];
                if(!used.count(q.K) && !used.count(dsu(q.V))) s.insert({q.K, dsu(q.V)});
                ans.push_back(q.V);
                cur = (q.V + 1) % n;
            }
        }
        cout << ans.size();
        for(ll x : ans) cout << ' ' << x + 1;
        cout << '\n';
    }    
}
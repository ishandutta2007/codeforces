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

ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        map<ll, ll> mp;
        F(i, 0, n) cin >> a[i], mp[a[i]]++;
        ll mx = 0, ops = k;
        while(mp.count(mx) || ops) {
            if(!mp.count(mx)) ops--;
            mx++;
        }
        mx = min(n, mx);
        vector<ll> rems;
        for(pl p : mp) if(p.K >= mx) rems.push_back(p.K);
        sort(A(rems), [&](ll x, ll y) { return mp[x] > mp[y]; });
        while(k && rems.size())
            if(k >= mp[rems.back()]) { k -= mp[rems.back()]; rems.pop_back(); }
            else break;
        cout << rems.size() << '\n';
    }
}
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
#define N 26

vector<pair<char, ll>> v;

ll queryR(ll l, ll r) {
    cout << "? 2 " << l << ' ' << r << endl;
    G(res) return res;
}

char queryC(ll i) {
    cout << "? 1 " << i << endl;
    GS(res) return res[0];
}

ll bsch(ll l, ll r, ll i) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return queryR(v[m].V, i) == m + 1 ? bsch(l, m, i) : bsch(m + 1, r, i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) ll d = 0;
    string ans;
    F(i, 1, n + 1) {
        if(queryR(1, i) > d)
            d++, ans.push_back(queryC(i));
        else {
            v.clear(); set<char> seen;
            FD(j, ans.size() - 1, -1) if(!seen.count(ans[j])) v.emplace_back(ans[j], j + 1), seen.insert(ans[j]);
            ans.push_back(v[bsch(0, v.size() - 1, i)].K);
        }
    }   
    cout << "! " << ans << endl;
}
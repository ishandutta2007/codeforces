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

ll adj, zadj, zct, n, a, b, c, maxjno, maxjnz;
string s;
vector<ll> gaps;

ll cost(ll x, ll y) {
    if(x > zct) return 0;
    if(y > x) {
        if(y - adj > maxjno) return 0;
    } else if(y - adj > maxjnz) return 0;
    if(y <= adj) {
        ll q = min(x, zadj);
        return y * b + q * a - (x - q) * c;
    }
    ll g = gaps[y - adj - 1];
    if(g > x) return 0;
    ll q = min(x - (y - adj), zadj);
    if(q < 0) return 0;
    return y * b + q * a - (x - q) * c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> a >> b >> c >> s;
        adj = zadj = maxjno = maxjnz = 0; gaps.clear();
        F(i, 1, n) if(s[i] == '1' && s[i - 1] == '1') adj++; else if(s[i] == '0' && s[i - 1] == '0') zadj++;
        zct = count(A(s), '0');
        ll cur = LLONG_MIN;
        for(char h : s) if(h == '1') {
            if(cur > 0) gaps.push_back(cur);
            cur = 0;
        } else cur++;
        sort(A(gaps));
        F(i, 1, gaps.size()) gaps[i] += gaps[i - 1];
        gaps.push_back(LLONG_MAX);
        while(adj + maxjno >= gaps[maxjno]) maxjno++;
        while(adj + maxjnz >= gaps[maxjnz] - 1) maxjnz++;
        gaps.pop_back();
        ll ans = 0;
        F(o, 0, n + 1) ans = max({ans, cost(o, o + 1), cost(o + 1, o), cost(o, o)});
        cout << ans << '\n';
    }
}
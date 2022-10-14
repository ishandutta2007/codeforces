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
#define N 300010
#define S 550

ll a[N], l[N], r[N], ans[N], ct[N], num[N], curAns = 0;

void update(ll i, ll d) {
    num[ct[a[i]]]--;
    ct[a[i]] += d;
    num[ct[a[i]]]++;
    if(num[curAns + 1]) curAns++;
    if(!num[curAns]) curAns--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 1, n + 1) cin >> a[i];
    num[0] = N;
    vector<ll> q;
    F(i, 0, m) cin >> l[i] >> r[i], q.push_back(i);
    sort(A(q), [](ll i, ll j) {
        if(l[i] / S - l[j] / S) return l[i] / S < l[j] / S;
        return l[i] / S % 2 ? r[i] > r[j] : r[i] < r[j];
    });
    ll cL = 0, cR = -1;
    for(ll i : q) {
        while(cL > l[i]) update(--cL, 1);
        while(cR < r[i]) update(++cR, 1);
        while(cL < l[i]) update(cL++, -1);
        while(cR > r[i]) update(cR--, -1);
        ans[i] = max(1ll, 2 * curAns - (r[i] - l[i] + 1));
    }
    F(i, 0, m) cout << ans[i] << '\n';
}
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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

namespace sgtree {
    typedef ll T;
    T id = 0, t[2 * N];

    T f(T a, T b) { return max(a, b); }

    void modify(ll l, ll r, T value) {
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) { t[l] = f(t[l], value); l++; }
            if (r & 1) { r--; t[r] = f(t[r], value); }
        }
    }

    T query(ll p) {
        T res = 0;
        for (p += N; p > 0; p >>= 1) res = f(res, t[p]);
        return res;
    }
}

vector<ll> pos[N];
ll n, a[N], prev[N];

void doMods(ll x) {
    if(pos[x].empty()) { sgtree::modify(0, n, n); return; }
    sgtree::modify(0, pos[x][0] + 1, pos[x][0]);
    F(i, 0, (ll)pos[x].size() - 1)
        sgtree::modify(pos[x][i] + 1, pos[x][i + 1] + 1, pos[x][i + 1]);
    sgtree::modify(pos[x].back() + 1, n, n);
}

bool doQueries(ll x) {
    if(pos[x].empty()) return sgtree::query(0) < n;
    if(sgtree::query(0) < pos[x][0]) return true;
    F(i, 0, (ll)pos[x].size() - 1) if(sgtree::query(pos[x][i] + 1) < pos[x][i + 1]) return true;
    if(sgtree::query(pos[x].back()) < n) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; F(i, 0, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    if(count(a, a + n, 1) == n) EX(1)
    doMods(1);
    F(j, 2, n + 5) {
        if(!doQueries(j)) EX(j)
        doMods(j);
    }
}
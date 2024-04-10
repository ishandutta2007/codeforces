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
#define N 500010

vector<ll> a[N], bf[N], sf[N], bb[N], sb[N]; 
ll x[N], y[N];

#define TOG(v) { if(s.count(v)) s.erase(v); else s.insert(v); }

#define RESET F(i, 0, n) a[i].clear(), bf[i].clear(), sf[i].clear(), bb[i].clear(), sb[i].clear();

void solve() {
    G(n) G(m)
    F(i, 0, n) F(j, 0, m) { G(v) a[i].push_back(v); }
    iota(x, x + n, 0ll); iota(y, y + n, 0ll);
    sort(x, x + n, [&](ll i, ll j) { return a[i][0] < a[j][0]; });
    sort(y, y + n, [&](ll i, ll j) { return a[i][m - 1] > a[j][m - 1]; });
    F(i, 0, n) F(j, 0, m) {
        sf[i].push_back(a[x[i]][j]), sb[i].push_back(a[y[i]][m - 1 - j]);
        if(j) sf[i][j] = max(sf[i][j], sf[i][j - 1]), sb[i][j] = min(sb[i][j], sb[i][j - 1]);
        if(i) sf[i][j] = max(sf[i][j], sf[i - 1][j]), sb[i][j] = min(sb[i][j], sb[i - 1][j]);
    }
    FD(i, n - 1, -1) F(j, 0, m) {
        bb[i].push_back(a[y[i]][m - 1 - j]), bf[i].push_back(a[x[i]][j]);
        if(j) bb[i][j] = max(bb[i][j], bb[i][j - 1]), bf[i][j] = min(bf[i][j], bf[i][j - 1]);
        if(i - n + 1) bb[i][j] = max(bb[i][j], bb[i + 1][j]), bf[i][j] = min(bf[i][j], bf[i + 1][j]);
    }
    set<ll> s;
    F(t, 0, n - 1) {
        TOG(x[t]) TOG(y[t])
        if(s.empty()) F(j, 0, m - 1)
            if(sf[t][j] < bf[t + 1][j] && sb[t][m - 2 - j] > bb[t + 1][m - 2 - j]) {
                string ans(n, 'R');
                F(z, 0, t + 1) ans[x[z]] = 'B';
                cout << "YES\n";
                cout << ans << ' ' << j + 1 << '\n';
                RESET
                return;
            }
    }
    RESET
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) solve();
}
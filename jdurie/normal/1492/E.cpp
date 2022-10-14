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

typedef int ll;
typedef vector<ll> vl;
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
#define N 250010

vl a[N], b[N], fx;
set<ll> diff[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) F(j, 0, m) { G(x) a[i].push_back(x); }
    F(j, 0, m) {
        bool ok = true;
        F(i, 1, n) if(a[i][j] - a[0][j]) ok = false;
        if(ok) fx.push_back(j);
        else F(i, 0, n) b[i].push_back(a[i][j]);
    }
    if((ll)fx.size() >= m - 2) {
        cout << "Yes\n";
        F(j, 0, m) cout << a[0][j] << ' ';
        cout << '\n';
        exit(0);
    }
    ll k = b[0].size();
    if(k > 2 * n) {
        cout << "No\n";
        exit(0);
    }
    F(i, 1, n) F(j, 0, k) if(b[i][j] - b[0][j]) diff[i].insert(j);
    F(p1, 0, k) F(p0, 0, p1) {
        bool ok = true;
        ll v0 = -1, v1 = -1;
        map<ll, ll> m0, m1;
        set<pl> aaaa;
        ll edges = 0;
        F(i, 1, n) {
            ll bdi = diff[i].size();
            if(diff[i].count(p0)) bdi--;
            if(diff[i].count(p1)) bdi--;
            pl p = {b[i][p0], b[i][p1]};
            if(!bdi) continue;
            else if(bdi > 2) { ok = false; break; }
            else if(bdi == 2) {
                if(!~v0) v0 = b[i][p0], v1 = b[i][p1];
                else if(v0 - b[i][p0] || v1 - b[i][p1]) { ok = false; break; }
            } else if(!aaaa.count(p)) m0[b[i][p0]]++, m1[b[i][p1]]++, aaaa.insert(p), edges++;
        }
        if(ok && ~v0) {
            F(i, 1, n) {
                ll bdi = diff[i].size();
                if(diff[i].count(p0)) { if(b[i][p0] == v0) bdi--; }
                else if(b[i][p0] - v0) bdi++;
                if(diff[i].count(p1)) { if(b[i][p1] == v1) bdi--; }
                else if(b[i][p1] - v1) bdi++;
                if(bdi > 2) { ok = false; break; }
            }
        } else if(ok && m0.size()) {
            pl m1p = *m1.rbegin();
            bool good = false;
            for(pl p : m0) {
                ll reee = aaaa.count({p.K, m1p.K}) ? 1 : 0;
                if(p.V == edges) { good = true; v0 = p.K; break; }
                else if(p.V == edges - 1) {
                    v0 = p.K;
                    for(pl aa : aaaa) if(aa.K - p.K) v1 = aa.V;
                    good = true;
                    break;
                } else if(p.V + m1p.V - reee == edges) { good = true; v0 = p.K; v1 = m1p.K; break; }
            }
            if(!good) ok = false;
        }
        if(ok) {
            cout << "Yes\n";
            ll idx = 0, fidx = 0;
            F(i, 0, m)
                if(fidx < fx.size() && fx[fidx] == i) cout << a[0][fx[fidx++]] << ' ';
                else if(idx == p0) cout << max(v0, 1) << ' ', idx++;
                else if(idx == p1) cout << max(v1, 1) << ' ', idx++;
                else cout << b[0][idx++] << ' ';
            cout << '\n';
            exit(0);
        }
    }
    cout << "No\n";
}
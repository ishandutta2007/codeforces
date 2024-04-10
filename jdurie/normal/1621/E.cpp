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

namespace sgtree {
    typedef ll T;
    T id = 7, t[2 * N];

    T f(T a, T b) { return a & b; }

    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
    }

    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = f(resl, t[l++]);
            if(r & 1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }
}

ll t[N], id[N], tot[N];
pair<ll, pl> sg[N];
vector<ll> grp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(m) G(n)
        F(i, 0, m) cin >> t[i];
        sort(t, t + m);
        F(i, m - n, m) t[i - m + n] = t[i];
        F(i, 0, n) {
            G(k) sg[i].V.V = i;
            F(j, 0, k) { G(x) grp[i].push_back(x); sg[i].V.K += x; }
            sg[i].K = (sg[i].V.K + k - 1) / k;
        }
        sort(sg, sg + n);
        F(i, 0, n) {
            ll j = sg[i].V.V;
            id[j] = i;
            ll msk = 0;
            if(sg[i].K <= t[i]) msk++;
            if(i && sg[i].K <= t[i - 1]) msk += 2;
            if(i + 1 < n && sg[i].K <= t[i + 1]) msk += 4;
            sgtree::modify(i, msk);
        }
        F(j, 0, n) {
            ll i = id[j];
            for(ll x : grp[j]) {
                ll nwavg = (sg[i].V.K - x + grp[j].size() - 2) / (grp[j].size() - 1);
                if(nwavg <= sg[i].K) {
                    pair<ll, pl> query = pair<ll, pl>{nwavg, pl{0, 0}};
                    ll q = lower_bound(sg, sg + n, query) - sg;
                    bool b1 = (sgtree::query(0, q) & 1);
                    bool b2 = (sgtree::query(i + 1, n) & 1);
                    bool b3 = (sgtree::query(q, i) & 4);
                    bool b4 = (nwavg <= t[q]);
                    cout << b1 * b2 * b3 * b4;
                } else {
                    pair<ll, pl> query = pair<ll, pl>{nwavg, pl{LLONG_MAX, LLONG_MAX}};
                    ll q = upper_bound(sg, sg + n, query) - sg;
                    bool b1 = (sgtree::query(0, i) & 1);
                    bool b2 = (sgtree::query(q, n) & 1);
                    bool b3 = (sgtree::query(i + 1, q) & 2);
                    bool b4 = (nwavg <= t[q - 1]);
                    cout << b1 * b2 * b3 * b4;
                }
            }
        }
        cout << '\n';
        F(j, 0, n) grp[j].clear(), sg[j] = {0, {0, 0}}, tot[j] = 0;
    }
}
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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define DO_POLL(q) auto a = *q.rbegin(); q.erase(a);      \
                   sm -= a.K.K;                           \
                   a.V.V /= 2;                            \
                   a.K.K = a.V.K * ((a.V.V + 1) / 2);     \
                   q.insert(a);                           \

vector<pair<ll, pl>> tree[N];
pl parW[N];
ll sz[N];

ll dfs(ll i, ll p) {
    sz[i] = tree[i].size() == 1 ? 1 : 0;
    for(auto j : tree[i])
        if(j.K - p) sz[i] += dfs(j.K, i);
        else parW[i] = j.V;
    return sz[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(S)
        F(i, 0, n - 1) {
            G(u) G(v) G(w) G(c)
            tree[u].emplace_back(v, make_pair(w, c));
            tree[v].emplace_back(u, make_pair(w, c));
        }
        dfs(1, 1);
        set<pair<pl, pl>> q1, q2, q1x, q2x;
        ll sm = 0, ans = 0, ansx = 1, origSm = 0;
        F(i, 2, n + 1) {
            sm += sz[i] * parW[i].K;
            pair<pl, pl> p = {{ sz[i] * ((parW[i].K + 1) / 2), i }, { sz[i], parW[i].K }};
            if(parW[i].V == 1) q1.insert(p), q1x.insert(p);
            else q2.insert(p), q2x.insert(p);
        }
    
        origSm = sm;
        if(!q1x.empty()) { DO_POLL(q1x) }
        else ansx = 10000000000000ll;
        while(sm > S) {
            ll g2 = q2x.empty() ? 0 : q2x.rbegin()->K.K;
            ll g1 = q1x.empty() ? 0 : q1x.rbegin()->K.K, delt = 0;
            if(g1) {
                auto a = *q1x.rbegin();
                delt = max((q1x.size() > 1 ? (++q1x.rbegin())->K.K : 0), a.V.K * ((a.V.V / 2 + 1) / 2));
                g1 += delt;
            }
            ansx += 2;
            if(g2 >= g1) { DO_POLL(q2x) }
            else { DO_POLL(q1x) if(delt) { DO_POLL(q1x) }}
        }
        sm = origSm;
        while(sm > S) {
            ll g2 = q2.empty() ? 0 : q2.rbegin()->K.K;
            ll g1 = q1.empty() ? 0 : q1.rbegin()->K.K, delt = 0;
            if(g1) {
                auto a = *q1.rbegin();
                delt = max((q1.size() > 1 ? (++q1.rbegin())->K.K : 0), a.V.K * ((a.V.V / 2 + 1) / 2));
                g1 += delt;
            }
            ans += 2;
            if(g2 >= g1) { DO_POLL(q2) }
            else { DO_POLL(q1) if(delt) { DO_POLL(q1) }}
        }
        cout << min(ans, ansx) << '\n';
        F(i, 1, n + 1) tree[i].clear();
    }
}
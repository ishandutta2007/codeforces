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
#define NO { if(!done) done = true, cout << "NO\n"; }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 510

ll n;
pl a[N], b[N];
vector<pl> ops;
bool done;

void doop(ll i, ll j) {
    ops.emplace_back(i, j + 1);
    reverse(a + i, a + j + 1);
    F(k, i, j + 1) swap(a[k].K, a[k].V);
}

void solve(ll i) {
    pl p = b[i], q = {p.V, p.K};
    vector<ll> v;
    F(j, i, n) if(a[j] == q) {
        doop(i, j);
        return;
    } else if(a[j] == p) v.emplace_back(j);
    if(v.empty()) NO
    else if(v.size() > 1) {
        doop(i, v[1] - 1);
        solve(i);
    } else {
        F(j, i, v[0]) F(k, v[0], n)
            if(a[j].K == a[k].V) {
                doop(j, k);
                solve(i);
                return;
            }
        NO
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n; ops.clear(); done = false;
        F(i, 0, n) cin >> a[i].K;
        F(i, 0, n) cin >> b[i].K;
        n--;
        F(i, 0, n) a[i].V = a[i + 1].K, b[i].V = b[i + 1].K;
        F(i, 0, n) 
            if(a[i].K - b[i].K) { NO break; }
            else if(a[i].V - b[i].V && !done) solve(i);
        if(!done) {
            cout << "YES\n" << ops.size() << '\n';
            for(pl p : ops) cout << p.K + 1 << ' ' << p.V + 1 << '\n';
        }
    }
}
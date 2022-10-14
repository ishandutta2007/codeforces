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

namespace sgtree {
    typedef ll T;
    T id = 0, t[2 * N];

    T f(T a, T b) { return a + b; }

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

vector<ll> ids[9];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        F(i, 0, 9) ids[i].clear();
        GS(s) ll n = s.size(); G(w) G(m)
        F(i, 0, n) sgtree::modify(i, s[i] - '0');
        F(i, 0, n - w + 1) ids[sgtree::query(i, i + w) % 9].push_back(i);
        while(m--) {
            G(l) G(r) G(k)
            ll v = sgtree::query(l - 1, r);
            pl ans = {M, M};
            F(i, 0, 9) F(j, 0, 9) if((i * v + j) % 9 == k && i - j && ids[i].size() && ids[j].size())
                ans = min(ans, pl{ids[i][0], ids[j][0]});
            F(i, 0, 9) if((i * v + i) % 9 == k && ids[i].size() >= 2)
                ans = min(ans, pl{ids[i][0], ids[i][1]});
            if(ans.K == M) cout << "-1 -1\n";
            else cout << ans.K + 1 << ' ' << ans.V + 1 << '\n';
        }
    }
}
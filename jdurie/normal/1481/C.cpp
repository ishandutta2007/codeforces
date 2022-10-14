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

ll a[N], b[N], ans[N], col[N];
vector<ll> need[N], fxed[N], unfxed;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> a[i];
        F(i, 0, n) cin >> b[i];
        F(i, 0, n)
            if(a[i] == b[i]) fxed[a[i]].push_back(i);
            else need[b[i]].push_back(i), unfxed.push_back(i);
        F(i, 0, m) cin >> col[i];
        bool ok = true;
        F(i, 0, m) {
            ll c = col[i];
            while(unfxed.size() && a[unfxed.back()] == b[unfxed.back()]) unfxed.pop_back();
            if(need[c].size()) { ans[i] = need[c].back(); need[c].pop_back(); fxed[c].push_back(ans[i]); }
            else if(fxed[c].size()) ans[i] = fxed[c].back();
            else if(unfxed.size()) ans[i] = unfxed.back();
            else if(fxed[col[m - 1]].size()) {
                ans[i] = fxed[col[m - 1]].back();
                unfxed.push_back(ans[i]);
                need[col[m - 1]].push_back(ans[i]);
                fxed[col[m - 1]].pop_back();
            } else ok = false;
            a[ans[i]] = c;
        }
        F(i, 0, n) if(a[i] - b[i]) ok = false;
        if(ok) {
            cout << "YES\n";
            F(i, 0, m) cout << ans[i] + 1 << ' ';
            cout << '\n';
        } else cout << "NO\n";
        F(i, 1, n + 1) need[i].clear(), fxed[i].clear();
        unfxed.clear();
    }
}
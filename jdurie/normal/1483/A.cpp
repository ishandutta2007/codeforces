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

vector<ll> lists[N];
ll ct[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, m) {
            G(k) while(k--) { G(x) lists[i].push_back(x); }
            ct[lists[i][0]]++;
        }
        ll maxc = 1;
        F(i, 2, n + 1) if(ct[i] > ct[maxc]) maxc = i;
        F(i, 0, m) {
            if(lists[i][0] - maxc || ct[maxc] <= (m + 1) / 2 || lists[i].size() == 1) ans[i] = lists[i][0];
            else ans[i] = lists[i][1], ct[maxc]--;
        }
        if(ct[maxc] > (m + 1) / 2) cout << "NO\n";
        else {
            cout << "YES\n";
            F(i, 0, m) cout << ans[i] << ' ';
            cout << '\n';
        }
        F(i, 0, m) lists[i].clear();
        F(i, 1, n + 1) ct[i] = ans[i] = 0;
    }
}
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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
typedef tree<ll, null_type, less<ll>,
rb_tree_tag, tree_order_statistics_node_update> set_t;

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
//#define N 200010

set_t oset;
deque<ll> pos[128];

#define FIX(c) pos[c].front() + (oset.size() - oset.order_of_key(pos[c].front()))

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) GS(s) GS(t)
        F(i, 0, n) pos[s[i]].push_back(i);
        F(c, 'a', 'z' + 1) pos[c].push_back(1e16);
        ll ans = LLONG_MAX, cur = 0;
        F(i, 0, n) {
            F(c, 'a', 'z' + 1) {
                while(FIX(c) < i) pos[c].pop_front();
                if(c < t[i]) ans = min(ans, cur + FIX(c) - i);
            }
            if(pos[t[i]].front() < n) {
                cur += FIX(t[i]) - i;
                oset.insert(pos[t[i]].front());
                pos[t[i]].pop_front();
            } else break;
        }
        cout << (ans > 1e12 ? -1 : ans) << '\n';
        oset.clear();
        F(c, 'a', 'z' + 1) pos[c].clear();
    }
}
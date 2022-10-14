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
#define M 1000000000000000000ll //998244353
//#define N 100010

ll p10[18];
set_t st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p10[0] = 1;
    F(i, 1, 18) p10[i] = 10 * p10[i - 1];
    F(i, 0, 18) F(j, 0, i) F(k, 0, j)
        F(a, 0, 10) F(b, 0, 10) F(c, 0, 10)
            st.insert(a * p10[i] + b * p10[j] + c * p10[k]);
    st.insert(M);
    G(tc) while(tc--) {
        G(l) G(r)
        cout << st.order_of_key(r + 1) - st.order_of_key(l) << '\n';
    }
}
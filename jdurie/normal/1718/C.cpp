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

ll n, prime[N], sm[6][N], a[N];
multiset<ll> ms[6];
vector<ll> p;

ll ans() {
    ll ans = 0;
    F(j, 0, p.size()) ans = max(ans, *ms[j].rbegin() * n / p[j]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime[0] = prime[1] = 1;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = i;
        for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
    }
    G(tc) while(tc--) {
        cin >> n; G(q) ll t = n;
        while(t > 1) {
            ll qq = prime[t];
            p.push_back(qq);
            while(!(t % qq)) t /= qq;
        }
        F(i, 0, n) {
            cin >> a[i];
            F(j, 0, p.size()) sm[j][i % (n / p[j])] += a[i];
        }
        F(j, 0, p.size()) F(i, 0, n / p[j]) ms[j].insert(sm[j][i]);
        cout << ans() << '\n';
        while(q--) {
            G(i) G(x) i--;
            F(j, 0, p.size()) {
                ms[j].erase(ms[j].find(sm[j][i % (n / p[j])]));
                sm[j][i % (n / p[j])] -= a[i];
            }
            a[i] = x;
            F(j, 0, p.size()) {
                sm[j][i % (n / p[j])] += a[i];
                ms[j].insert(sm[j][i % (n / p[j])]);
            }
            cout << ans() << '\n';
        }
        F(i, 0, 6) fill_n(sm[i], n, 0), ms[i].clear();
        p.clear();
    }
}
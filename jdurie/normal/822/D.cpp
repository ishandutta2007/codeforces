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
#define N 5000010

ll f[N], prime[N];

ll pw(ll a, ll p) { return p ? pw(a * a % M, p / 2) * (p & 1 ? a : 1) % M : 1; }

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

int main() {
    prime[0] = prime[1] = 1;
    F(i, 2, N) {
        if(!prime[i]) {
        prime[i] = i;
        for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
        }f[i] = (i * (prime[i] - 1) / 2 + f[i / prime[i]]) % M;}
    G(t) G(l) G(r)
    //sP(f, 10)
    ll ans = 0;
    F(k, l, r + 1) ans = (ans + pw(t, k - l) * f[k]) % M;
    cout << ans << '\n';
}


/*

ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> a[i];
        vector<ll> b; set<ll> s;
        ll cr = 1;
        while(b.size() < n) {
            bool ok = true;
            F(i, 0, n) if(s.count(a[i] + cr)) ok = false;
            if(!ok) cr++;
            else {
                b.push_back(cr);
                F(i, 0, n) if(s.count(a[i] + cr)) EX("NO") else s.insert(a[i] + cr);
            }
            if(cr > 100000) break;
        }
        if(b.size() < n || b.back() > 1000000) EX("NO");
        cout << "YES\n";
        for(ll x : b) cout << x << ' ';
        cout << '\n';
    }
}*/
//Codeforces Template
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
#define N 1010

using u128 = ll;//__uint128_t;

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

map<ll, vector<ll>> plist;
vector<ll> notpw, oknotpw;
ll x[N];

ll pw(ll a, ll p) { return p ? a * pw(a, p - 1) : 1; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(k)
    F(i, 0, n) {
        cin >> x[i];
        ll xpw = -1;
        F(p, 1, 100) {
            if(x[i] >> p) {
                ld y = (ll)round(powl((ld)x[i], 1 / (ld)p));
                F(z, y - 10, y + 10)
                    if(pw(z, p) == x[i] && MillerRabin(z)) xpw = z;
            }
        }
        if(~xpw) plist[xpw].push_back(x[i]);
        else notpw.push_back(x[i]);
    }
    vector<ll> rlist;
    for(auto a : plist) if(a.V.size() < 2) rlist.push_back(a.K);
    for(ll r : rlist) plist.erase(r);
    ll bestSpare = -1;
    set<ll> bstSet;
    for(ll z : notpw) {
        ll temp = z;
        set<ll> eee;
        for(auto a : plist) while(!(temp % a.K)) temp /= a.K, eee.insert(a.K);
        if(temp == 1) {
            oknotpw.push_back(z);
            if(eee.size() < bstSet.size() || bstSet.empty()) bestSpare = z, bstSet = eee;
        }
    }
    vector<ll> ans;
    bool flag = false;
    //cout << plist << '\n';
    ll reeeee = -1;
    if(k & 1) {
        for(auto& a : plist) if(a.V.size() >= 3) {
            F(i, 0, 3) ans.push_back(a.V.back()), a.V.pop_back();
            reeeee = a.K;
            break;
        }
        if(ans.empty()) {
            if(bstSet.size() && k >= 1 + 2 * bstSet.size()) {
                ans.push_back(bestSpare);
                flag = true;
                for(ll e : bstSet) F(j, 0, 2) ans.push_back(plist[e].back()), plist[e].pop_back();
            } else EX(0)
        }
    }
    //cout << plist << '\n';
    for(auto& a : plist) if(ans.size() + 2 <= k && a.V.size() >= 2 && a.K - reeeee)
        F(i, 0, 2) ans.push_back(a.V.back()), a.V.pop_back();
    //cout << plist << '\n';
    for(auto& a : plist) while(ans.size() < k && a.V.size()) ans.push_back(a.V.back()), a.V.pop_back();
    //cout << plist << '\n';
    for(ll x : oknotpw) {
        if(flag && x == bestSpare) { flag = false; continue; }
        if(ans.size() < k) ans.push_back(x);
    }
    if(ans.size() != k) EX(0)
    F(i, 0, k) cout << ans[i] << ' ';
}
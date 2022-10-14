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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << '\n'; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 400010
#define L 20

ll n = 2, last = 0, mx[N][L], nxt[N][L], pathSum[N][L], par[N][L], maxLen[N];

ll pSum(ll r, ll steps) {
    ll sum = 0;
    FD(i, L - 1, -1) if(steps >> i) {
        sum += pathSum[r][i];
        r = nxt[r][i];
        steps -= (1 << i);
    }
    return sum;
}

ll bSearch(ll l, ll r, ll n, ll w) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return pSum(n, m) <= w ? bSearch(m, r, n, w) : bSearch(l, m - 1, n, w);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    maxLen[1] = 1;
    F(i, 0, L) par[1][i] = nxt[1][i] = 1;
    G(q) while(q--) {
        G(t) G(r) G(x)
        r ^= last, x ^= last;
        if(t == 1) {
            par[n][0] = r;
            F(i, 1, L) par[n][i] = par[par[n][i - 1]][i - 1];
            mx[n][0] = x;
            F(i, 1, L) mx[n][i] = max(mx[n][i - 1], mx[par[n][i - 1]][i - 1]);
            nxt[n][0] = r;
            FD(i, L - 1, -1) if(mx[nxt[n][0]][i] < x) nxt[n][0] = par[nxt[n][0]][i];
            maxLen[n] = (nxt[n][0] == 1 && x) ? 1 : maxLen[nxt[n][0]] + 1;
            F(i, 1, L) nxt[n][i] = nxt[nxt[n][i - 1]][i - 1];
            pathSum[n][0] = x;
            F(i, 1, L) pathSum[n][i] = pathSum[n][i - 1] + pathSum[nxt[n][i - 1]][i - 1];
            n++;
            //F(i, 1, n) cout << nxt[i][0] << ' ';
            //P(maxLen, n)
        } else {
            /*if(r == 3) {
                cout << "COCK" << r << "  " << x << '\n';
                cout << maxLen[r] << '\n';
                F(i, 0, 3) cout << pathSum[r][i] << ' '; cout << '\n';
                F(i, 0, 5) cout << pSum(r, i) << ' ';
                cout << '\n';
            }*/
            cout << (last = bSearch(0, maxLen[r], r, x)) << '\n';
        }
    }
}
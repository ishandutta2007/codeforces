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
typedef pair<ll, int> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(int i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1048575
#define N 300010
#define S 150

namespace sgtree {
    typedef ll T;
    T t[2 * N];

    void modify(int p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = t[2 * p] + t[2 * p + 1];
    }

    T query(int l, int r) { //query on interval [l, r)
        T res = 0;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) res += t[l++];
            if(r & 1) res += t[--r];
        }
        return res;
    }  
}

mt19937 gen(__builtin_ia32_rdtsc());
uniform_int_distribution<int> dist(1, N - 1);

bool seen[N];

int main() {
    int n, x;
    scanf("%d", &n); ll ans = 0; 
    while(n--) {
        scanf("%d", &x);
        //x = dist(gen);
        F(j, 1, S) {
            ll p = sgtree::query(x / (j + 1) + 1, x / j + 1);
            ans += (p & M) * x + (1 - j) * (p >> 20);
        }
        F(j, 1, x / S + 1) if(seen[j]) ans += j + x % j;
        F(j, 1, S) {
            if(j * x >= N) break;
            ll p = sgtree::query(j * x, min(N, (j + 1) * x));
            ans += (p >> 20) + (1 - j) * (p & M) * x;
        }
        F(j, S * x, N) if(seen[j]) ans += x + j % x;
        printf("%lld ", ans);
        sgtree::modify(x, (((ll)x) << 20) + 1), seen[x] = true;
    }
    printf("\n");
}
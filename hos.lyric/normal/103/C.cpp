//  Codeforces Beta Round #80

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

Int N, K;
int Q;

int solve(Int x) {
    if (K == 0) return 0;
    if (K == N) return 1;
    if (x == 0) return 0;
    if (x == N - 1) return 1;
    if (N % 2 == 0) {
        if (K <= N / 2) {
            if (x % 2 == 0) return 0;
            Int d = (N - 1 - x) / 2;
            if (d < K) return 1;
            return 0;
        } else {
            if (x % 2 == 1) return 1;
            Int d = x / 2;
            if (d < N - K) return 0;
            return 1;
        }
    } else {
        if (K <= N / 2) {
            if (x % 2 == 0) return 0;
            Int d = (N - 2 - x) / 2;
            if (d < K - 1) return 1;
            return 0;
        } else {
            if (x % 2 == 1) return 1;
            Int d = x / 2;
            if (d < N - K) return 0;
            return 1;
        }
    }
}

int main() {
    int q;
    Int x;
    
//*
    for (; cin >> N >> K >> Q; ) {
        for (q = 0; q < Q; ++q) {
            cin >> x;
            --x;
//*/
//N=in();for(K=0;K<=N;++K){Q=N;for(q=0;q<Q;++q){x=q;
            int ans = solve(x);
            putchar(".X?"[ans]);
        }
        puts("");
    }
    
    return 0;
}
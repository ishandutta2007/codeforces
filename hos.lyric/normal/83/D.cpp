//  Codeforces Beta Round #72

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

const Int LIM = 4000005;
int isnp[4000010];
int maxp[4000010];
int meb[4000010];
int psLen;
int ps[1000010];

void prpr() {
    Int i, j;
    for (i = 2; i * i < LIM; ++i) if (!isnp[i]) {
        for (j = i * i; j < LIM; j += i) isnp[j] = i;
    }
    for (i = 1; i < LIM; ++i) meb[i] = 1;
    for (i = 2; i < LIM; ++i) if (!isnp[i]) {
        for (j = i; j < LIM; j += i) maxp[j] = i;
    }
    for (i = 2; i < LIM; ++i) if (!isnp[i]) {
        for (j = i; j < LIM; j += i) {
            if (j / i % i == 0) meb[j] = 0;
            meb[j] *= -1;
        }
    }
//pv(meb,meb+31);
    for (i = 2; i < LIM; ++i) if (!isnp[i]) {
        ps[psLen++] = i;
    }
}

Int A, B, K;

Int brute() {
    Int x, y;
    Int ret = 0;
    for (x = A; x <= B; ++x) {
        for (y = 2; y <= K; ++y) {
            if (x % y == 0) break;
        }
        if (y == K) ++ret;
    }
    return ret;
}

Int solveSlow(Int m) {
    Int ret = 0;
    Int d;
    for (d = 1; d * K <= m; ++d) if (maxp[d] < K) {
        ret += m / (d * K) * meb[d];
    }
    return ret;
}

set<Int> vis;
Int dfs(Int t, Int sig, int i) {
//cout<<"dfs "<<m<<" "<<t<<" "<<sig<<" "<<i<<endl;
    if (B < t * K) return 0;
    Int ret = 0;
    if (vis.insert(t).second) {
//cout<<"add "<<t<<" "<<sig<<endl;
        ret += B / (t * K) * sig - (A - 1) / (t * K) * sig;
    }
    if (ps[i] < K) {
        ret += dfs(t, sig, i + 1);
        ret += dfs(t * ps[i], -sig, i + 1);
    }
    return ret;
}
Int solve() {
    vis.clear();
    Int ret = dfs(1, +1, 0);
    return ret;
}

int main() {
    int tmA, tmB, tmK;
    
    prpr();
    
    for (; ~scanf("%d%d%d", &tmA, &tmB, &tmK); ) {
        A = tmA;
        B = tmB;
        K = tmK;
//cout<<A<<" "<<B<<" "<<K<<" : ";
//cout<<"brute = "<<brute()<<endl;
        Int ans = 0;
        Int n = K, d;
        for (d = 2; d * d <= n; ++d) if (n % d == 0) {
            puts("0");
            goto failed;
        }
        if (K < 500) {
            ans += solve();
        } else {
            ans += solveSlow(B);
            ans -= solveSlow(A - 1);
        }
        cout << ans << endl;
    failed:;
    }
    
    return 0;
}
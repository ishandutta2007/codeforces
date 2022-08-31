//  Codeforces Beta Round #19
//  Problem B

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

const Int INF = 1001001001001001001LL;
void chmin(Int &t, Int f) { if (t > f) t = f; }

const int LIM = 4005;

int N;
int T[2010];
Int C[2010];
Int dp[4010];

int main() {
    int i, j;
    
    N = in();
    for (i = 0; i < N; ++i) {
        T[i] = in() + 1;
        C[i] = in();
    }
    
    for (j = 0; j <= LIM; ++j) {
        dp[j] = INF;
    }
    dp[0] = 0;
    for (i = 0; i < N; ++i) {
        for (j = LIM; j >= T[i]; --j) {
            chmin(dp[j], dp[j - T[i]] + C[i]);
        }
    }
    
    Int ans = INF;
    for (j = N; j <= LIM; ++j) {
        chmin(ans, dp[j]);
    }
    cout << ans << endl;
    
    return 0;
}
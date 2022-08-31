//  Codeforces Beta Round #9
//  Problem D

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

int N, H;
Int dp[40][40];

int main() {
    int n, i, a, b;
    
    N = in();
    H = in();
    dp[0][0] = 1;
    for (n = 1; n <= N; ++n) {
        for (i = 0; i < n; ++i) {
            for (a = 0; a < N; ++a) for (b = 0; b < N; ++b) {
                dp[n][max(a, b) + 1] += dp[i][a] * dp[n - 1 - i][b];
            }
        }
    }
    
    Int ans = 0;
    for (a = H; a <= N; ++a) ans += dp[N][a];
    cout << ans << endl;
    
    return 0;
}
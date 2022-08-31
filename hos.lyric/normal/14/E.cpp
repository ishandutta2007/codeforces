//  Codeforces Beta Round #14
//  Problem E

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

int N, T;
Int dp[30][30][10][10];

int main() {
    int i, j, a, b;
    int jj, c;
    
    N = in();
    T = in();
    dp[0][0][0][0] = 1;
    for (i = 0; i < N; ++i) for (j = 0; j <= T; ++j) {
        for (a = 0; a <= 4; ++a) for (b = 0; b <= 4; ++b) if (dp[i][j][a][b]) {
//printf("dp[%d][%d][%d][%d] = %lld\n",i,j,a,b,dp[i][j][a][b]);
            for (c = 1; c <= 4; ++c) {
                jj = j;
                if (b == c) continue;
                if (i == 1 && b > c) continue;
                if (i == N - 1 && b < c) continue;
                if (a < b && b > c) ++jj;
                dp[i + 1][jj][b][c] += dp[i][j][a][b];
            }
        }
    }
    
    Int ans = 0;
    for (a = 0; a <= 4; ++a) for (b = 0; b <= 4; ++b) {
        ans += dp[N][T][a][b];
    }
    cout << ans << endl;
    
    return 0;
}
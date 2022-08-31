//  Codeforces Beta Round #2
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

const int INF = 1001001001;

int N;
int A[1010][1010];
int dp[2][1010][1010];

int main() {
    int x, y;
    int a, e2, e5;
    
    N = in();
    for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
        A[x][y] = in();
    }
    
    for (x = 0; x < N; ++x) dp[0][x][N] = dp[1][x][N] = INF;
    for (x = 0; x < N - 1; ++x) dp[0][x][N] = dp[1][x][N] = INF;
    for (y = 0; y < N - 1; ++y) dp[0][N][y] = dp[1][N][y] = INF;
    
    for (x = N; x--; ) for (y = N; y--; ) {
        if (A[x][y]) {
            e2 = __builtin_ctz(A[x][y]);
            for (a = A[x][y], e5 = 0; a % 5 == 0; a /= 5, ++e5);
        } else {
            e2 = e5 = 1;
        }
        dp[0][x][y] = e2 + min(dp[0][x][y + 1], dp[0][x + 1][y]);
        dp[1][x][y] = e5 + min(dp[1][x][y + 1], dp[1][x + 1][y]);
    }
    
    int im = (dp[0][0][0] <= dp[1][0][0]) ? 0 : 1;
    
    if (dp[im][0][0] > 1) {
        for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
            if (!A[x][y]) {
                puts("1");
                for (int i = x; i--; ) putchar('D');
                for (int i = y; i--; ) putchar('R');
                for (int i = N - 1 - x; i--; ) putchar('D');
                for (int i = N - 1 - y; i--; ) putchar('R');
                puts("");
                return 0;
            }
        }
    }
    
    printf("%d\n", dp[im][0][0]);
    for (x = 0, y = 0; x < N - 1 || y < N - 1; ) {
        if (dp[im][x][y + 1] <= dp[im][x + 1][y]) {
            putchar('R');
            ++y;
        } else {
            putchar('D');
            ++x;
        }
    }
    puts("");
    
    return 0;
}
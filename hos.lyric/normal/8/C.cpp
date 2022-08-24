//  Codeforces Beta Round #8
//  Problem C

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

const int INF = 1001001001;
bool chmin(int &t, int f) { return (t > f) ? (t = f, 1) : 0; }
bool chmax(int &t, int f) { return (t < f) ? (t = f, 1) : 0; }

int N, L;
int SX, SY, X[30], Y[30];
int cs[30], ds[30][30];
int dp[0x100000a];
int prev[0x100000a];

int main() {
    int h, i, j;
    
    SX = in();
    SY = in();
    N = in();
    L = 1 << N;
    for (i = 0; i < N; ++i) {
        X[i] = in() - SX;
        Y[i] = in() - SY;
        cs[i] = X[i] * X[i] + Y[i] * Y[i];
    }
    for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) {
        ds[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
    }
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (h = 1; h < L; ++h) {
        for (i = 0; i < N; ++i) if (h & 1 << i) break;
        if (chmin(dp[h], dp[h ^ 1 << i] + cs[i] + cs[i])) {
            prev[h] = -i;
        }
        for (j = i + 1; j < N; ++j) if (h & 1 << j) {
            if (chmin(dp[h], dp[h ^ 1 << i ^ 1 << j] + cs[i] + ds[i][j] + cs[j])) {
                prev[h] = i * N + j;
            }
        }
    }
    printf("%d\n", dp[L - 1]);
    for (h = L - 1; h; ) {
        if (prev[h] <= 0) {
            i = -prev[h];
            printf("0 %d ", i + 1);
            h ^= 1 << i;
        } else {
            i = prev[h] / N;
            j = prev[h] % N;
            printf("0 %d %d ", i + 1, j + 1);
            h ^= 1 << i ^ 1 << j;
        }
    }
    puts("0");
    
    return 0;
}
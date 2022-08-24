//  Codeforces Beta Round #16
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

int N;
double P[20][20];
double dp[300010][20];

int main() {
    int h, i, j, k;
    int den;
    
    N = in();
    for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) {
        scanf("%lf", &P[i][j]);
    }
    
    for (h = 1; h < 1 << N; ++h) {
        if (h & h - 1) {
            den = __builtin_popcount(h);
            den = den * (den - 1) / 2;
            for (i = 0; i < N; ++i) if (h & 1 << i) for (j = 0; j < i; ++j) if (h & 1 << j) {
                for (k = 0; k < N; ++k) {
                    dp[h][k] += (P[i][j] * dp[h ^ 1 << j][k] + P[j][i] * dp[h ^ 1 << i][k]) / den;
                }
            }
        } else {
            for (k = 0; k < N; ++k) {
                dp[h][k] = (h & 1 << k) ? 1.0 : 0.0;
            }
        }
    }
    for (k = 0; k < N; ++k) {
        if (k) putchar(' ');
        printf("%.6f", dp[(1 << N) - 1][k]);
    }
    puts("");
    
    return 0;
}
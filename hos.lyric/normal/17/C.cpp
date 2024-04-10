//  Codeforces Beta Round #17
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

const int MO = 51123987;

void pl(int &t, int f) { if ((t += f) >= MO) t -= MO; }

int M, N;
char S[160];
int K, is[160][160][160];
int to[600010][3];
int dp[9][600010];

int main() {
    int i;
    int a, b, c;
    int z, x, y, s;
    
    scanf("%d%s", &M, S);
    N = unique(S, S + M) - S;
    for (a = 0; a <= M; ++a) for (b = 0; a + b <= M; ++b) for (c = 0; a + b + c <= M; ++c) {
        is[a][b][c] = ++K;
    }
    for (a = 0; a <= M; ++a) for (b = 0; a + b <= M; ++b) for (c = 0; a + b + c <= M; ++c) {
        to[is[a][b][c]][0] = is[a + 1][b][c];
        to[is[a][b][c]][1] = is[a][b + 1][c];
        to[is[a][b][c]][2] = is[a][b][c + 1];
    }
    dp[0][is[0][0][0]] = 1;
    for (i = 0; i < N; ++i) {
        s = S[i] - 'a';
        for (x = 0; x <= 8; ++x) if (~x & 1 << s) {
            for (z = 1; z <= K; ++z) if (dp[x][z]) {
                pl(dp[8][to[z][s]], dp[x][z]);
            }
        }
        for (x = 0; x <= 8; ++x) if (~x & 1 << s) {
            y = x & 7 | 1 << s;
            for (z = 1; z <= K; ++z) if (dp[x][z]) {
                pl(dp[y][z], dp[x][z]);
                dp[x][z] = 0;
            }
        }
    }
    
    int ans = 0;
    for (a = 0; a <= M; ++a) for (b = 0; a + b <= M; ++b) for (c = 0; a + b + c <= M; ++c) {
        if (a + b + c == M && abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1) {
            for (x = 0; x < 8; ++x) {
                pl(ans, dp[x][is[a][b][c]]);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
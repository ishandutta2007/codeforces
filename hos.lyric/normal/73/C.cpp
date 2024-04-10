//  Codeforces Beta Round 66

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int INF = 1001001001;
const int L = 26;

char S[110];
int K;
int N;
int C[110][110];
int dp[110][30][110];

int main() {
    int i, j, k, jj, kk;
    int u, v;
    
    for (; ~scanf("%s", S); ) {
        K = in();
        N = in();
        memset(C, 0, sizeof(C));
        for (; N--; ) {
            u = in_c() - 'a';
            v = in_c() - 'a';
            C[u][v] = in();
        }
        memset(dp, 0xc0, sizeof(dp));
        dp[0][L][K] = 0;
        for (i = 0; S[i]; ++i) for (j = 0; j <= L; ++j) for (k = 0; k <= K; ++k) {
            for (jj = 0; jj < L; ++jj) {
                kk = (S[i] - 'a' == jj) ? k : (k - 1);
                if (kk >= 0) {
                    chmax(dp[i + 1][jj][kk], dp[i][j][k] + C[j][jj]);
                }
            }
        }
        int ans = -INF;
        for (j = 0; j <= L; ++j) for (k = 0; k <= K; ++k) {
            chmax(ans, dp[i][j][k]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
//  Codeforces Beta Round #90

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

const double INF = 1e+10;

int N, K, L;
double A[110];
int M;
int B[110][110];

bool used[110];
int asLen;
double as[110];

int main() {
    int i, j, m;
    
    for (; ~scanf("%d%d", &N, &K); ) {
        L = N / K;
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        M = in();
        for (m = 0; m < M; ++m) {
            for (j = 0; j < L; ++j) {
                B[m][j] = in() - 1;
            }
        }
        double sho = +INF, dai = -INF;
        for (m = 0; m < M; ++m) {
            double sum = 0.0;
            for (j = 0; j < L; ++j) {
                sum += A[B[m][j]];
            }
            chmin(sho, sum / L);
            chmax(dai, sum / L);
        }
        memset(used, 0, sizeof(used));
        for (m = 0; m < M; ++m) {
            for (j = 0; j < L; ++j) {
                used[B[m][j]] = 1;
            }
        }
        asLen = 0;
        for (i = 0; i < N; ++i) if (!used[i]) {
            as[asLen++] = A[i];
        }
        sort(as, as + asLen);
        if (asLen >= N / K + (N - N / K * K)) {
            chmin(sho, accumulate(as, as + L, 0.0) / L);
            chmax(dai, accumulate(as + asLen - L, as + asLen, 0.0) / L);
        }
        printf("%.10f %.10f\n", sho, dai);
    }
    
    return 0;
}
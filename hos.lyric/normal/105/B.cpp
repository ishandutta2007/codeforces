//  Codeforces Beta Round #81

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

int N, K;
double A;
double B[20], L[20];
double sumB[1010];
double probB[1010];

double ps[20];
double dp[1010];
double ans;

void dping() {
    int i, h;
    memset(dp, 0, sizeof(dp[0]) * (1 << N));
    dp[0] = 1.0;
    for (i = 0; i < N; ++i) {
        for (h = 0; h < 1 << i; ++h) {
            dp[h | 1 << i] = dp[h] * (1.0 - ps[i]);
            dp[h] *= ps[i];
        }
    }
    double tmp = 0.0;
    for (h = 0; h < 1 << N; ++h) {
        tmp += dp[h] * probB[h];
    }
//cout<<"tmp = "<<tmp<<"  ; ";pv(ps,ps+N);
    chmax(ans, tmp);
}
void dfs(int i, int kLeft) {
    if (i == N) {
        dping();
        return;
    }
    int k;
    for (k = 0; k <= kLeft; ++k) {
        ps[i] = min(L[i] + 0.1 * k, 1.0);
        dfs(i + 1, kLeft - k);
    }
}

int main() {
    int i, h;
    
    for (; ~scanf("%d%d%lf", &N, &K, &A); ) {
        for (i = 0; i < N; ++i) {
            B[i] = in();
            L[i] = in() / 100.0;
        }
        for (i = 0; i < N; ++i) {
            for (h = 0; h < 1 << i; ++h) {
                sumB[h | 1 << i] = sumB[h] + B[i];
            }
        }
//cout<<"sumB : ";pv(sumB,sumB+(1<<N));
        for (h = 0; h < 1 << N; ++h) {
            probB[h] = ((N - __builtin_popcount(h)) * 2 > N) ? 1.0 : (A / (A + sumB[h]));
        }
//cout<<"probB : ";pv(probB,probB+(1<<N));
        ans = 0.0;
        dfs(0, K);
        printf("%.10f\n", ans);
    }
    
    return 0;
}
//  Yandex.Algorithm 2011 Qual 2

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

const int INF = 1001001001;

#define MAXN 1010

#define chmini(a,b) else if ((a) == (b))

int N;
int A[MAXN];
int dp[MAXN][MAXN];

void output(int a) { printf("%d\n", a + 1); }
void output(int a, int b) { if (a > b) swap(a, b); printf("%d %d\n", a + 1, b + 1); }

int main() {
    int i, j;
    int ii, jj;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        if (N == 1) {
            printf("%d\n", A[0]);
            output(0);
            continue;
        }
        memset(dp, 0x3f, sizeof(dp));
        {
            i = N;
            chmin(dp[i][i], 0);
            for (j = 0; j < i; ++j) {
                chmin(dp[i][j], A[j]);
            }
        }
        {
            i = N - 1;
            chmin(dp[i][i], A[i]);
            for (j = 0; j < i; ++j) {
                chmin(dp[i][j], max(A[i], A[j]));
            }
        }
        {
            i = N - 2;
            chmin(dp[i][i], max(A[i], A[i + 1]));
        }
        for (i = N - 2; i >= 0; --i) {
            if (i < N - 2) {
                chmin(dp[i][i], max(A[i + 0], A[i + 1]) + dp[i + 3][i + 2]);
                chmin(dp[i][i], max(A[i + 0], A[i + 2]) + dp[i + 3][i + 1]);
                chmin(dp[i][i], max(A[i + 1], A[i + 2]) + dp[i + 3][i + 0]);
            }
            for (j = 0; j < i; ++j) {
                chmin(dp[i][j], max(A[i + 0], A[i + 1]) + dp[i + 2][  j  ]);
                chmin(dp[i][j], max(A[i + 0], A[  j  ]) + dp[i + 2][i + 1]);
                chmin(dp[i][j], max(A[i + 1], A[  j  ]) + dp[i + 2][i + 0]);
            }
        }
//cout<<"====="<<endl;for(i=0;i<N;++i)pv(dp[i],dp[i]+i+1);cout<<"====="<<endl;
        printf("%d\n", dp[0][0]);
        for (i = 0, j = 0; ; ) {
            if (i == N) {
                if (i == j) {
                    break;
                } else {
                    output(j);
                    break;
                }
            } else if (i == N - 1) {
                if (i == j) {
                    output(i);
                    break;
                } else {
                    output(i, j);
                    break;
                }
            } else if (i == N - 2 && i == j) {
                output(i, i + 1);
                break;
            } else {
                if (i == j) {
                    if (0) {}
                    chmini(dp[i][i], max(A[i + 0], A[i + 1]) + dp[i + 3][i + 2]) {
                        output(i + 0, i + 1);
                        ii = i + 3;
                        jj = i + 2;
                    }
                    chmini(dp[i][i], max(A[i + 0], A[i + 2]) + dp[i + 3][i + 1]) {
                        output(i + 0, i + 2);
                        ii = i + 3;
                        jj = i + 1;
                    }
                    chmini(dp[i][i], max(A[i + 1], A[i + 2]) + dp[i + 3][i + 0]) {
                        output(i + 1, i + 2);
                        ii = i + 3;
                        jj = i + 0;
                    }
                } else {
                    if (0) {}
                    chmini(dp[i][j], max(A[i + 0], A[i + 1]) + dp[i + 2][  j  ]) {
                        output(i + 0, i + 1);
                        ii = i + 2;
                        jj =   j  ;
                    }
                    chmini(dp[i][j], max(A[i + 0], A[  j  ]) + dp[i + 2][i + 1]) {
                        output(i + 0,   j  );
                        ii = i + 2;
                        jj = i + 1;
                    }
                    chmini(dp[i][j], max(A[i + 1], A[  j  ]) + dp[i + 2][i + 0]) {
                        output(i + 1,   j  );
                        ii = i + 2;
                        jj = i + 0;
                    }
                }
            }
            i = ii;
            j = jj;
        }
    }
    
    return 0;
}
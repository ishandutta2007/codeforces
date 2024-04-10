//  Codeforces Beta Round #68

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

int N, T;
int SA, SB;
char dirB[110];
char P[210];
int posB[210];
int dp[210][110];

int main() {
    int i;
    int x, dx, xx;
    
    for (; ~scanf("%d", &N); ) {
        SA = in();
        SB = in();
        scanf("%s", dirB);
        scanf("%s", dirB);
        scanf("%s", P);
        T = strlen(P);
        posB[0] = SB;
        int sig = !strcmp(dirB, "head") ? -1 : +1;
        for (i = 0; i < T; ++i) {
            if (posB[i] == N) sig = -1;
            if (posB[i] == 1) sig = +1;
            posB[i + 1] = posB[i] + sig;
        }
        for (x = 1; x <= N; ++x) {
            dp[T - 1][x] = (x == posB[T - 1]) ? (T - 1) : INF;
        }
        for (i = T - 2; i >= 0; --i) for (x = 1; x <= N; ++x) {
            if (x == posB[i]) {
                dp[i][x] = i;
            } else {
                dp[i][x] = i;
                if (P[i] == '0') {
                    for (dx = -1; dx <= +1; ++dx) {
                        xx = min(max(x + dx, 1), N);
                        if (xx != posB[i]) {
                            chmax(dp[i][x], dp[i + 1][xx]);
                        }
                    }
                } else {
                    for (xx = 1; xx <= N; ++xx) {
                        chmax(dp[i][x], dp[i + 1][xx]);
                    }
                }
            }
        }
//for(i=0;i<T;++i)pv(dp[i]+1,dp[i]+N+1);
        if (dp[0][SA] >= INF) {
            puts("Stowaway");
        } else {
            printf("Controller %d\n", dp[0][SA]);
        }
    }
    
    return 0;
}
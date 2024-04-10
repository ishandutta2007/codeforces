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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAXN 160
const int INF = 1001001001;

int N;
int A[MAXN];
char S[MAXN];
int dp[MAXN][MAXN][MAXN];
int DP[MAXN][MAXN][MAXN];

int main() {
    int h, i, j, k;
    int a;
    
    for (; ~scanf("%d", &N); ) {
        for (a = 1; a <= N; ++a) {
            A[a] = in();
        }
        scanf("%s", S);
        A[0] = 0;
        for (a = 1; a <= N; ++a) {
            if (A[a] < 0) {
                A[a] = -INF;
            }
        }
        memset(dp, 0xc0, sizeof(dp));
        memset(DP, 0xc0, sizeof(DP));
        for (h = 0; h <= N; ++h) {
            for (i = 0, j = h; j <= N; ++i, ++j) {
                for (a = 0; a <= N - h; ++a) {
                    int &hos = dp[i][j][a];
                    int &HOS = DP[i][j][a];
                    chmax(hos, dp[i][j][0]);
                    chmax(hos, dp[i + 1][j][a]);
                    chmax(hos, dp[i][j - 1][a]);
                    for (k = i + 1; k < j; ++k) {
                        chmax(hos, dp[i][k][0] + dp[k][j][0]);
                        chmax(hos, DP[i][k][a] + DP[k][j][0]);
                        chmax(hos, DP[i][k][0] + DP[k][j][a]);
                        chmax(HOS, DP[i][k][a] + DP[k][j][0]);
                        chmax(HOS, DP[i][k][0] + DP[k][j][a]);
                    }
                    if (h <= 1) {
                        chmax(hos, A[a + h]);
                        chmax(HOS, A[a + h]);
                    } else if (S[i] == S[j - 1]) {
                        chmax(hos, DP[i + 1][j - 1][a + 2]);
                        chmax(HOS, DP[i + 1][j - 1][a + 2]);
                    }
                    chmax(hos, DP[i][j][0] + A[a]);
                    chmax(HOS, DP[i][j][0] + A[a]);
                }
            }
        }
        printf("%d\n", dp[0][N][0]);
    }
    
    return 0;
}
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

const int MO = 1000000007;
void add(int &t, int f) { if ((t += f) >= MO) t -= MO; }

int M, N;
char S[5010], T[5010];
int dp[5010][5010];

int main() {
    int i, j;
    
    for (; ~scanf("%s%s", S, T); ) {
        M = strlen(S);
        N = strlen(T);
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < M; ++i) {
            int sum = 1;
            for (j = 0; j < N; ++j) {
                if (S[i] == T[j]) {
                    add(dp[i + 1][j], sum);
                }
                add(sum, dp[i][j]);
            }
        }
// for(i=0;i<=M;++i)pv(dp[i],dp[i]+N);
        int ans = 0;
        for (i = 1; i <= M; ++i) {
            for (j = 0; j < N; ++j) {
                add(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
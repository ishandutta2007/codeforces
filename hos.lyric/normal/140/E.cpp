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

const int LIM = 5005;

Int P;
int N, M;
int L[1000010];

Int dp[5010][5010];
Int ps[5010], fac[5010];
Int DP[2][5010];

void dping() {
    int i, j;
    dp[0][0] = 1;
    for (i = 0; i < LIM; ++i) {
        for (j = 0; j <= i; ++j) {
            if (j) {
                (dp[i + 1][j] += dp[i][j] * (j - 1)) %= P;
            }
            (dp[i + 1][j + 1] += dp[i][j]) %= P;
        }
//if(i<10)pv(dp[i],dp[i]+10);
    }
}

int main() {
    int i, j;
    
    N = in();
    M = in();
    P = in();
    for (i = 0; i < N; ++i) {
        L[i] = in();
    }
    
    dping();
    ps[0] = fac[0] = 1;
    for (j = 1; j < LIM; ++j) {
        ps[j] = ps[j - 1] * (M + 1 - j) % P;
        fac[j] = fac[j - 1] * j % P;
    }
    
    for (j = 1; j <= L[0]; ++j) {
        DP[1][j] = dp[L[0]][j] * ps[j] % P;
    }
    for (i = 1; i < N; ++i) {
        int i0 = i & 1;
        int i1 = i0 ^ 1;
        Int sum = 0;
        for (j = 1; j <= L[i - 1]; ++j) {
            sum += DP[i0][j];
        }
        sum %= P;
        for (j = 1; j <= L[i]; ++j) {
            DP[i1][j] = sum * (dp[L[i]][j] * ps[j] % P) % P;
            if (j <= L[i - 1]) {
                (DP[i1][j] -= DP[i0][j] * (dp[L[i]][j] * fac[j] % P)) %= P;
            }
        }
    }
    Int ans = 0;
    for (j = 1; j <= L[N - 1]; ++j) {
        ans += DP[N & 1][j];
    }
    ans %= P;
    ans += P;
    ans %= P;
    cout << ans << endl;
    
    return 0;
}
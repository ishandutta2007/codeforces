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

bool isLucky(int x) {
    if (!(x % 10 == 4 || x % 10 == 7)) return 0;
    if (x < 10) return 1;
    return isLucky(x / 10);
}

#define MAXN 100010

int N, K;
int A[MAXN];

int M;
Int B[MAXN];

const Int MO = 1000000007;
Int inv[MAXN], fac[MAXN], fnv[MAXN];

Int dp[MAXN];

int main() {
    int i, j;
    
    for (; ~scanf("%d%d", &N, &K); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        sort(A, A + N);
        M = 0;
        for (i = 0; i < N; i = j) {
            for (j = i; j < N && A[i] == A[j]; ++j);
            if (isLucky(A[i])) {
                B[M++] = j - i;
            } else {
                for (int reps = j - i; reps--; ) {
                    B[M++] = 1;
                }
            }
        }
        sort(B, B + M);
//cout<<"B : ";pv(B,B+M);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (i = 0; i < M; ++i) if (B[i] > 1) {
            for (j = N; j >= 1; --j) {
                dp[j] = (dp[j] + dp[j - 1] * B[i]) % MO;
            }
        }
//cout<<"dp : ";pv(dp,dp+N+1);
        
        fac[0] = fnv[0] = 1;
        for (i = 1; i <= N; ++i) {
            inv[i] = (i == 1) ? 1 : (MO - (MO / i) * inv[MO % i] % MO);
            fac[i] = fac[i - 1] * i % MO;
            fnv[i] = fnv[i - 1] * inv[i] % MO;
        }
        int cnt1 = count(B, B + M, 1);
        Int ans = 0;
        for (i = 0; i <= cnt1 && i <= K; ++i) {
            Int tmp = dp[K - i];
            tmp = (tmp * fac[cnt1]) % MO;
            tmp = (tmp * fnv[cnt1 - i]) % MO;
            tmp = (tmp * fnv[i]) % MO;
            ans += tmp;
            ans %= MO;
        }
        ans %= MO;
        ans += MO;
        ans %= MO;
        cout << ans << endl;
    }
    
    return 0;
}
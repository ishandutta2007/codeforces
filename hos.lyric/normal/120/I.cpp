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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

char I[20][20] = {
    "---.---", 
    "..-..-.", 
    "-.---.-", 
    "-.--.--", 
    ".---.-.", 
    "--.-.--", 
    "--.----", 
    "-.-..-.", 
    "-------", 
    "----.--", 
};
int P[20][20];
void prepare() {
    int x, y, i;
    for (x = 0; x < 10; ++x) for (y = 0; y < 10; ++y) {
        for (i = 0; i < 7; ++i) if (I[x][i] == '-' && I[y][i] == '-') {
            ++P[x][y];
        }
    }
//for(x=0;x<10;++x)pv(P[x],P[x]+10);
}

#define MAXNN 200010

int N, NN;
char S[MAXNN];
int A[MAXNN], B[MAXNN];

int dp[MAXNN];
int sum[MAXNN], ASum[MAXNN], BSum[MAXNN];

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    prepare();
    
    int i, j, k;
    
    for (; ~scanf("%s", S); ) {
if(!strcmp(S,"#"))break;
        NN = strlen(S);
        N = NN / 2;
        for (i = 0; i < NN; ++i) {
            A[i] = S[i] - '0';
        }
        for (i = 0; i < N; ++i) {
            sum[i + 1] = sum[i] + P[A[i]][A[i + N]];
            ASum[i + 1] = ASum[i] + P[A[i]][8];
        }
        int tar = sum[N];
//cout<<"tar = "<<tar<<endl;
        dp[NN] = tar;
        for (i = NN; --i >= N; ) {
            dp[i] = dp[i + 1];
            for (j = A[i] + 1; j < 10; ++j) {
                chmax(dp[i], (sum[i - N] - sum[0]) + P[A[i - N]][j] + (ASum[N] - ASum[i - N + 1]));
            }
        }
        for (i = N; --i >= 0; ) {
            dp[i] = dp[i + 1];
            for (j = A[i] + 1; j < 10; ++j) {
                chmax(dp[i], (ASum[i] - ASum[0]) + P[j][8] + P[8][8] * (N - i - 1));
            }
        }
//cout<<"dp : ";pv(dp,dp+NN+1);
        for (k = 0; k < NN; ++k) {
            if (dp[k] <= tar) break;
        }
        --k;
        if (k < 0) {
            puts("-1");
            continue;
        }
//cout<<"k = "<<k<<endl;
        int now = 0;
        for (i = 0; i < NN; ++i) {
            if (i < k) {
                B[i] = A[i];
            } else {
                for (j = (i == k) ? (A[i] + 1) : 0; j < 10; ++j) {
                    int tmp;
                    if (i < N) {
                        tmp = (BSum[i] - BSum[0]) + P[j][8] + P[8][8] * (N - i - 1);
                    } else {
                        tmp = now + P[B[i - N]][j] + (BSum[N] - BSum[i - N + 1]);
                    }
                    if (tmp > tar) {
                        B[i] = j;
                        break;
                    }
                }
assert(j<10);
            }
            if (i < N) {
                BSum[i + 1] = BSum[i] + P[B[i]][8];
            } else {
                now += P[B[i - N]][B[i]];
            }
        }
        for (i = 0; i < NN; ++i) {
            putchar('0' + B[i]);
        }
        puts("");
    }
    
    return 0;
}
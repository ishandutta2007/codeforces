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

#define MAXN 310

int N;
int A[MAXN][MAXN];
int B[MAXN];
int as[MAXN][MAXN];
int bs[MAXN];
int ans[MAXN];

int main() {
    int i, j, k;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                A[i][j] = in() - 1;
            }
        }
        for (j = 0; j < N; ++j) {
            B[j] = in() - 1;
        }
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                as[i][A[i][j]] = j;
            }
        }
        for (j = 0; j < N; ++j) {
            bs[B[j]] = j;
        }
        for (i = 0; i < N; ++i) {
            int km = -1;
            int kk = -1;
            for (k = 0; k < N; ++k) {
                if (k != i) {
                    if (!~kk || bs[kk] > bs[k]) {
                        kk = k;
                    }
                }
                if (!~km || as[i][km] > as[i][kk]) {
                    km = kk;
                }
            }
            ans[i] = km;
        }
        for (i = 0; i < N; ++i) {
            if (i) printf(" ");
            printf("%d", ans[i] + 1);
        }
        puts("");
    }
    
    return 0;
}
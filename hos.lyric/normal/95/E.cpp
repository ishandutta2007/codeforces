//  Codeforces Beta Round #77

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

#define MAX 200010

int uf[MAX];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

const int LIM = 200005;
int lucky[MAX];

int N, M;
int A[MAX], B[MAX];
int is[MAX];
int dp[MAX];

int main() {
    int i, u;
    int k, h, l;
    
    lucky[0] = 1;
    for (k = 1; k < LIM; ++k) {
        lucky[k] = (k % 10 == 4 || k % 10 == 7) ? lucky[k / 10] : 0;
//if(lucky[k])cout<<k<<endl;
    }
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (i = 0; i < M; ++i) {
            A[i] = in() - 1;
            B[i] = in() - 1;
        }
        memset(uf, ~0, N << 2);
        for (i = 0; i < M; ++i) {
            conn(A[i], B[i]);
        }
        memset(is, 0, (N + 1) << 2);
        for (u = 0; u < N; ++u) if (uf[u] < 0) {
            ++is[-uf[u]];
        }
//cout<<"is : ";pv(is,is+N+1);
        memset(dp, 0x3f, (N + 1) << 2);
        dp[0] = 0;
        for (k = 1; k <= N; ++k) if (is[k]) {
            int rest = is[k];
            for (h = 1; rest; h <<= 1) {
                chmin(h, rest);
                rest -= h;
                int kh = k * h;
                for (l = N; l >= kh; --l) {
                    chmin(dp[l], dp[l - kh] + h);
                }
            }
        }
//cout<<"dp : ";pv(dp,dp+N+1);
        int ans = N + 1;
        for (l = 1; l <= N; ++l) if (lucky[l]) {
            chmin(ans, dp[l] - 1);
        }
        if (ans > N) ans = -1;
        printf("%d\n", ans);
    }
    
    return 0;
}
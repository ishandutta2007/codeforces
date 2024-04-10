//  Codeforces Beta Round #76

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

Int N;
int K;
Int A[110];

const int LIM = 500005;
int sum[110][500010];

void doit() {
    int i, j;
    for (j = 1; j < LIM; ++j) {
        sum[K][j] = 1;
    }
    for (i = K; i--; ) {
        for (j = 0; j < LIM; ++j) {
            sum[i][j] = sum[i + 1][j];
        }
        for (j = 0; j < LIM; j += A[i]) {
            sum[i][j] = 0;
        }
    }
    for (i = K; i >= 0; --i) {
        for (j = 0; j < LIM; ++j) {
            sum[i][j + 1] += sum[i][j];
        }
    }
}

Int ans = 0;

void dfs(Int n, Int s, int i) {
    if (n < LIM) {
        ans += sum[i][n] * s;
        return;
    }
    ans += n * s;
    Int nn;
    for (; i < K && (nn = n / A[i]) > 0; ++i) {
        dfs(nn, -s, i + 1);
    }
}

int main() {
    int i;
    
    for (; cin >> N >> K; ) {
        for (i = 0; i < K; ++i) {
            cin >> A[i];
        }
        sort(A, A + K);
        doit();
//for(i=0;i<=K;++i){cout<<"sum[i] : ";pv(sum[i],sum[i]+21);}
        ans = 0;
        dfs(N, +1, 0);
        cout << ans << endl;
    }
    
    return 0;
}
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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const Int INF = 1001001001001001001LL;
void pl(Int &t, Int f) { if ((t += f) >= INF) t = INF; }

const int LIM = 205;
Int DP[210][210];
void dping() {
    int i, j;
    DP[0][0] = 1;
    for (i = 0; i < LIM; ++i) for (j = 0; j < LIM; ++j) {
        if (i < j) pl(DP[i + 1][j], DP[i][j]);
        pl(DP[i][j + 1], DP[i][j]);
    }
}

int M, N;
Int K;
int C[210][210];

int L;
int D[210];
pint ps[210];
char seq[210];
char ans[210][210];

Int dp[210][210];
Int calc() {
    int i, j;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (i = 0; i < L; ++i) for (j = 0; j <= L / 2; ++j) if (dp[i][j]) {
        if (seq[i] != ')') pl(dp[i + 1][j + 1], dp[i][j]);
        if (seq[i] != '(') if (j) pl(dp[i + 1][j - 1], dp[i][j]);
    }
    return dp[L][0];
}

int main() {
    int x, y, z;
    int l;
    
    //dping();
    
    for (; cin >> M >> N >> K; ) {
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            C[x][y] = in();
        }
        L = M + N - 1;
        assert(L % 2 == 0);
        memset(D, 0x3f, sizeof(D));
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            chmin(D[x + y], C[x][y]);
        }
        for (z = 0; z < L; ++z) {
            ps[z] = mp(D[z], z);
        }
        sort(ps, ps + L);
//cout<<"ps : ";for(z=0;z<L;++z)cout<<ps[z].second<<" ";cout<<endl;
        memset(seq, '?', L);
        seq[L] = 0;
        Int k = K;
        for (l = 0; l < L; ++l) {
            z = ps[l].second;
            seq[z] = '(';
            Int tmp = calc();
            if (k > tmp) {
                k -= tmp;
                seq[z] = ')';
            }
        }
//cout<<"seq : "<<seq<<endl;
        for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
            ans[x][y] = seq[x + y];
        }
        for (x = 0; x < M; ++x) {
            ans[x][N] = 0;
            puts(ans[x]);
        }
    }
    
    return 0;
}
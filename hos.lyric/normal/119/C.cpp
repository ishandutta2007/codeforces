//  Codeforces Beta Round #90

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
//template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

template<class T> bool chmax(T &t, T f) { if (t < f) { t = f; return 1; } return 0; }

struct Subject {
    Int a, b;
    int c;
    int id;
    bool operator<(const Subject &a) const { return (c < a.c); }
};

int N, M;
Int K;
Subject ss[60];
Int dp[60][60][110];
pair<int,Int> prev[60][60][110];

int ansLen;
pair<int,Int> ans[60];

int main() {
    int i, j, ii;
    Int k, kk;
    int l;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        K = In();
        for (i = 0; i < M; ++i) {
            ss[i].a = In();
            ss[i].b = In();
            ss[i].c = in();
            ss[i].id = i;
        }
        sort(ss, ss + M);
        memset(dp, ~0, sizeof(dp));
        for (i = 0; i < M; ++i) for (k = ss[i].a; k <= ss[i].b; ++k) {
            if (chmax(dp[i][1][k - ss[i].a], k)) {
                prev[i][1][k - ss[i].a] = mp(-1, 0);
            }
        }
        for (i = 0; i < M; ++i) for (j = 0; j <= N; ++j) for (k = ss[i].a; k <= ss[i].b; ++k) if (~dp[i][j][k - ss[i].a]) {
            for (ii = i + 1; ii < M; ++ii) if (ss[i].c < ss[ii].c) {
                for (l = 0; l < 2; ++l) {
                    kk = l ? (k * K) : (k + K);
                    if (ss[ii].a <= kk && kk <= ss[ii].b) {
                        if (chmax(dp[ii][j + 1][kk - ss[ii].a], dp[i][j][k - ss[i].a] + kk)) {
                            prev[ii][j + 1][kk - ss[ii].a] = mp(i, k);
                        }
                    }
                }
            }
        }
        Int dai = -1;
        int im = -1;
        Int km = -1;
        for (i = 0; i < M; ++i) for (k = ss[i].a; k <= ss[i].b; ++k) {
            if (chmax(dai, dp[i][N][k - ss[i].a])) {
                im = i; km = k;
            }
        }
        if (!~im) {
            puts("NO");
            continue;
        }
        puts("YES");
        ansLen = 0;
        for (i = im, j = N, k = km; j; ) {
            ans[ansLen++] = mp(i, k);
            pair<int,Int> p = prev[i][j][k - ss[i].a];
            i = p.first;
            --j;
            k = p.second;
        }
        reverse(ans, ans + ansLen);
        for (j = 0; j < ansLen; ++j) {
            cout << (ss[ans[j].first].id + 1) << " " << ans[j].second << endl;
        }
    }
    
    return 0;
}
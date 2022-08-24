//  Codeforces Beta Round #25
//  Problem E

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
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int kmp(char *p, int fail[]) {
    int m = strlen(p);
    int i, j = fail[0] = -1;
    for (i = 1; i <= m; ++i) {
        for (; ~j && p[j] != p[i - 1]; j = fail[j]);
        fail[i] = ++j;
    }
    return m;
}

int L[3];
char S[3][100010];
int f[3][100010];
int match[3][3], over[3][3];

int solve() {
    int i, j, k;
    int ret = L[0] + L[1] + L[2];
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) if (i != j) {
            if (!match[i][j]) break;
        }
        if (j == 3) {
            return L[i];
        }
    }
    for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j) if (i != j) {
        k = 3 - i - j;
        if (match[i][k] || match[j][k]) {
            chmin(ret, L[i] + L[j] - over[i][j]);
        }
        chmin(ret, L[i] + L[j] + L[k] - over[i][j] - over[j][k]);
    }
    return ret;
}

int main() {
    int i, j;
    int x, y;
    
    scanf("%s%s%s", S[0], S[1], S[2]);
    for (i = 0; i < 3; ++i) {
        L[i] = kmp(S[i], f[i]);
    }
    for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j) {
        y = 0;
        for (x = 0; x < L[i]; ++x) {
            for (; ~y && S[j][y] != S[i][x]; y = f[j][y]);
            if (++y == L[j]) {
                match[i][j] = 1;
                y = f[j][y];
            }
        }
        over[i][j] = y;
    }
    
    int res = solve();
    printf("%d\n", res);
    
    return 0;
}
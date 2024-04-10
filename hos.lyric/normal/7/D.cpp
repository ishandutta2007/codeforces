//  Codeforces Beta Round #7
//  Problem D

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

int palindrome(char t[], int rads[]) {
    int nn = strlen(t) << 1;
    int i, j, k;
    for (i = j = 0; i < nn; i += k, j = max(j - k, 0)) {
        for (; 0 <= i - j && i + j + 1 < nn && t[i - j >> 1] == t[i + j + 1 >> 1]; ++j);
        rads[i] = j;
        for (k = 1; 0 <= i - k && 0 <= rads[i] - k && rads[i - k] != rads[i] - k; ++k) {
            rads[i + k] = min(rads[i - k], rads[i] - k);
        }
    }
    return nn;
}

int N, NN;
char S[5000010];
int dp[5000010];
int rs[10000010];

int main() {
    int i;
    Int ans = 0;
    
    scanf("%s", S);
    NN = palindrome(S, rs);
    N = NN >> 1;
    for (i = 1; i <= N; ++i) {
        ans += dp[i] = (rs[i - 1] >= i - 1) ? (dp[i >> 1] + 1) : 0;
    }
//pv(dp+1,dp+N+1);
    cout << ans << endl;
    
    return 0;
}
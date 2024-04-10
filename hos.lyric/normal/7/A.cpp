//  Codeforces Beta Round #7
//  Problem A

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

const int M = 8;
char S[20][20];

int main() {
    int x, y;
    int ans = 0;
    
    for (x = 0; x < M; ++x) {
        scanf("%s", S[x]);
    }
    for (x = 0; x < M; ++x) {
        for (y = 0; y < M && S[x][y] == 'B'; ++y);
        if (y == M) ++ans;
    }
    for (y = 0; y < M; ++y) {
        for (x = 0; x < M && S[x][y] == 'B'; ++x);
        if (x == M) ++ans;
    }
    if (ans == M + M) ans = M;
    printf("%d\n", ans);
    
    return 0;
}
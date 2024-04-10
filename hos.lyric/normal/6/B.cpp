//  Codeforces Beta Round #6
//  Problem B

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

int dx[] = { 1, 0, -1, 0, };
int dy[] = { 0, 1, 0, -1, };

int M, N;
char C, S[110][110];
bool des[0x10a];

int main() {
    int h, x, y;
    
    M = in();
    N = in();
    C = in_c();
    for (x = 1; x <= M; ++x) {
        scanf("%s", S[x] + 1);
    }
    for (x = 1; x <= M; ++x) for (y = 1; y <= N; ++y) if (S[x][y] == C) {
        for (h = 0; h < 4; ++h) {
            des[S[x + dx[h]][y + dy[h]] - 0] = 1;
        }
    }
    int ans = 0;
    for (int c = 'A'; c <= 'Z'; ++c) if (c != C) {
        if (des[c]) ++ans;
    }
    printf("%d\n", ans);
    
    return 0;
}
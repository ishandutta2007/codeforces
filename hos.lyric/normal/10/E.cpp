//  Codeforces Beta Round #10
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

int N;
int A[410];
int gr[410], gs[410];

int greedy(int w) {
    int ret = 0, i;
    for (i = 0; i < N; ++i) {
        ret += gr[i] = w / A[i];
        w %= A[i];
    }
    return ret;
}

int main() {
    int i, j;
    int ans = ~0;
    int g, c;
    
    N = in();
    for (i = 0; i < N; ++i) {
        A[i] = in();
    }
    for (i = 0; i < N; ++i) {
        c = A[i] - 1;
        g = greedy(c);
        memcpy(gs, gr, N << 2);
        for (j = N; --j > i; ) {
            if (g + 1 < greedy(c + A[j])) {
                if (!~ans || ans > c + A[j]) {
                    ans = c + A[j];
                }
            }
            c -= A[j] * gs[j];
            g -= gs[j];
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
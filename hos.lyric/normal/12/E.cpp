//  Codeforces Beta Round #12
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
int is[1010][1010];

int main() {
    int t, s, x, y;
    
    N = in();
    for (t = 1; t < N; ++t) {
        x = N - 1;
        y = (N - 1 + t) % (N - 1);
        is[x][y] = is[y][x] = t;
        for (s = 1; s < N - 1 - s; ++s) {
            x = (s + t) % (N - 1);
            y = (N - 1 - s + t) % (N - 1);
            is[x][y] = is[y][x] = t;
        }
    }
    for (x = 0; x < N; ++x) {
        for (y = 0; y < N; ++y) {
            if (y) putchar(' ');
            printf("%d", is[x][y]);
        }
        puts("");
    }
    
    return 0;
}
//  Codeforces Beta Round #14
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

const int LIM = 1005;

int N, X;
int is[1010];

int main() {
    int i;
    int a, b, c;
    int ans = -1, tmp;
    
    N = in();
    X = in();
    for (i = 0; i < N; ++i) {
        a = in();
        b = in();
        if (a > b) swap(a, b);
        for (c = a; c <= b; ++c) {
            ++is[c];
        }
    }
    
    for (c = 0; c < LIM; ++c) if (is[c] == N) {
        tmp = abs(c - X);
        if (!~ans || ans > tmp) {
            ans = tmp;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
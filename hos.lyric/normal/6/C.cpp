//  Codeforces Beta Round #6
//  Problem C

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
int A[100010];

int main() {
    int i;
    int ia, ib, ta, tb;
    
    N = in();
    for (i = 0; i < N; ++i) {
        A[i] = in();
    }
    ia = -1;
    ib = N;
    ta = tb = 0;
    for (; ia + 1 < ib; ) {
        if (ta <= tb) {
            ta += A[++ia];
        } else {
            tb += A[--ib];
        }
    }
    printf("%d %d\n", ib, N - ib);
    
    return 0;
}
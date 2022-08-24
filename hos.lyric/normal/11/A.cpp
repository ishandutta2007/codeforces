//  Codeforces Beta Round #11
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

int N;
Int D, B[2010];

int main() {
    int i;
    Int ans = 0, tmp;
    
    N = in();
    D = in();
    for (i = 0; i < N; ++i) {
        B[i] = in();
    }
    for (i = 1; i < N; ++i) if (B[i - 1] >= B[i]) {
        tmp = (B[i - 1] - B[i]) / D + 1;
        ans += tmp;
        B[i] += D * tmp;
    }
    cout << ans << endl;
    
    return 0;
}
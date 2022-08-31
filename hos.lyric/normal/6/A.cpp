//  Codeforces Beta Round #6
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



int main() {
    int i, j, k;
    int a[5];
    
    scanf("%d%d%d%d", a, a + 1, a + 2, a + 3);
    sort(a, a + 4);
    for (i = 0; i < 4; ++i) for (j = i + 1; j < 4; ++j) for (k = j + 1; k < 4; ++k) {
        if (a[i] + a[j] > a[k]) {
            puts("TRIANGLE");
            return 0;
        }
    }
    for (i = 0; i < 4; ++i) for (j = i + 1; j < 4; ++j) for (k = j + 1; k < 4; ++k) {
        if (a[i] + a[j] == a[k]) {
            puts("SEGMENT");
            return 0;
        }
    }
    puts("IMPOSSIBLE");
    
    return 0;
}
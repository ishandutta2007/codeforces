//  Codeforces Beta Round #51 (C)

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

int M, N, K;

int main() {
    int x, y;
    
    for (; ~scanf("%d%d%d", &M, &N, &K); ) {
        bool ans = 0;
        for (; K--; ) {
            scanf("%d%d", &x, &y);
            int d = min(min(x - 1, M - x), min(y - 1, N - y));
            if (d <= 4) ans = 1;
        }
        puts(ans ? "YES" : "NO");
    }
    
    return 0;
}
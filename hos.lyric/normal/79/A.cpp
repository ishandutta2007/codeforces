//  Codeforces Beta Round #71

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }



int main() {
    int x, y;
    
    for (; ~scanf("%d%d", &x, &y); ) {
        for (; ; ) {
            if (0) {}
            else if (x >= 2 && y >= 2) x -= 2, y -= 2;
            else if (x >= 1 && y >= 12) x -= 1, y -= 12;
            else if (y >= 22) y -= 22;
            else { puts("Hanako"); break; }
            if (0) {}
            else if (y >= 22) y -= 22;
            else if (x >= 1 && y >= 12) x -= 1, y -= 12;
            else if (x >= 2 && y >= 2) x -= 2, y -= 2;
            else { puts("Ciel"); break; }
        }
    }
    
    return 0;
}
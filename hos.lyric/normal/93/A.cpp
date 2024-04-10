//  Codeforces Beta Round #76

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

int solve(Int n, Int m, Int a, Int b) {
    --n;
    --a;
    --b;
    Int nx = n / m, ny = n % m;
    Int ax = a / m, ay = a % m;
    Int bx = b / m, by = b % m;
    if (ax == bx) return 1;
    if (ay == 0 && (by == m - 1 || b == n)) return 1;
    if (ay == 0 || (by == m - 1 || b == n)) return 2;
    if (ax + 1 == bx) return 2;
    if (ay - 1 == by) return 2;
    return 3;
}

int main() {
    int n, m, a, b;
    
    for (; ~scanf("%d%d%d%d", &n, &m, &a, &b); ) {
        int res = solve(n, m, a, b);
        cout << res << endl;
    }
    
    return 0;
}
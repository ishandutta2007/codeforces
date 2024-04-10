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

int asLen[110];
int as[110][110];
int ks[110][110];

bool solve(int n, int w, int m) {
    int i, j;
    int y = 0;
    int k = 0;
    memset(asLen, 0, sizeof(asLen));
    for (i = 0; i < m; ++i) {
        int x = n;
        for (; x; ) {
            if (y == 0) {
                ++k;
                y = m;
            }
            int tmp = min(x, y);
            as[i][asLen[i]] = tmp;
            ks[i][asLen[i]] = k;
            ++asLen[i];
            x -= tmp;
            y -= tmp;
            if (x == 0 && tmp + n < m) {
                return 0;
            }
        }
    }
    
    puts("YES");
    for (i = 0; i < m; ++i) {
        for (j = 0; j < asLen[i]; ++j) {
            if (j) putchar(' ');
            printf("%d %.6f", ks[i][j], (double)w / m * as[i][j]);
        }
        puts("");
    }
    return 1;
}

int main() {
    int n, w, m;
    
    for (; ~scanf("%d%d%d", &n, &w, &m); ) {
        bool res = solve(n, w, m);
        if (!res) puts("NO");
    }
    
    return 0;
}
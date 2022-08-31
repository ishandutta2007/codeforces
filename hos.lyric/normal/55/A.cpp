//  Codeforces Beta Round #51 (A)

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
int is[1010];
int vis[1010][1010];

int main() {
    int x, k;
    
    for (; ~scanf("%d", &N); ) {
        memset(vis, 0, sizeof(vis));
        memset(is, 0, sizeof(is));
        int cnt = 0;
        x = 0;
        k = 0;
        for (; ; ) {
            if (vis[x][k]) break;
            vis[x][k] = 1;
            if (!is[x]) {
                is[x] = 1;
                ++cnt;
            }
            x = (x + k + 1) % N;
            k = (k + 1) % N;
        }
        puts((cnt == N) ? "YES" : "NO");
    }
    
    return 0;
}
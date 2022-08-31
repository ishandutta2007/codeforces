//  Codeforces Beta Round #88

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

int N;
int M;

int solve(int s, int f, int t) {
    if (s == f) return t;
    int a = t / (M * 2) * (M * 2);
    int ss[] = { a + s, a + M * 2 - s, a + M * 2 + s, a + M * 4 - s, a + M * 4 + s, a + M * 6 - s, };
    int fs[] = { a + f, a + M * 2 - f, a + M * 2 + f, a + M * 4 - f, a + M * 4 + f, a + M * 6 - f, };
    int i, j;
    for (i = 0; ss[i] < t; ++i);
    for (j = 0; fs[j] < ss[i]; ++j);
    return fs[j];
}

int main() {
    int i;
    int s, f, t;
    
    for (; ~scanf("%d", &N); ) {
        M = in() - 1;
        for (i = 0; i < N; ++i) {
            s = in() - 1;
            f = in() - 1;
            t = in();
            int res = solve(s, f, t);
            printf("%d\n", res);
        }
    }
    
    return 0;
}
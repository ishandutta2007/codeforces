//  Codeforces Beta Round #24
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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int N;
int deg[110], g[110][10];
int C[110][110];

int us[110];

int main() {
    int i, u, v;
    
    N = in();
    for (i = 0; i < N; ++i) {
        u = in() - 1;
        v = in() - 1;
        C[v][u] = in();
        g[u][deg[u]++] = v;
        g[v][deg[v]++] = u;
    }
    
    us[0] = 0;
    us[1] = g[0][0];
    for (i = 2; i <= N; ++i) {
        u = us[i - 2];
        v = us[i - 1];
        us[i] = g[v][0] + g[v][1] - u;
    }
    
    int a0 = 0, a1 = 0;
    for (i = 0; i < N; ++i) {
        a0 += C[us[i + 0]][us[i + 1]];
        a1 += C[us[i + 1]][us[i + 0]];
    }
    printf("%d\n", min(a0, a1));
    
    return 0;
}
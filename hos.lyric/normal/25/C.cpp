//  Codeforces Beta Round #25
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

int N, K;
Int d[310][310];

int main() {
    int k;
    int u, v, w;
    int a, b;
    Int c;
    
    N = in();
    for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
        d[u][v] = in();
    }
    for (w = 0; w < N; ++w) for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
        chmin(d[u][v], d[u][w] + d[w][v]);
    }
    K = in();
    for (k = 0; k < K; ++k) {
        a = in() - 1;
        b = in() - 1;
        c = in();
        if (d[a][b] > c) {
            d[a][b] = d[b][a] = c;
            for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) {
                chmin(d[u][v], d[u][a] + c + d[b][v]);
                chmin(d[u][v], d[u][b] + c + d[a][v]);
            }
        }
        Int ans = 0;
        for (u = 0; u < N; ++u) for (v = u + 1; v < N; ++v) {
            ans += d[u][v];
        }
        if (k) putchar(' ');
        cout << ans;
    }
    puts("");
    
    return 0;
}
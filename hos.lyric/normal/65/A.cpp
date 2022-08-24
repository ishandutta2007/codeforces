//  Codeforces Beta Round #60

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

const double INF = 1e+20;
const double EPS = 1e-10;

int A, B, C, D, E, F;
int X[3], Y[3];

bool solve() {
    int i, j;
    double d[3] = { 1, 0, 0 };
    X[0] = A; Y[0] = B;
    X[1] = C; Y[1] = D;
    X[2] = E; Y[2] = F;
    for (i = 0; i < 3; ++i) {
        j = (i + 1) % 3;
        if (!X[i] && Y[i]) {
            d[j] = INF;
        }
    }
    for (int reps = 10; reps--; ) {
        for (i = 0; i < 3; ++i) {
            j = (i + 1) % 3;
            if (X[i]) {
                chmax(d[j], d[i] / X[i] * Y[i]);
            }
        }
    }
    if (d[2] >= 1e+10) return 1;
    if (d[0] > 1.0 + EPS && d[2] > 0.0 + EPS) return 1;
    return 0;
}

int main() {
    
    
    for (; ~scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F); ) {
        puts(solve() ? "Ron" : "Hermione");
    }
    
    return 0;
}
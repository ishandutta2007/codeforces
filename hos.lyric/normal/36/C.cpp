//  Codeforces Beta Round #36
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

int N;
double H[3010], A[3010], B[3010];
double ys[3010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int i, j;
    double t;
    
    N = in();
    for (i = 0; i < N; ++i) {
        H[i] = in();
        A[i] = in();
        B[i] = in();
    }
    
    for (i = 0; i < N; ++i) for (j = 0; j < i; ++j) {
        chmax(ys[i], ys[j]);
        t = min((A[i] - A[j]) / (B[j] - A[j]), 1.0);
        if (t >= 0.0) {
            chmax(ys[i], ys[j] + H[j] * t);
        }
        t = min((B[i] - A[j]) / (B[j] - A[j]), 1.0);
        if (t >= 0.0) {
            chmax(ys[i], ys[j] + H[j] * t - H[i]);
        }
        t = max((B[j] - A[i]) / (B[i] - A[i]), 0.0);
        if (t <= 1.0) {
            chmax(ys[i], ys[j] + H[j] - H[i] * t);
        }
    }
//pv(ys,ys+N);
    
    double ans = 0.0;
    for (i = 0; i < N; ++i) {
        chmax(ans, ys[i] + H[i]);
    }
    printf("%.10f\n", ans);
    
    return 0;
}
//  Codeforces Beta Round #24
//  Problem E

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

int N;
pair<double,double> P[500010];

double solve(int a, int b, int c) {
    if (a == b || b == c) return INF;
    int i;
    double lo = 0.0, ho = 1e+9;
    for (int reps = 60; reps--; ) {
        double mo = (lo + ho) / 2.0;
        double f = -INF;
        for (i = a; i < b; ++i) {
            chmax(f, P[i].first + P[i].second * mo);
        }
        for (i = b; i < c; ++i) {
            if (P[i].first + P[i].second * mo <= f) break;
        }
        (i == c) ? lo = mo : ho = mo;
    }
    return ho;
}

int main() {
    int i, j, k;
    
    N = in();
    for (i = 0; i < N; ++i) {
        P[i].first = in();
        P[i].second = in();
    }
    sort(P, P + N);
    
    double ans = INF;
    
    for (i = 0; i < N; i = k) {
        for (j = i; j < N && P[j].second > 0; ++j);
        for (k = j; k < N && P[k].second < 0; ++k);
        chmin(ans, solve(i, j, k));
    }
    
    if (ans >= INF) {
        puts("-1");
    } else {
        printf("%.12f\n", ans);
    }
    
    
    return 0;
}
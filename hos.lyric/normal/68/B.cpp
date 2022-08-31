//  Codeforces Beta Round #62

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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int N;
double K;
double A[10010];

int main() {
    int i;
    
    for (; ~scanf("%d%lf", &N, &K); ) {
        for (i = 0; i < N; ++i) {
            scanf("%lf", &A[i]);
        }
        double lo = 0.0, ho = 1000.0;
        for (int reps = 50; reps--; ) {
            double mo = (lo + ho) / 2.0;
            double p = 0.0, m = 0.0;
            for (i = 0; i < N; ++i) {
                if (A[i] > mo) {
                    p += A[i] - mo;
                } else {
                    m += mo - A[i];
                }
            }
            p *= 1.0 - K / 100.0;
            (p >= m) ? (lo = mo) : (ho = mo);
        }
        printf("%.9f\n", lo);
    }
    
    return 0;
}
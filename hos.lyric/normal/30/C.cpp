//  Codeforces Beta Round #30
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

struct Target {
    int x, y, t;
    double p;
    bool operator<(const Target &a) const {
        return (t < a.t);
    }
};

Int sq(Int x) { return x * x; }

int N;
Target ts[1010];
double dp[1010];

int main() {
    int i, j;
    
    N = in();
    for (i = 0; i < N; ++i) {
        scanf("%d%d%d%lf", &ts[i].x, &ts[i].y, &ts[i].t, &ts[i].p);
    }
    sort(ts, ts + N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < i; ++j) {
            if (sq(ts[i].x - ts[j].x) + sq(ts[i].y - ts[j].y) <= sq(ts[i].t - ts[j].t)) {
                chmax(dp[i], dp[j]);
            }
        }
        dp[i] += ts[i].p;
    }
    
    double ans = 0.0;
    for (i = 0; i < N; ++i) {
        chmax(ans, dp[i]);
    }
    printf("%.12f\n", ans);
    
    return 0;
}
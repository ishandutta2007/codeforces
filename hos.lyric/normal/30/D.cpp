//  Codeforces Beta Round #30
//  Problem D

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

const double INF = 1e+10;

int N, K;
double X[100010], Y, XK;
double dist[100010];

int main() {
    int i;
    double ans = INF, tmp;
    
    N = in();
    K = in() - 1;
    for (i = 0; i <= N; ++i) {
        X[i] = in();
    }
    Y = in();
    XK = X[K];
    sort(X, X + N);
    
    for (i = 0; i < N; ++i) {
        dist[i] = hypot(X[i] - X[N], Y);
    }
    
    if (K < N) {
        K = lower_bound(X, X + N, XK) - X;
        tmp = dist[K] + min(dist[0], dist[N - 1]) + abs(X[0] - X[N - 1]);
        chmin(ans, tmp);
        for (i = 0; i < N; ++i) {
            tmp = min(abs(X[K] - X[0]) + abs(X[0] - X[i]) + dist[i], abs(X[K] - X[i]) + abs(X[i] - X[0]) + dist[0]);
            if (i + 1 <= N - 1) tmp += min(dist[i + 1], dist[N - 1]) + abs(X[i + 1] - X[N - 1]);
            chmin(ans, tmp);
            tmp = min(abs(X[K] - X[N - 1]) + abs(X[N - 1] - X[i]) + dist[i], abs(X[K] - X[i]) + abs(X[i] - X[N - 1]) + dist[N - 1]);
            if (0 <= i - 1) tmp += min(dist[0], dist[i - 1]) + abs(X[0] - X[i - 1]);
            chmin(ans, tmp);
        }
    } else {
        tmp = min(dist[0], dist[N - 1]) + abs(X[0] - X[N - 1]);
        chmin(ans, tmp);
    }
    
    printf("%.12f\n", ans);
    
    return 0;
}
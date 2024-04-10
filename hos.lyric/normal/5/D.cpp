//  Codeforces Beta Round #5
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

double A, V, L, D, W;

double calc(double v0, double v1) {
    return (v0 + v1) * (v1 - v0) / A / 2.0;
}
double niji(double a, double b, double c) {
    double d = b * b - a * c * 4.0;
    if (d < 0) d = 0;
    return (-b + sqrt(d)) / a / 2.0;
}

int main() {
    double t0, t1;
    
    scanf("%lf%lf%lf%lf%lf", &A, &V, &L, &D, &W);
    if (W > V) W = V;
    
    if (calc(0.0, W) >= D) {
        if (calc(0.0, V) >= L) {
            printf("%.12f\n", sqrt(L / A * 2.0));
        } else {
            printf("%.12f\n", V / A + (L - calc(0.0, V)) / V);
        }
    } else {
        if (calc(0.0, V) + calc(W, V) >= D) {
            double lo = W, ho = V;
            for (int reps = 100; reps--; ) {
                double mo = (lo + ho) / 2.0;
                (calc(0.0, mo) + calc(W, mo) < D) ? lo = mo : ho = mo;
            }
            t0 = lo / A + (lo - W) / A;
        } else {
            t0 = V / A + (V - W) / A + (D - calc(0.0, V) - calc(W, V)) / V;
        }
        if (calc(W, V) >= L - D) {
            t1 = niji(A / 2.0, W, -(L - D));
        } else {
            t1 = (V - W) / A + (L - D - calc(W, V)) / V;
        }
//cout<<t0<<" "<<t1<<endl;
        printf("%.12f\n", t0 + t1);
    }
    
    return 0;
}
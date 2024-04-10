//  Codeforces Beta Round #9
//  Problem B

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

const double EPS = 1e-10;
const double INF = 1e+10;

int N;
double VB, VS, XU, YU;
double X[110];

int main() {
    int i, im = 0;
    double sho = INF, tmp;
    
    N = in();
    VB = in();
    VS = in();
    for (i = 0; i < N; ++i) {
        X[i] = in();
    }
    XU = in();
    YU = in();
    
    for (i = 1; i < N; ++i) {
        tmp = X[i] / VB + hypot(XU - X[i], YU) / VS;
        if (sho + EPS >= tmp) {
            sho = tmp;
            im = i;
        }
    }
    printf("%d\n", im + 1);
    
    return 0;
}
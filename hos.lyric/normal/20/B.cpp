//  Codeforces Alpha Round #20
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

void out(double x) {
    printf("%.10f\n", x);
}

int main() {
    Int a, b, c;
    
    a = in();
    b = in();
    c = in();
    if (a) {
        Int d = b * b - 4 * a * c;
        if (d > 0) {
            puts("2");
            double dd = sqrt(d);
            double x0 = (-b - dd) / (2 * a);
            double x1 = (-b + dd) / (2 * a);
            if (x0 > x1) swap(x0, x1);
            out(x0);
            out(x1);
        } else if (d == 0) {
            puts("1");
            out(-b / (double)(2 * a));
        } else {
            puts("0");
        }
    } else if (b) {
        puts("1");
        out(-c / (double)b);
    } else if (c) {
        puts("0");
    } else {
        puts("-1");
    }
    
    return 0;
}
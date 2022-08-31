//  Codeforces Beta Round 66

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



int main() {
    int X, Y, Z, K;
    int a, b, c;
    
    for (; ~scanf("%d%d%d%d", &X, &Y, &Z, &K); ) {
        if (Y > Z) swap(Y, Z);
        Int ans = 1;
        for (a = 0; a <= K && a < X; ++a) {
            b = (K - a) / 2;
            c = K - a - b;
            if (b >= Y) {
                c += b - (Y - 1);
                b = Y - 1;
            }
            if (c >= Z) {
                b += c - (Z - 1);
                c = Z - 1;
            }
            if (b >= Y) {
                b = Y - 1;
            }
            if (c >= Z) {
                c = Z - 1;
            }
            chmax(ans, (Int)(a + 1) * (b + 1) * (c + 1));
        }
        cout << ans << endl;
    }
    
    return 0;
}
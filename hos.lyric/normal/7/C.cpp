//  Codeforces Beta Round #7
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

Int gojo(Int a, Int b, Int &x, Int &y) {    //  ax + by == gcd(a, b)
    if (b) { Int g = gojo(b, a % b, y, x); y -= (a / b) * x; return g; }
    x = 1; y = 0; return a;
}

Int A, B, C;

int main() {
    Int x, y, g;
    
    A = in();
    B = in();
    C = in();
    g = gojo(A, B, x, y);
    if (-C % g != 0) {
        puts("-1");
        return 0;
    }
    cout << x * (-C / g) << " " << y * (-C / g) << endl;
    
    return 0;
}
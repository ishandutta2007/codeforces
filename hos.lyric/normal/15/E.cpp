//  Codeforces Beta Round #15
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

const Int MO = 1000000009;

int N;

int main() {
    int n;
    Int a = 2, b = 2, c = 1;
    
    N = in();
    
    for (n = 3; n <= N; ++n) {
        a += b;
        a %= MO;
        if (~n & 1) {
            c = (c * 2 + 3) % MO;
            b = b * c % MO;
        }
    }
    
    cout << (1 + a * a) * 2 % MO << endl;
    
    return 0;
}
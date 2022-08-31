//  Codeforces Beta Round #51 (B)

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

const Int INF = 1001001001001001001LL;

char S[10][10];
Int ans;

void solve2(Int a, Int b) {
    Int x = (S[2][0] == '+') ? (a + b) : (a * b);
    if (ans > x) {
        ans = x;
    }
}
void solve3(Int a, Int b, Int c) {
    if (S[3][0] == '+') {
        solve2(a + b, c);
        solve2(a + c, b);
        solve2(b + c, a);
    } else {
        solve2(a * b, c);
        solve2(a * c, b);
        solve2(b * c, a);
    }
}
void solve4(Int a, Int b, Int c, Int d) {
    if (S[4][0] == '+') {
        solve3(a + b, c, d);
        solve3(a + c, b, d);
        solve3(a + d, b, c);
        solve3(b + c, a, d);
        solve3(b + d, a, c);
        solve3(c + d, a, b);
    } else {
        solve3(a * b, c, d);
        solve3(a * c, b, d);
        solve3(a * d, b, c);
        solve3(b * c, a, d);
        solve3(b * d, a, c);
        solve3(c * d, a, b);
    }
}

int main() {
    int a, b, c, d;
    
    for (; ~scanf("%d%d%d%d", &a, &b, &c, &d); ) {
        scanf("%s%s%s", S[4], S[3], S[2]);
        ans = INF;
        solve4(a, b, c, d);
        cout << ans << endl;
    }
    
    return 0;
}
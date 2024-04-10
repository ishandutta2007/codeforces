//  Codeforces Beta Round #17
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

char SB[1000010], SN[1000010];
Int B, N, M;

Int strmod(char *s, Int m) {
    Int ret = 0;
    for (; *s; ++s) ret = (ret * 10 + (*s - '0')) % m;
    return ret;
}
Int power(Int a, Int e, Int m) {
    Int x = a, y = 1;
    for (; e; e >>= 1, x = (x * x) % m) if (e & 1) y = (y * x) % m;
    return y;
}

int main() {
    Int phi, m;
    
    scanf("%s%s", SB, SN);
    M = in();
    
    phi = m = M;
    for (Int d = 2; d * d <= m; ++d) if (m % d == 0) {
        phi = phi / d * (d - 1);
        for (; m % d == 0; m /= d);
    }
    if (m > 1) {
        phi = phi / m * (m - 1);
    }
    
    B = strmod(SB, M);
    N = strmod(SN, phi) - 1 + phi * 2;
    if (strlen(SN) <= 2) N = strmod(SN, 100) - 1;
    Int ans = power(B, N, M);
    ans *= B - 1 + M;
    ans %= M;
    if (!ans) ans = M;
    cout << ans << endl;
    
    return 0;
}
//  Codeforces Beta Round #15
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



int main() {
    Int m, n, p, q, r, s;
    Int x, y;
    Int ans;
    
    for (int TC = in(); TC--; ) {
        m = in();
        n = in();
        p = in();
        q = in();
        r = in();
        s = in();
        x = r - p;
        y = s - q;
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        ans = 0;
        ans += (m - x) * (n - y) * 2;
        ans -= max(m - x - x, 0LL) * max(n - y - y, 0LL);
        ans = m * n - ans;
        cout << ans << endl;
    }
    
    return 0;
}
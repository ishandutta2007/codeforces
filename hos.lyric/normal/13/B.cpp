//  Codeforces Beta Round #13
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

struct S {
    Int xa, ya, xb, yb;
};
bool common(S &s, S &t) {
    if (s.xa == t.xa && s.ya == t.ya) return 1;
    swap(t.xa, t.xb);
    swap(t.ya, t.yb);
    if (s.xa == t.xa && s.ya == t.ya) return 1;
    swap(s.xa, s.xb);
    swap(s.ya, s.yb);
    if (s.xa == t.xa && s.ya == t.ya) return 1;
    swap(t.xa, t.xb);
    swap(t.ya, t.yb);
    if (s.xa == t.xa && s.ya == t.ya) return 1;
    swap(s.xa, s.xb);
    swap(s.ya, s.yb);
    return 0;
}

S s[10];

int main() {
    int i, j;
    Int d0, d1, da, db;
    
    for (int TC = in(); TC--; ) {
        for (i = 0; i < 3; ++i) {
            s[i].xa = in();
            s[i].ya = in();
            s[i].xb = in();
            s[i].yb = in();
        }
        for (i = 0; i < 3; ++i) for (j = i + 1; j < 3; ++j) {
            if (common(s[i], s[j])) {
                swap(s[0], s[i]);
                swap(s[1], s[j]);
                goto found;
            }
        }
        goto failed;
    found:;
        for (i = 3; i--; ) {
            s[i].xb -= s[0].xa;
            s[i].yb -= s[0].ya;
            s[i].xa -= s[0].xa;
            s[i].ya -= s[0].ya;
        }
        if (s[0].xb * s[1].xb + s[0].yb * s[1].yb < 0) goto failed;
        if (s[0].xb * s[1].yb - s[1].xb * s[0].yb == 0) goto failed;
        if (s[0].xb * s[2].ya - s[2].xa * s[0].yb != 0) {
            swap(s[2].xa, s[2].xb);
            swap(s[2].ya, s[2].yb);
        }
//for(i=0;i<3;++i)printf("(%lld,%lld)-(%lld,%lld)\n",s[i].xa,s[i].ya,s[i].xb,s[i].yb);
        if (s[0].xb * s[2].ya - s[2].xa * s[0].yb != 0) goto failed;
        if (s[1].xb * s[2].yb - s[2].xb * s[1].yb != 0) goto failed;
        if (s[0].xb * s[2].xa + s[0].yb * s[2].ya < 0) goto failed;
        if (s[1].xb * s[2].xb + s[1].yb * s[2].yb < 0) goto failed;
        d0 = s[0].xb * s[0].xb + s[0].yb * s[0].yb;
        d1 = s[1].xb * s[1].xb + s[1].yb * s[1].yb;
        da = s[2].xa * s[2].xa + s[2].ya * s[2].ya;
        db = s[2].xb * s[2].xb + s[2].yb * s[2].yb;
        if (da * 25 < d0 || d0 * 16 < da * 25) goto failed;
        if (db * 25 < d1 || d1 * 16 < db * 25) goto failed;
        puts("YES");
        continue;
    failed:;
        puts("NO");
    }
    
    
    return 0;
}
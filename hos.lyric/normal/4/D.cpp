//  Codeforces Beta Round #4
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

struct Cow {
    int w, h, id;
    bool operator<(const Cow &a) const {
        return (w != a.w) ? (w < a.w) : (h > a.h);
    }
};

int N, W, H;
int M;
Cow P[5010];
int len, v[5010], ids[5010], prev[5010];
int ans[5010];

int main() {
    int i, w, h;
    int pos;
    
    N = in();
    W = in();
    H = in();
    for (i = 0; i < N; ++i) {
        w = in();
        h = in();
        if (W < w && H < h) {
            P[M].w = w;
            P[M].h = h;
            P[M].id = i;
            ++M;
        }
    }
    if (!M) {
        puts("0");
        return 0;
    }
    sort(P, P + M);
    for (i = 0; i < M; ++i) {
        pos = lower_bound(v, v + len, P[i].h) - v;
        v[pos] = P[i].h;
        ids[pos] = P[i].id;
        prev[P[i].id] = pos ? ids[pos - 1] : ~0;
        if (pos == len) ++len;
    }
    ans[len - 1] = ids[len - 1];
    for (i = len - 2; i >= 0; --i) {
        ans[i] = prev[ans[i + 1]];
    }
    printf("%d\n", len);
    for (i = 0; i < len; ++i) {
        if (i) putchar(' ');
        printf("%d", ans[i] + 1);
    }
    puts("");
    
    return 0;
}
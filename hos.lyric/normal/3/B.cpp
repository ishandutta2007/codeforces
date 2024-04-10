//  Codeforces Beta Round #3
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

int N, V;
int A, B;
pint P[100010], Q[100010];
int sp[100010], sq[100010];

int len, ans[100010];

int main() {
    int h, i, j;
    int im, jm;
    int dai;
    
    N = in();
    V = in();
    for (h = 0; h < N; ++h) {
        if (in() == 1) {
            P[A++] = mp(in(), h);
        } else {
            Q[B++] = mp(in(), h);
        }
    }
    sort(P, P + A, greater<pint>());
    sort(Q, Q + B, greater<pint>());
    for (i = 0; i < A; ++i) sp[i + 1] = sp[i] + P[i].first;
    for (j = 0; j < B; ++j) sq[j + 1] = sq[j] + Q[j].first;
//pv(sp,sp+A+1);pv(sq,sq+B+1);
    
    dai = 0;
    im = jm = 0;
    for (i = 0; i <= A && i <= V; ++i) {
        j = min((V - i) / 2, B);
        if (dai < sp[i] + sq[j]) {
            dai = sp[i] + sq[j];
            im = i;
            jm = j;
        }
    }
    
    for (i = 0; i < im; ++i) ans[len++] = P[i].second;
    for (j = 0; j < jm; ++j) ans[len++] = Q[j].second;
    sort(ans, ans + len);
    printf("%d\n", dai);
    for (h = 0; h < len; ++h) {
        if (h) putchar(' ');
        printf("%d", ans[h] + 1);
    }
    puts("");
    
    return 0;
}
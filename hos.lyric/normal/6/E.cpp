//  Codeforces Beta Round #6
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

int N, K;
int H[100010];
pint pue[100010], que[100010], *pb, *pe, *qb, *qe;
int ans[100010];

int main() {
    int i, j;
    
    N = in();
    K = in();
    for (i = 0; i < N; ++i) {
        H[i] = in();
    }
    H[N] = H[N - 1] + K + 1;
    
    pb = pe = pue;
    qb = qe = que;
    *pe++ = *qe++ = mp(H[0], 0);
    for (j = 1, i = 0; i < N; ++i) {
        for (; qb->first - pb->first <= K; ++j) {
            for (; pb != pe && (pe - 1)->first >= H[j]; --pe); *pe++ = mp(H[j], j);
            for (; qb != qe && (qe - 1)->first <= H[j]; --qe); *qe++ = mp(H[j], j);
        }
        ans[i] = j - i - 1;
        if (pb->second == i) ++pb;
        if (qb->second == i) ++qb;
    }
    int dai = 0, cnt = 0;
    for (i = 0; i < N; ++i) if (dai < ans[i]) dai = ans[i];
    for (i = 0; i < N; ++i) if (dai == ans[i]) ++cnt;
    printf("%d %d\n", dai, cnt);
    for (i = 0; i < N; ++i) if (dai == ans[i]) printf("%d %d\n", i + 1, i + dai);
    
    return 0;
}
//  Codeforces Beta Round #13
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

const int L = 500;

int N, qry;
int is[100010];
int to[100010], over[100010], oc[100010];

void overing(int i) {
    if (is[i] == is[to[i]]) {
        over[i] = over[to[i]];
        oc[i] = 1 + oc[to[i]];
    } else {
        over[i] = i;
        oc[i] = 1;
    }
}
void change(int i, int d) {
    int j;
    to[i] = min(i + d, N);
    for (j = i; j >= 0 && is[j] == is[i]; --j) {
        overing(j);
    }
}

int main() {
    int i;
    
    N = in();
    qry = in();
    for (i = 0; i < N; ++i) {
        is[i] = i / L;
    }
    is[N] = is[N - 1] + 1;
    
    to[N] = N;
    over[N] = N;
    oc[N] = 0;
    for (i = N; i--; ) {
        to[i] = i + 1;
        overing(i);
    }
    
    for (i = 0; i < N; ++i) {
        change(i, in());
    }
    for (; qry--; ) {
        if (in()) {
            i = in() - 1;
            int ans = 0, las = i;
            for (; i < N; i = to[over[i]]) {
                ans += oc[i];
                las = over[i];
            }
            printf("%d %d\n", las + 1, ans);
        } else {
            i = in() - 1;
            change(i, in());
        }
    }
    
    return 0;
}
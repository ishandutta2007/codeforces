//  Codeforces Beta Round #86

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int L;
char S[100010];

int N;
int is[100010];

bool solve() {
    int i;
    for (i = 0; i < N; ++i) {
        if (is[i] == -1) {
            return 0;
        }
    }
    if (N == 1) return 1;
    for (i = 0; i < N; ++i) {
        if (is[0] % 2 != is[i] % 2) {
            return 0;
        }
    }
    int a = 0, b = 0, c = 0;
    i = 0;
    for (; i < N && is[i] / 2 == 0; ++i) ++a;
    for (; i < N && is[i] / 2 == 1; ++i) ++b;
    for (; i < N && is[i] / 2 == 2; ++i) ++c;
    if (i != N) return 0;
    if (b != 1) return 0;
    return 1;
}

int main() {
    int i;
    
    for (; ; ) {
        N = 0;
        for (; ~scanf("%s", S); ) {
            if (!strcmp(S, "#")) break;
            L = strlen(S);
            is[N] = -1;
            if (!strcmp(S + L - 4,   "lios")) is[N] = 0;
            if (!strcmp(S + L - 5,  "liala")) is[N] = 1;
            if (!strcmp(S + L - 3,    "etr")) is[N] = 2;
            if (!strcmp(S + L - 4,   "etra")) is[N] = 3;
            if (!strcmp(S + L - 6, "initis")) is[N] = 4;
            if (!strcmp(S + L - 6, "inites")) is[N] = 5;
            ++N;
        }
        if (N == 0) break;
//cout<<"is : ";pv(is,is+N);
        bool res = solve();
        puts(res ? "YES" : "NO");
    }
    
    return 0;
}
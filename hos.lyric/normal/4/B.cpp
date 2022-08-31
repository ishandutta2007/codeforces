//  Codeforces Beta Round #4
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

int N, S;
int A[110], B[110];
int ans[110];

int main() {
    int i;
    int tmp;
    
    N = in();
    S = in();
    for (i = 0; i < N; ++i) {
        A[i] = in();
        B[i] = in();
    }
    
    for (i = 0; i < N; ++i) {
        S -= A[i];
        B[i] -= A[i];
    }
    if (S < 0) {
        puts("NO");
        return 0;
    }
    for (i = 0; i < N; ++i) {
        tmp = min(B[i], S);
        S -= tmp;
        ans[i] = A[i] + tmp;
    }
    if (S > 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (i = 0; i < N; ++i) {
        if (i) putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");
    
    return 0;
}
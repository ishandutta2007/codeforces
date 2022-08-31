//  Codeforces Beta Round #5
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

int N, L[1010];
char S[1010][1010];

int main() {
    int i;
    int dai = 0;
    int l = 0, r = 1;
    
    for (; gets(S[N]); ++N) {
        L[N] = strlen(S[N]);
        if (dai < L[N]) dai = L[N];
    }
    for (i = dai + 2; i--; ) putchar('*');
    puts("");
    for (i = 0; i < N; ++i) {
        printf("*%*s%s%*s*\n", (dai - L[i] + l) / 2, "", S[i], (dai - L[i] + r) / 2, "");
        if ((dai - L[i]) % 2 != 0) swap(l, r);
    }
    for (i = dai + 2; i--; ) putchar('*');
    puts("");
    
    return 0;
}
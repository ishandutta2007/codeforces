//  Codeforces Beta Round #7
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

int T, M, N;
int is[110], sum[110];
int del[110];

int main() {
    int i, j;
    int m, n;
    char buf[110];
    
    T = in();
    M = in();
    for (; T--; ) {
        scanf("%s", buf);
        switch (buf[0]) {
            case 'a': {
                m = in();
                for (i = 0; i < M; ++i) sum[i + 1] = sum[i] + (is[i] ? 1 : 0);
                for (i = 0; i + m <= M; ++i) if (sum[i + m] - sum[i] == 0) {
                    printf("%d\n", ++N);
                    for (j = i; j < i + m; ++j) is[j] = N;
                    goto found;
                }
                puts("NULL");
            found:;
            } break; case 'e': {
                n = in();
                if (!(1 <= n && n <= N) || del[n]) {
                    puts("ILLEGAL_ERASE_ARGUMENT");
                } else {
                    for (i = 0; i < M; ++i) if (is[i] == n) is[i] = 0;
                    del[n] = 1;
                }
            } break; case 'd': {
                for (i = j = 0; i < M; ++i) {
                    for (; j < M && !is[j]; ++j);
                    is[i] = is[j];
                    if (j < M) ++j;
                }
            }
        }
    }
    
    return 0;
}
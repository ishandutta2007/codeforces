//  Codeforces Beta Round #5
//  Problem C

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

#define MAXN 1000010

int N;
char S[MAXN];
int _sy[MAXN], _si[MAXN];

int main() {
    int i;
    int y = 0;
    int ans = 0, cnt = 1;
    
    scanf("%s", S);
    N = strlen(S);
    
    int *sy = _sy, *si = _si;
    *sy = -N - 1;
    for (i = 0; i <= N; ++i) {
        for (; *sy > y; --sy, --si);
        if (*sy == y) {
            if (ans < i - *si) {
                ans = i - *si;
                cnt = 1;
            } else if (ans == i - *si) {
                ++cnt;
            }
        } else {
            *++sy = y;
            *++si = i;
        }
        (S[i] == '(') ? ++y : --y;
    }
    if (!ans) cnt = 1;
    printf("%d %d\n", ans, cnt);
    
    return 0;
}
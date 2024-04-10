//  Codeforces Beta Round #8
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

const int M = 210;
const int SX = 105;
const int SY = 105;

int dx[] = { 1, 0, -1, 0, };
int dy[] = { 0, 1, 0, -1, };

int tr[0x10a];
char S[110];
int is[220][220];

int TX, TY;
int d[220][220], que[40010], *qb, *qe;

int main() {
    int h, x, y;
    
    tr['D' - 0] = 0;
    tr['R' - 0] = 1;
    tr['U' - 0] = 2;
    tr['L' - 0] = 3;
    
    scanf("%s", S);
    x = SX;
    y = SY;
    is[x][y] = 1;
    for (char *p = S; *p; ++p) {
        h = tr[*p - 0];
        x += dx[h];
        y += dy[h];
        is[x][y] = 1;
    }
    TX = x;
    TY = y;
    
    qb = qe = que;
    memset(d, ~0, sizeof(d));
    d[SX][SY] = 0;
    *qe++ = SX; *qe++ = SY;
    for (; qb != qe; ) {
        x = *qb++; y = *qb++;
        if (x == TX && y == TY) {
            puts((d[x][y] == (int)strlen(S)) ? "OK" : "BUG");
            return 0;
        }
        for (h = 0; h < 4; ++h) {
            int xx = x + dx[h], yy = y + dy[h];
            if (is[xx][yy] && !~d[xx][yy]) {
                d[xx][yy] = d[x][y] + 1;
                *qe++ = xx; *qe++ = yy;
            }
        }
    }
    puts("BUG");
    
    return 0;
}
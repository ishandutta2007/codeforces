//  Codeforces Beta Round #10
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

const int INF = 1001001001;

int N, K, H;
int as[110][110], is[110][110];

int main() {
    int x, y, yy;
    int m;
    int sho, sum, tmp, xm, ym;
    
    N = in();
    K = in();
    H = (K + 1) / 2;
    for (; N--; ) {
        m = in();
        sho = INF;
        xm = ym = ~0;
        for (y = 1; y + m - 1 <= K; ++y) {
            sum = 0;
            for (yy = y; yy < y + m; ++yy) {
                sum += abs(yy - H);
            }
            for (x = 1; x <= K; ++x) {
                tmp = sum + abs(x - H) * m;
                if (is[x][y + m] - is[x][y] == 0) {
                    if (sho > tmp || sho == tmp && (xm > x || xm == x && ym > y)) {
                        sho = tmp;
                        xm = x;
                        ym = y;
                    }
                }
            }
        }
        if (sho < INF) {
            printf("%d %d %d\n", xm, ym, ym + m - 1);
            for (yy = ym; yy < ym + m; ++yy) {
                as[xm][yy] = 1;
            }
            for (yy = ym; yy <= K; ++yy) {
                is[xm][yy + 1] = is[xm][yy] + as[xm][yy];
            }
        } else {
            puts("-1");
        }
    }
    
    
    return 0;
}
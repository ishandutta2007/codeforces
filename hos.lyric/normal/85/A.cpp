//  Yandex.Algorithm 2011 Round 1

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

char CS[2][10] = { "abcdefgh", "ijklmnop" };

int N;
char ans[10][1010];

int main() {
    int x, y;
    int c, cc;
    
    for (; ~scanf("%d", &N); ) {
        c = 0;
        cc = 0;
        memset(ans, 0, sizeof(ans));
        for (x = 0; x < 2; ++x) {
            for (y = 0; y + 2 <= N; y += 2) {
                ans[x][y] = CS[x % 2][c];
                ans[x][y + 1] = CS[x % 2][c];
                ++c %= 8;
            }
        }
        for (x = 2; x < 4; ++x) {
            for (y = 1; y + 2 <= N; y += 2) {
                ans[x][y] = CS[x % 2][c];
                ans[x][y + 1] = CS[x % 2][c];
                ++c %= 8;
            }
        }
        for (x = 0; x < 4; x += 2) {
            for (y = 0; y < N; ++y) if (!ans[x][y]) {
                ans[x][y] = ans[x + 1][y] = 'y' + cc;
                ++cc %= 2;
            }
        }
        for (x = 0; x < 4; ++x) {
            puts(ans[x]);
        }
    }
    
    return 0;
}
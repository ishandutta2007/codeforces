//  Yandex.Algorithm 2011 Round 2

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

Int TEN[110];
Int L, R;

int main() {
    int i;
    int tmL, tmR;
    
    TEN[0] = 1;
    for (i = 1; i < 20; ++i) {
        TEN[i] = TEN[i - 1] * 10;
    }
    
    for (; ~scanf("%d%d", &tmL, &tmR); ) {
        L = tmL;
        R = tmR;
        Int ans = 0;
        for (i = 0; i < 15; ++i) {
            Int l = max(TEN[i], L);
            Int r = min(TEN[i + 1] - 1, R);
            if (l <= r) {
                chmax(ans, l * (TEN[i + 1] - 1 - l));
                chmax(ans, r * (TEN[i + 1] - 1 - r));
                Int x = TEN[i + 1] / 2;
                for (Int dx = -5; dx <= +5; ++dx) {
                    Int xx = x + dx;
                    if (l <= xx && xx <= r) {
                        chmax(ans, xx * (TEN[i + 1] - 1 - xx));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
//  Codeforces Beta Round #73

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

const int LIM = 100005;

int g[200010];
int flg[200010];
int counter;

int main() {
    int n, m, k, i;
    
    for (n = 1; n <= LIM; ++n) {
        for (k = 2; ; ++k) {
            int a = n - k * (k + 1) / 2;
            if (a < 0) break;
            if (a % k == 0) {
                int x = 0;
                for (i = 0; i < k; ++i) {
                    x ^= g[a / k + 1 + i];
                }
                flg[x] = n;
            }
        }
        for (m = 0; ; ++m) {
            if (flg[m] != n) {
                g[n] = m;
                break;
            }
        }
    }
//cerr<<counter<<endl;
    
    for (; ~scanf("%d", &n); ) {
        if (!g[n]) {
            puts("-1");
            continue;
        }
        int ans = n + 1;
        for (k = 2; ; ++k) {
            int a = n - k * (k + 1) / 2;
            if (a < 0) break;
            if (a % k == 0) {
                int x = 0;
                for (i = 0; i < k; ++i) {
                    x ^= g[a / k + 1 + i];
                }
                if (!x) {
                    chmin(ans, k);
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
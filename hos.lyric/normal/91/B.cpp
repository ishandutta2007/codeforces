//  Codeforces Beta Round #75

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

int N;
int A[100010];
pint ps[100010];
int ans[100010];

int main() {
    int i;
    int j, k, l;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        for (i = 0; i < N; ++i) {
            ps[i] = mp(A[i], i);
        }
        sort(ps, ps + N);
        memset(ans, 0, sizeof(ans));
        int maxPos = -1;
        for (j = 0; j < N; j = k) {
            for (k = j; k < N && ps[j].first == ps[k].first; ++k);
            for (l = j; l < k; ++l) {
                i = ps[l].second;
                ans[i] = max(maxPos - i - 1, -1);
            }
            for (l = j; l < k; ++l) {
                i = ps[l].second;
                chmax(maxPos, i);
            }
        }
        for (i = 0; i < N; ++i) {
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    
    return 0;
}
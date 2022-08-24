//  Yandex.Algorithm 2011 Finals

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

const int LIM = 1000000000;

int N;
pint A[10010];
set<pint> pts;

void solve(int s, int t) {
    if (t - s <= 1) return;
    int u = (s + t) / 2;
    solve(s, u);
    solve(u, t);
    int i;
    for (i = s; i < t; ++i) {
        pts.insert(mp(A[u].first, A[i].second));
    }
}

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            A[i].first = in();
            A[i].second = in();
        }
        sort(A, A + N);
        pts.clear();
        for (i = 0; i < N; ++i) {
            pts.insert(A[i]);
        }
        solve(0, N);
        printf("%u\n", pts.size());
        for (set<pint>::iterator it = pts.begin(), en = pts.end(); it != en; ++it) {
            printf("%d %d\n", it->first, it->second);
        }
    }
    
    return 0;
}
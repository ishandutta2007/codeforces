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

#define MAX 200010

int N, Q;
int P[MAX], L[MAX], R[MAX];
int A[MAX];
int QA[MAX];
int root, deg[MAX];
int asLen, as[MAX];
int aMin[MAX], aMax[MAX];
double ans[MAX];

void dfsMinMax(int u) {
    if (deg[u] > 0) {
        dfsMinMax(L[u]);
        dfsMinMax(R[u]);
        aMin[u] = aMin[L[u]];
        aMax[u] = aMax[R[u]];
    } else {
        aMin[u] = aMax[u] = A[u];
    }
}
void dfsAns(int u, Int sum, int cnt) {
    if (deg[u] > 0) {
        dfsAns(L[u], sum + aMin[R[u]], cnt + 1);
        dfsAns(R[u], sum + aMax[L[u]], cnt + 1);
    } else {
        int pos = lower_bound(as, as + asLen, A[u]) - as;
        ans[pos] = sum / (double)cnt;
    }
}

int main() {
    int u, q;
    
    for (; ~scanf("%d", &N); ) {
        for (u = 0; u < N; ++u) {
            P[u] = in() - 1;
            A[u] = in();
        }
        Q = in();
        for (q = 0; q < Q; ++q) {
            QA[q] = in();
        }
        root = -1;
        memset(deg, 0, sizeof(deg));
        memset(L, ~0, sizeof(L));
        memset(R, ~0, sizeof(R));
        for (u = 0; u < N; ++u) {
            if (P[u] < 0) {
                root = u;
            } else {
                ++deg[P[u]];
                if (!~L[P[u]]) {
                    L[P[u]] = u;
                } else {
                    R[P[u]] = u;
                }
            }
        }
        for (u = 0; u < N; ++u) if (deg[u] > 0) {
            if (A[L[u]] > A[R[u]]) {
                swap(L[u], R[u]);
            }
        }
//pv(A,A+N);pv(L,L+N);pv(R,R+N);
        asLen = 0;
        for (u = 0; u < N; ++u) if (deg[u] > 0) {
            as[asLen++] = A[u];
        }
        sort(as, as + asLen);
        dfsMinMax(root);
        dfsAns(root, 0, 0);
        for (q = 0; q < Q; ++q) {
            int pos = lower_bound(as, as + asLen, QA[q]) - as;
            printf("%.10f\n", ans[pos]);
        }
    }
    
    return 0;
}
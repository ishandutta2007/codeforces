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
typedef vector<string> vstr;
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

int N;
int A[MAX], B[MAX];
double X[MAX], Y[MAX];
int m, ptr[MAX], next[MAX], zu[MAX];

int dep[MAX], par[MAX];
int que[MAX], *qb, *qe;
void bfs(int root) {
    int i, u, v;
    qb = qe = que;
    memset(dep, 0, N << 2);
    dep[0] = root;
    par[0] = -1;
    *qe++ = 0;
    for (; qb != qe; ) {
        u = *qb++;
        for (i = ptr[u]; ~i; i = next[i]) {
            v = zu[i];
            if (v != par[u]) {
                dep[v] = dep[u] + 1;
                par[v] = u;
                *qe++ = v;
            }
        }
    }
}

double sum1All, sumXAll;
double sum1[MAX], sumX[MAX];
void doit(int u) {
    int i, v;
    sum1[u] = 1;
    sumX[u] = X[u];
    for (i = ptr[u]; ~i; i = next[i]) {
        v = zu[i];
        if (v != par[u]) {
            sum1[u] += sum1[v];
            sumX[u] += sumX[v];
        }
    }
}
double calc(int u) {
    int i, v;
    double ret = 0.0;
    for (i = ptr[u]; ~i; i = next[i]) {
        v = zu[i];
        if (v != par[u]) {
            ret += sum1[v] * sumX[v];
        }
    }
    ret += (sum1All - sum1[u]) * (sumXAll - sumX[u]);
    ret *= Y[u];
    return ret;
}

int main() {
    int i, u, v;
    int j;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N - 1; ++i) {
            scanf("%d%d", &A[i], &B[i]);
            --A[i];
            --B[i];
        }
        for (u = 0; u < N; ++u) {
            scanf("%lf%lf", &X[u], &Y[u]);
        }
        double XSum = accumulate(X, X + N, 0.0);
        double YSum = accumulate(Y, Y + N, 0.0);
        for (u = 0; u < N; ++u) {
            X[u] /= XSum;
            Y[u] /= YSum;
        }
        m = 0;
        memset(ptr, ~0, N << 2);
        for (i = 0; i < N - 1; ++i) {
            u = A[i];
            v = B[i];
            next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
            next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
        }
        int root = 0;
        bfs(root);
        memset(sum1, 0, N * sizeof(sum1[0]));
        memset(sumX, 0, N * sizeof(sumX[0]));
//cout<<"que : ";pv(que,que+N);
        for (j = N; j--; ) {
            doit(que[j]);
        }
        sum1All = sum1[root];
        sumXAll = sumX[root];
        double ans = 0.0;
        for (j = N; j--; ) {
            ans += calc(que[j]);
        }
        printf("%.15f\n", ans);
    }
    
    return 0;
}
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

const double INF = 1e+10;

#define MAX 400010

int N, Q;
int A[MAX], B[MAX];
int QL[MAX], QR[MAX], QT[MAX];

int segn;
int segLen[MAX];
double *segT[MAX];
int *segI[MAX];

int len, len01, LEN;
double ts[MAX], ts01[MAX], TS[MAX];
int is[MAX], is0[MAX], is1[MAX], IS[MAX];

void segMerge(int u, int v0, int v1) {
//cout<<"!!! merge : "<<u<<" "<<v0<<" "<<v1<<endl;
//cout<<"segT["<<v0<<"] : ";pv(segT[v0],segT[v0]+segLen[v0]+1);
    int x, x0, x1, xx;
    int i0, i1;
    double t, tt;
    len01 = 0;
    ts01[0] = 0.0;
    for (x0 = x1 = 0; segT[v0][x0] < INF && segT[v1][x1] < INF; ) {
        is0[len01] = segI[v0][x0];
        is1[len01] = segI[v1][x1];
        if (segT[v0][x0 + 1] <= segT[v1][x1 + 1]) {
            ts01[++len01] = segT[v0][++x0];
        } else {
            ts01[++len01] = segT[v1][++x1];
        }
    }
//cout<<"ts01 : ";pv(ts01,ts01+len01+1);
//cout<<"is0 : ";pv(is0,is0+len01);
//cout<<"is1 : ";pv(is1,is1+len01);
    len = 0;
    ts[0] = 0.0;
    for (x = 0; x < len01; ++x) {
        i0 = is0[x];
        i1 = is1[x];
        if (B[i0] != B[i1]) {
            t = -(A[i0] - A[i1]) / (double)(B[i0] - B[i1]);
            if (ts01[x] < t && t < ts01[x + 1]) {
                tt = (ts01[x] + t) / 2.0;
                is[len] = (A[i0] + B[i0] * tt >= A[i1] + B[i1] * tt) ? i0 : i1;
                ts[++len] = t;
                tt = (t + ts01[x + 1]) / 2.0;
                is[len] = (A[i0] + B[i0] * tt >= A[i1] + B[i1] * tt) ? i0 : i1;
                ts[++len] = ts01[x + 1];
                continue;
            }
        }
        tt = (ts01[x] + ts01[x + 1]) / 2.0;
        is[len] = (A[i0] + B[i0] * tt >= A[i1] + B[i1] * tt) ? i0 : i1;
        ts[++len] = ts01[x + 1];
    }
//cout<<"ts : ";pv(ts,ts+len+1);
//cout<<"is : ";pv(is,is+len);
    LEN = 0;
    TS[0] = 0.0;
    for (x = 0; x < len; x = xx) {
        for (xx = x; xx < len && is[x] == is[xx]; ++xx);
        IS[LEN] = is[x];
        TS[++LEN] = ts[xx];
    }
//cout<<"TS : ";pv(TS,TS+LEN+1);
//cout<<"IS : ";pv(IS,IS+LEN);
    segLen[u] = LEN;
    segT[u] = new double[LEN + 1];
    segI[u] = new int[LEN];
    memcpy(segT[u], TS, sizeof(double) * (LEN + 1));
    memcpy(segI[u], IS, sizeof(int) * LEN);
}

int segMaxIndex(int a, int b, double t) {
    double dai = 0.0, tmp;
    int im = N, i;
    a += segn;
    b += segn;
    for (; a <= b; a >>= 1, b >>= 1) {
        if ( a & 1) {
            i = segI[a][upper_bound(segT[a], segT[a] + segLen[a], t) - segT[a] - 1];
            tmp = A[i] + B[i] * t;
            if (dai < tmp) { dai = tmp; im = i; }
            ++a;
        }
        if (~b & 1) {
            i = segI[b][upper_bound(segT[b], segT[b] + segLen[b], t) - segT[b] - 1];
            tmp = A[i] + B[i] * t;
            if (dai < tmp) { dai = tmp; im = i; }
            --b;
        }
    }
    return im;
}

int main() {
    int q;
    int i;
    int u;
    
    for (; ~scanf("%d%d", &N, &Q); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
            B[i] = in();
        }
        A[N] = B[N] = 0;
        for (q = 0; q < Q; ++q) {
            QL[q] = in() - 1;
            QR[q] = in() - 1;
            QT[q] = in();
        }
        for (segn = 1; segn < N; segn <<= 1);
        for (i = 0; i < segn; ++i) {
            u = segn + i;
            segLen[u] = 1;
            segT[u] = new double[2];
            segI[u] = new int[1];
            segT[u][0] = 0.0;
            segT[u][1] = INF;
            segI[u][0] = min(i, N);
        }
        for (u = segn; --u; ) {
            segMerge(u, u << 1 | 0, u << 1 | 1);
        }
        for (q = 0; q < Q; ++q) {
            i = segMaxIndex(QL[q], QR[q], QT[q]);
            printf("%d\n", i + 1);
        }
        for (u = 0; u < segn << 1; ++u) {
            delete[] segT[u];
            delete[] segI[u];
        }
    }
    
    return 0;
}
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAXN 150010
#define MAXM 300010

int N, M;
double C;
double X[MAXN];
double P[MAXN];
int A[MAXM], B[MAXM];

double profit[MAXN * 2];

int segN;
struct Seg {
    double s, m, l, r;
    Seg() {}
    Seg(double x) : s(x), m(x), l(x), r(x) {}
};
Seg operator+(const Seg &a, const Seg &b) {
    Seg ret;
    ret.s = a.s + b.s;
    ret.m = max(max(a.m, b.m), a.r + b.l);
    ret.l = max(a.l, a.s + b.l);
    ret.r = max(b.r, b.s + a.r);
    return ret;
}
Seg seg[MAXN * 4];

void init(int n) {
    for (segN = 1; segN < n; segN <<= 1);
    int a;
    for (a = 0; a < segN; ++a) seg[segN + a] = Seg(profit[a]);
    for (a = segN; --a; ) seg[a] = seg[a << 1] + seg[a << 1 | 1];
}
double rangeMax(int a, int b) {
    Seg retA(0), retB(0);
    for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
        if ( a & 1) { retA = retA + seg[a]; ++a; }
        if (~b & 1) { retB = seg[b] + retB; --b; }
    }
    Seg ret = retA + retB;
    return ret.m;
}

int main() {
    int i;
    int e;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        C = in();
        --N;
        for (e = 0; e <= N; ++e) {
            X[e] = in();
        }
        for (e = 0; e < N; ++e) {
            P[e] = in() / 100.0;
        }
        for (i = 0; i < M; ++i) {
            A[i] = in() - 1;
            B[i] = in() - 1;
        }
        for (e = 0; e < N; ++e) {
            profit[e] = 0.0;
            profit[e] += (X[e + 1] - X[e]) / 2.0;
            profit[e] -= (C * P[e]) / 1.0;
        }
        init(N);
        double ans = 0.0;
        for (i = 0; i < M; ++i) {
            ans += max(rangeMax(A[i], B[i] - 1), 0.0);
        }
        printf("%.10f\n", ans);
    }
    
    return 0;
}
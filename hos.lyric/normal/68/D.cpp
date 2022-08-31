//  Codeforces Beta Round #62

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

#define MAXV 3000010

int H, Q;
int V;
int I[MAXV], L[MAXV], R[MAXV], P[MAXV];
int has[MAXV], sum[MAXV];
int len, is[110];

void analyze(int dest) {
    int i;
    len = 0;
    for (i = dest; i >= 1; i >>= 1) {
        is[len++] = i;
    }
    reverse(is, is + len);
}

void build(int h, int u, int dest, int val) {
    sum[u] += val;
    if (h + 1 == len) {
        has[u] += val;
        return;
    }
    if (~is[h + 1] & 1) {
        if (!L[u]) {
            L[V] = 0; R[V] = 0; sum[V] = 0; L[u] = V++;
        }
        build(h + 1, L[u], dest, val);
    } else {
        if (!R[u]) {
            L[V] = 0; R[V] = 0; sum[V] = 0; R[u] = V++;
        }
        build(h + 1, R[u], dest, val);
    }
}

double calc(int h, int u, int o) {
    if (!u) return o;
    int x = has[u], l = sum[L[u]], r = sum[R[u]];
//cout<<"calc. "<<x<<" "<<l<<" "<<r<<endl;
    if (h == H) {
        return max(x, o);
    }
    double ret = 0.0;
    if (l >= r) {
        ret += max(x + l, o);
        ret += calc(h + 1, L[u], max(o, x + r));
    } else {
        ret += max(x + r, o);
        ret += calc(h + 1, R[u], max(o, x + l));
    }
    ret /= 2.0;
    return ret;
}

int main() {
    int dest, val;
    char typ[10];
    
    for (; ~scanf("%d%d", &H, &Q); ) {
        memset(has, 0, sizeof(has));
        memset(sum, 0, sizeof(sum));
        V = 1;
        L[V] = 0; R[V] = 0; sum[V] = 0; ++V;
        for (; Q--; ) {
            scanf("%s", typ);
            if (!strcmp(typ, "add")) {
                dest = in();
                val = in();
                analyze(dest);
//cout<<"dest = "<<dest<<" : ";pv(is,is+len);
                build(0, 1, dest, val);
            } else {
//pv(has+1,has+V+1);pv(sum+1,sum+V+1);
                double res = calc(0, 1, 0);
                printf("%.8f\n", res);
            }
        }
//pv(sum,sum+V);
    }
    
    return 0;
}
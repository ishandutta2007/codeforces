//  Codeforces Beta Round #69

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

const int INF = 2001001001;

const int V = 7;
int E;
int A[110], B[110];
int T;
map<string,int> tr;
int PA, PB, PC;

int calc(int a, int b, int c) {
    int ps[3] = { PA / a, PB / b, PC / c };
    sort(ps, ps + 3);
    return ps[2] - ps[0];
}

int main() {
    int i;
    int a, b, c;
    int p, q, r;
    char buf0[110], buf1[110], buf2[110];
    
    for (; ~scanf("%d", &E); ) {
        T = 0;
        tr.clear();
        for (i = 0; i < E; ++i) {
            scanf("%s%s%s", buf0, buf1, buf2);
            if (!tr.count(buf0)) tr[buf0] = T++;
            if (!tr.count(buf2)) tr[buf2] = T++;
            A[i] = tr[buf0];
            B[i] = tr[buf2];
        }
        PA = in();
        PB = in();
        PC = in();
//pv(A,A+E);pv(B,B+E);
        int sho = INF;
        for (a = 1; a <= V; ++a) for (b = 1; b <= V; ++b) for (c = 1; c <= V; ++c) {
            if (a + b + c == V) {
                chmin(sho, calc(a, b, c));
            }
        }
//cout<<"sho = "<<sho<<endl;
        int dai = 0;
        for (p = 0; p < 1 << V; ++p) for (q = 0; q < 1 << V; ++q) if (!(p & q)) {
            r = (1 << V) - 1 ^ p ^ q;
            a = __builtin_popcount(p);
            b = __builtin_popcount(q);
            c = __builtin_popcount(r);
            if (a && b && c && sho == calc(a, b, c)) {
                int cnt = 0;
                for (i = 0; i < E; ++i) {
                    if ((p & 1 << A[i]) && (p & 1 << B[i])) ++cnt;
                    if ((q & 1 << A[i]) && (q & 1 << B[i])) ++cnt;
                    if ((r & 1 << A[i]) && (r & 1 << B[i])) ++cnt;
                }
                chmax(dai, cnt);
            }
        }
        printf("%d %d\n", sho, dai);
    }
    
    return 0;
}
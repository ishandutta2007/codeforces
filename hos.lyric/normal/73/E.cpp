//  Codeforces Beta Round 66

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
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

#define MAXX 2000010
const int LIM = 2000005;
int isnp[MAXX];

#define MAXN 100010

int N, X;
int A[MAXN];
int is[MAXX];

int main() {
    int i, j;
    
    /*
    for (i = 2; i * i < LIM; ++i) if (!isnp[i]) {
        for (j = i * i; j < LIM; j += i) isnp[j] = 1;
    }
    cerr << LIM - accumulate(isnp, isnp + LIM, 0) << endl;
    */
    
    for (; ~scanf("%d%d", &N, &X); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        sort(A, A + N);
        
        if (A[0] == 1) {
            puts((X == 2) ? "0" : "1");
            continue;
        }
        if (X >= LIM) {
            puts("-1");
            continue;
        }
        memset(is, 0, sizeof(is));
        int ans = 0;
        for (i = 0; i < N; ++i) {
            if (A[i] < X && !is[A[i]]) {
                ++ans;
                for (j = A[i]; j < X; j += A[i]) {
                    is[j] = 1;
                }
            }
        }
        for (j = 2; j < X; ++j) {
            if (!is[j]) {
                break;
            }
        }
        if (j < X) {
            puts("-1");
            continue;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
//  Codeforces Beta Round #80

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

const int LIM = 600;

int N, Q;
Int W[300010];
pair<pint,int> ps[300010];
Int ss[600010];
Int ans[300010];

Int out(Int x) {
    if (x >= 10) out(x / 10);
    putchar('0' + x % 10);
}

int main() {
    int i, q;
    int a, b;
    Int sum;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            W[i] = in();
        }
        Q = in();
        for (q = 0; q < Q; ++q) {
            ps[q].first.second = in() - 1;
            ps[q].first.first = in();
            ps[q].second = q;
        }
        sort(ps, ps + Q);
        for (q = 0; q < Q; ++q) {
            a = ps[q].first.second;
            b = ps[q].first.first;
            if (b >= LIM) {
                sum = 0;
                for (i = a; i < N; i += b) {
                    sum += W[i];
                }
            } else {
                if (q == 0 || ps[q - 1].first.first != ps[q].first.first) {
                    for (i = N; i--; ) {
                        ss[i] = W[i] + ss[i + b];
                    }
                }
                sum = ss[a];
            }
            ans[ps[q].second] = sum;
        }
        for (q = 0; q < Q; ++q) {
            out(ans[q]);
            puts("");
        }
    }
    
    return 0;
}
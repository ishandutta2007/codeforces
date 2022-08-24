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

int uf[100010];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

const Int MO = 1000000009;
Int mod(Int a) { return (a % MO + MO) % MO; }

int N, M;
int A[100010], B[100010];

int main() {
    int i;
    
    for (; ~scanf("%d%d", &N, &M); ) {
        for (i = 0; i < M; ++i) {
            A[i] = in() - 1;
            B[i] = in() - 1;
        }
        memset(uf, ~0, N << 2);
        Int two = 1;
        for (i = 0; i < M; ++i) {
            if (!conn(A[i], B[i])) {
                two = mod(two * 2);
            }
            cout << mod(two - 1) << endl;
        }
    }
    
    return 0;
}
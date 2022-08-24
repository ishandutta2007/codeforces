//  Codeforces Beta Round #19
//  Problem C

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

const Int P = 10;
Int pk[100010];

int N;
int A[100010];
Int hash[100010];

int next[100010];
map<int,int> is;

int sz[100010], pos[100010];

bool hasher(int a, int b, int c) {
    return (hash[b] - hash[a] * pk[b - a] == hash[c] - hash[b] * pk[c - b]);
}

int main() {
    int i, j;
    int tmp;
    
    N = in();
    for (i = 0; i < N; ++i) {
        A[i] = in();
        hash[i + 1] = hash[i] * P + A[i];
    }
    pk[0] = 1;
    for (i = 0; i < N; ++i) {
        pk[i + 1] = pk[i] * P;
    }
    
    for (i = 0; i < N; ++i) {
        next[i] = N;
    }
    for (i = 0; i < N; ++i) {
        if (is.count(A[i])) {
            next[is[A[i]]] = i;
        }
        is[A[i]] = i;
    }
//pv(next,next+N);
//pv(hash,hash+N+1);
    
    sz[N] = N;
    pos[N] = N;
    for (i = N; i--; ) {
        sz[i] = sz[i + 1];
        pos[i] = pos[i + 1];
        for (j = i; (j = next[j]) < N; ) {
            tmp = j - i;
            if (j + tmp <= N && sz[i] > tmp) {
                if (hasher(i, j, j + tmp)) {
                    pos[i] = j;
                }
            }
        }
    }
    
    i = 0;
    for (; pos[i] < N; ) {
        i = pos[i];
    }
    int ou = 0;
    printf("%d\n", N - i);
    for (; i < N; ++i) {
        if (ou++) putchar(' ');
        printf("%d", A[i]);
    }
    puts("");
    
    return 0;
}
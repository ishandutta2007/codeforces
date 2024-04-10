//  Codeforces Beta Round #12
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

int N, M, L;
int A[110], B[110];
map<string,int> frs;

int main() {
    int i;
    int sho = 0, dai = 0;
    string str;
    
    N = in();
    M = in();
    for (i = 0; i < N; ++i) {
        A[i] = in();
    }
    for (; M--; ) {
        cin >> str;
        if (!frs.count(str)) frs[str] = 0;
        ++frs[str];
    }
    for (map<string,int>::iterator it = frs.begin(), en = frs.end(); it != en; ++it) {
        B[L++] = it->second;
    }
    sort(B, B + L, greater<int>());
    sort(A, A + N);
    for (i = 0; i < L; ++i) {
        sho += A[i] * B[i];
    }
    reverse(A, A + N);
    for (i = 0; i < L; ++i) {
        dai += A[i] * B[i];
    }
    printf("%d %d\n", sho, dai);
    
    return 0;
}
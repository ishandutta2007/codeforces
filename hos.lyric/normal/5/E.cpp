//  Codeforces Beta Round #5
//  Problem E

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

int N;
int A[2000010];
bool ok[1000010];
int _st[1000010];

int main() {
    int i, im, pos;
    int dai;
    Int ans = 0;
    
    N = in();
    for (i = 0; i < N; ++i) {
        A[i] = A[i + N] = in();
    }
    im = 0;
    for (i = 0; i < N; ++i) {
        if (A[im] < A[i]) im = i;
    }
    int *a = A + im;
    dai = 0;
    for (i = 1; i < N; ++i) {
        if (dai <= a[i]) {
            dai = a[i];
            ok[i] = 1;
        }
    }
    dai = 0;
    for (i = N - 1; i; --i) {
        if (dai <= a[i]) {
            dai = a[i];
            ok[i] = 1;
        }
    }
//pv(ok,ok+N);
    for (i = 1; i < N; ++i) {
        if (ok[i]) ++ans;
    }
    int *st = _st;
    *st = *a;
    for (i = 1; i < N; ++i) {
//cout<<ans<<endl;
        pos = lower_bound(_st + 2, st + 1, a[i], greater<int>()) - _st - 1;
        ans += max(st - _st + 1 - pos, 0);
        for (; *st < a[i]; --st);
        *++st = a[i];
    }
    cout << ans << endl;
    
    return 0;
}
//  Codeforces Beta Round #8
//  Problem A

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

char answers[][10] = { "fantasy", "forward", "backward", "both", };

int L, M, N;
string A, B, C;
char buf[100010];

int solve() {
    int i;
    for (i = 0; i + M <= L; ++i) {
        if (A.substr(i, M) == B) break;
    }
    for (i += M; i + N <= L; ++i) {
        if (A.substr(i, N) == C) return 1;
    }
    return 0;
}

int main() {
    int ans = 0;
    
    A = gets(buf);
    B = gets(buf);
    C = gets(buf);
    L = A.length();
    M = B.length();
    N = C.length();
    
    ans |= solve();
    reverse(A.begin(), A.end());
    ans |= solve() << 1;
    
    puts(answers[ans]);
    
    return 0;
}
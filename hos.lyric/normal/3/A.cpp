//  Codeforces Beta Round #3
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



int main() {
    int a, b, c, d;
    
    a = in_c() - 'a';
    b = in_c() - '0';
    c = in_c() - 'a';
    d = in_c() - '0';
    
    int n = max(abs(c - a), abs(d - b));
    
    printf("%d\n", n);
    for (; n--; ) {
        if (a < c) { putchar('R'); ++a; }
        if (a > c) { putchar('L'); --a; }
        if (b < d) { putchar('U'); ++b; }
        if (b > d) { putchar('D'); --b; }
        puts("");
    }
    
    return 0;
}
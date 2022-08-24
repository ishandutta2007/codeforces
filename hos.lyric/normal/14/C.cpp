//  Codeforces Beta Round #14
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

typedef pair<Int,Int> Pt;
#define x first
#define y second

Pt operator-(Pt &a, Pt &b) {
    return mp(a.x - b.x, a.y - b.y);
}

Pt A[10];
set< pair<Pt,Pt> > es;

bool isrect(Pt a, Pt b, Pt c, Pt d) {
    if (!es.count(mp(a, b))) return 0;
    if (!es.count(mp(a, c))) return 0;
    if (!es.count(mp(b, d))) return 0;
    if (!es.count(mp(c, d))) return 0;
//printf("(%lld,%lld)",a.x,a.y);printf("(%lld,%lld)",b.x,b.y);printf("(%lld,%lld)",c.x,c.y);printf("(%lld,%lld)",d.x,d.y);cout<<endl;
    if (a.y != b.y) return 0;
    if (c.y != d.y) return 0;
    if (a.x != c.x) return 0;
    if (b.x != d.x) return 0;
    if (a.x == b.x) return 0;
    if (a.y == c.y) return 0;
    return 1;
}

int main() {
    int i;
    int a, b, c, d;
    
    for (i = 0; i < 8; ++i) {
        A[i].x = in();
        A[i].y = in();
    }
    for (i = 0; i < 8; i += 2) {
        es.insert(mp(A[i], A[i + 1]));
        es.insert(mp(A[i + 1], A[i]));
    }
    
    for (a = 0; a < 8; ++a) for (b = 0; b < 8; ++b) for (c = 0; c < 8; ++c) for (d = 0; d < 8; ++d) {
        if (isrect(A[a], A[b], A[c], A[d])) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    
    return 0;
}
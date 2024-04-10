//  Codeforces Beta Round #3
//  Problem D

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

const Int INF = 1001001001001LL;

int N;
char S[50010];

int main() {
    int i;
    Int a, b;
    Int ans = 0;
    priority_queue< pair<Int,int> > q;
    
    scanf("%s", S);
    N = strlen(S);
    for (i = 0; i < N; ++i) {
        switch (S[i]) {
            case '(': {
                a = 0;
                b = INF;
            } break; case ')': {
                a = INF;
                b = 0;
            } break; default: {
                S[i] = ')';
                a = in();
                b = in();
            }
        }
        ans += b;
        q.push(mp(b - a, i));
        if (~i & 1) {
            ans -= q.top().first;
            S[q.top().second] = '(';
            q.pop();
        }
    }
    if (ans >= INF) {
        puts("-1");
    } else {
        printf("%I64d\n", ans);
        puts(S);
    }
    
    return 0;
}
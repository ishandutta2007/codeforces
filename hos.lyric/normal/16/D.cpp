//  Codeforces Beta Round #16
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

const int M = 1001001;

int N;
char buf[100010];

int main() {
    int i;
    int bef = M * 3, tmp;
    int ans = 0;
    int cnt = 0;
    
    N = atoi(gets(buf));
    for (i = 0; i < N; ++i) {
        gets(buf);
        tmp = 0;
        tmp += atoi(buf + 1) % 12 * 60;
        tmp += atoi(buf + 4);
        if (buf[7] == 'p') tmp += M;
        if (bef == tmp) {
            if (cnt == 10) {
                ++ans;
                cnt = 0;
            }
        } else {
            cnt = 0;
            if (bef > tmp) ++ans;
        }
        ++cnt;
        bef = tmp;
    }
    printf("%d\n", ans);
    
    
    return 0;
}
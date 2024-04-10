//  Codeforces Beta Round #17
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

int N, K;
int isnp[1010];
int ok[2010];

int main() {
    int i, j;
    
    N = in();
    K = in();
    isnp[0] = isnp[1] = 1;
    for (i = 2; i * i <= N; ++i) if (!isnp[i]) {
        for (j = i * i; j <= N; j += i) isnp[j] = 1;
    }
    
    for (i = 2; i <= N; ++i) if (!isnp[i]) {
        for (j = i + 1; j <= N; ++j) if (!isnp[j]) {
            ok[i + j + 1] = 1;
            break;
        }
    }
    
    int cnt = 0;
    for (i = 2; i <= N; ++i) if (!isnp[i]) {
        cnt += ok[i];
//if(ok[i])cout<<i<<endl;
    }
    puts((cnt >= K) ? "YES" : "NO");
    
    
    return 0;
}
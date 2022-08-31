//  Codeforces Beta Round #51 (D)

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

const int M = 2520;
const int L = 19;

Int TEN[30];
int ten[30];

Int N;
int A[30];
map<int,Int> mem[30][2530];

Int calc(int i, int d, int r, bool limited = 0) {
    if (i == -1) {
        return (r % d == 0) ? 1 : 0;
    }
    if (!limited && mem[i][d].count(r)) {
        return mem[i][d][r];
    }
    Int ret = 0;
    int j;
    for (j = 0; j < 10; ++j) if (!limited || j <= A[i]) {
        int dd = j ? (d / __gcd(d, j) * j) : d;
        int rr = (r + j * ten[i]) % M;
        ret += calc(i - 1, dd, rr, limited && j == A[i]);
    }
    if (!limited) {
        mem[i][d][r] = ret;
    }
    return ret;
}

Int solve(Int n) {
    int i;
    
    N = n;
    for (i = 0; i < L; ++i) {
        A[i] = (int)(N / TEN[i] % 10);
    }
    
    Int ret = calc(L - 1, 1, 0, 1);
//cout<<"solve "<<n<<" : "<<ret<<endl;
    return ret;
}

int main() {
    int i;
    
    TEN[0] = 1;
    for (i = 0; i <= L; ++i) {
        TEN[i + 1] = TEN[i] * 10;
    }
    for (i = 0; i <= L; ++i) {
        ten[i] = (int)(TEN[i] % M);
    }
    
    Int l, r;
    
    int TC;
    for (cin >> TC; TC--; ) {
        cin >> l >> r;
        Int ans = solve(r) - solve(l - 1);
        cout << ans << endl;
    }
    
    return 0;
}
//  Codeforces Beta Round #51 (E)

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

typedef unsigned long long UInt;

int N;
Int X[200010], Y[200010];
Int AX, AY;

int sGP() {
    int side = -1;
    int i;
    for (i = 0; i < N; ++i) {
        Int x0 = X[i] - AX;
        Int y0 = Y[i] - AY;
        Int x1 = X[i + 1] - AX;
        Int y1 = Y[i + 1] - AY;
        if (y0 > y1) {
            swap(x0, x1);
            swap(y0, y1);
        }
        if (y0 <= 0 && 0 < y1 && x0 * y1 - y0 * x1 > 0) side = -side;
    }
    return side;
}

int main() {
    int i, j;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            X[i] = in();
            Y[i] = in();
        }
        reverse(X + 1, X + N);
        reverse(Y + 1, Y + N);
        for (i = 0; i <= N; ++i) {
            X[i + N] = X[i];
            Y[i + N] = Y[i];
        }
        for (int qry = in(); qry--; ) {
            AX = in();
            AY = in();
            if (sGP() < 0) {
                puts("0");
                continue;
            }
//cout<<"hello"<<endl;
            UInt ans = 0;
            for (i = j = 0; i < N; ++i) {
                for (; ; ++j) {
                    if (i == j) continue;
                    Int xi = X[i] - AX;
                    Int yi = Y[i] - AY;
                    Int xj = X[j] - AX;
                    Int yj = Y[j] - AY;
                    if (xi * yj - yi * xj <= 0) break;
                }
                Int k = j - i - 1;
//cout<<i<<" "<<j<<endl;
                if (k >= 0) {
                    ans += k * (k - 1) / 2;
                }
            }
            UInt n = N;
            ans += n * (n - 1) / 2 * (n - 2) / 3 * n;
            ans = -ans;
            ++n;
            ans += n * (n - 1) / 2 * (n - 2) / 3 * (n - 3);
            cout << ans << endl;
        }
    }
//UInt m=100001;m=m*(m-1)/2*(m-2)/3*(m-3);cout<<m<<endl;
    
    return 0;
}
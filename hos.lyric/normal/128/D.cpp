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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
int A[100010];

int M;
int is[100010];

bool solve() {
    int i;
    
    memset(is, 0, sizeof(is));
    int minA = A[0];
    for (i = 0; i < N; ++i) {
        chmin(minA, A[i]);
    }
    for (i = 0; i < N; ++i) {
        if (A[i] - minA >= N) {
            return 0;
        }
        ++is[A[i] - minA];
    }
    
    for (i = 0; is[i]; ++i);
    M = i;
    if (accumulate(is, is + M, 0) != N) {
        return 0;
    }
    
    if (M <= 1) return 0;
//cout<<"is : ";pv(is,is+M);
    int a = 0;
    for (i = 0; i < M; ++i) {
        a = is[i] * 2 - a;
        if (a < 0) return 0;
        if (i < M - 1 && a == 0) return 0;
    }
    if (a != 0) return 0;
    
    return 1;
}

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        bool res = solve();
        puts(res ? "YES" : "NO");
    }
    
    return 0;
}
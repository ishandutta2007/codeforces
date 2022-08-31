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

#define MAXN 100010

int N;
int A[MAXN];
int ans[MAXN];
int as[MAXN];

void check(int pos) {
    int i;
    for (i = 0; i < N; ++i) {
        as[i] = A[i];
    }
    as[pos] = (as[pos] == 1) ? 2 : 1;
    sort(as, as + N);
    for (i = 0; i < N; ++i) {
        chmin(ans[i], as[i]);
    }
}

int main() {
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        sort(A, A + N);
        memset(ans, 0x3f, N << 2);
        check(0);
        check(N - 1);
        for (i = 0; i < N; ++i) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    
    return 0;
}
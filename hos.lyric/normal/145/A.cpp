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
char A[MAXN], B[MAXN];

int main() {
    int i;
    
    for (; ~scanf("%s%s", A, B); ) {
        N = strlen(A);
        int a = 0, b = 0;
        for (i = 0; i < N; ++i) {
            if (A[i] == '4' && B[i] == '7') ++a;
            if (A[i] == '7' && B[i] == '4') ++b;
        }
        int ans = max(a, b);
        printf("%d\n", ans);
    }
    
    return 0;
}
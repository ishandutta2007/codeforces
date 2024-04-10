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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, K;
int A[110];

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    int i, j;
    
    for (; ~scanf("%d%d", &N, &K); ) {
        for (i = 0; i < N; ++i) {
            A[i] = in();
        }
        int ans = 0;
        for (i = 0; i < N; ++i) {
            int a = A[i];
            for (j = 0; j < 3; ++j) if (a >= K) a -= K;
            ans += a;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
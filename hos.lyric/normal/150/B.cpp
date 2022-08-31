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

const Int MO = 1000000007;

#define MAXN 2010

int uf[MAXN];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (uf[x] > uf[y]) swap(x, y);
    uf[x] += uf[y]; uf[y] = x;
    return 1;
}

int N, M, K;

int main() {
    int i, x, y;
    
    for (; ~scanf("%d%d%d", &N, &M, &K); ) {
        memset(uf, ~0, N << 2);
        for (i = 0; i + K <= N; ++i) {
            for (x = i, y = i + K - 1; x < y; ++x, --y) {
                conn(x, y);
            }
        }
        Int ans = 1;
        for (i = 0; i < N; ++i) {
            if (uf[i] < 0) {
                ans *= M;
                ans %= MO;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
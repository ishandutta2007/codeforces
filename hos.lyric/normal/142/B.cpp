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

int solve(int m, int n) {
    if (m > n) swap(m, n);
    if (m == 1) {
        return n;
    }
    if (m == 2) {
        int ret = n / 4 * 2;
        ret += min(n % 4, 2);
        ret *= 2;
        return ret;
    }
    return (m * n + 1) / 2;
}

int main() {
    int m, n;
    
    for (; ~scanf("%d%d", &m, &n); ) {
        int res = solve(m, n);
        printf("%d\n", res);
    }
    
    return 0;
}
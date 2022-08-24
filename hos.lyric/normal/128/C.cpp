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
void pl(Int &t, Int f) { (t += f) %= MO; }

const int LIM = 1005;
Int dp[1010][1010];

int main() {
    int i, j, k;
    
    for (j = 1; j < LIM; ++j) {
        dp[0][j] = 1;
    }
    for (i = 1; i < LIM; ++i) {
        Int sum = 0, sumSum = 0;
        for (j = 3; j < LIM; ++j) {
            pl(sum, dp[i - 1][j - 2]);
            pl(sumSum, sum);
            dp[i][j] = sumSum;
        }
    }
    
    int n, m;
    for (; ~scanf("%d%d%d", &n, &m, &k); ) {
        Int ans = 1;
        ans = (ans * dp[k][n]) % MO;
        ans = (ans * dp[k][m]) % MO;
        cout << ans << endl;
    }
    
    return 0;
}
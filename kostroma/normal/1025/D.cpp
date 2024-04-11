#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>
#include <ctime>

using namespace std;

#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()

const int N = 710;
int a[N];
bool g[N][N];
int dp[N][N][3];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool go(int L, int R, int dir) {
    if (dp[L][R][dir] != -1) {
        return dp[L][R][dir];
    }
    for (int i = L; i <= R; i++) {
        if ((dir == 0 && g[i][R + 1]) || (dir == 1 && g[i][L - 1]) || (dir == 2)) {
            bool f = true;
            if (i > L) f = (f && go(L, i - 1, 0));
            if (i < R) f = (f && go(i + 1, R, 1));
            if (f) return dp[L][R][dir] = 1;
        }
    }
    return dp[L][R][dir] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) REP(j, n) g[i][j] = (gcd(a[i], a[j]) > 1);
    memset(dp, -1, sizeof(dp));
    cout << (go(0, n - 1, 2) ? "YES" : "NO") << endl;
    return 0;
}
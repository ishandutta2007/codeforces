#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

const int INF = 1e9;
const int MOD = 998244353;

int solve(vector<int> p) {
    int n = p.size();
    vector<vector<int>> e(n);
    for (int i =1 ; i < n; i++) e[p[i]].push_back(i);

    vector<vector<int>> dp(n, vector<int>(2));
    for (int v = n - 1; v >= 0; v--) {
        if (e[v].empty()) {
            dp[v][0] = dp[v][1] = 1;
            continue;
        }

        vector<int> cdp(3);
        cdp[0] = 1;
        for (int to : e[v]) {
            vector<int> ndp(3);
            for (int j = 0; j < 3; j++) {
                ndp[j] = (ndp[j] + 1LL * cdp[j] * dp[to][0]) % MOD;
                int nj = min(2, j + 1);
                ndp[nj] = (ndp[nj] + 1LL * cdp[j] * dp[to][1]) % MOD;
            }
            cdp = ndp;
        }
        cdp[1] = (cdp[1] + cdp[2]) % MOD;
        cdp[0] = (cdp[0] + cdp[2]) % MOD;

        dp[v][0] = cdp[0];
        dp[v][1] = cdp[1];
        //cdp[0] = (cdp[0] + )
    }
    return dp[0][0];
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> p(n);
        p[0] = -1;
        for (int i= 1; i < n; i++) {
            scanf("%d", &p[i]);
            p[i]--;
        }

        printf("%d\n", solve(p));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}
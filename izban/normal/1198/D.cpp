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


const int INF = 1.01e9;

int solve(vector<vector<int>> a) {
    int n = a.size();

    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }

//    for (int i = 0; i < n; i++) {
//        dbv(a[i]);
//    }

    auto get = [&](int u, int l, int d, int r) {
        return s[d+1][r+1] - s[u][r+1] - s[d+1][l] + s[u][l];
    };

    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n))));
    for (int u = n - 1; u >= 0; u--) {
        for (int l = n - 1; l >= 0; l--) {
            for (int d = u; d < n; d++) {
                for (int r = l; r < n; r++) {
                    if (get(u, l, d, r) == 0) {
                        dp[u][l][d][r] = 0;
                    } else {
                        dp[u][l][d][r] = max(d - u + 1, r - l + 1);
                        for (int x = u; x < d; x++) {
                            dp[u][l][d][r] = min(dp[u][l][d][r], dp[u][l][x][r] + dp[x+1][l][d][r]);
                        }
                        for (int y = l; y < r; y++) {
                            dp[u][l][d][r] = min(dp[u][l][d][r], dp[u][l][d][y] + dp[u][y+1][d][r]);
                        }
                    }
                }
            }
        }
    }
//    if (n == 4) {
//        db(dp[0][1][3][3]);
//        db(get(0,1,3,3));
//    }
    return dp[0][0][n-1][n-1];
}

void test() {
    int n = 50;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 2;
        }
    }
    db(solve(a));
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            static char buf[(int)1.1e6];
            scanf(" %s", buf);
            for (int j = 0; j < n; j++) {
                a[i][j] = buf[j] == '#';
            }
        }

        printf("%d\n", solve(a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}
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




int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        m += 100;

        vector<int> b(m + 1);
        for (int x : a) b[x + 50]++;

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(3, vector<int>(3, -1)));
        dp[5][0][0] = 0;

        for (int i = 5; i < m; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (dp[i][j][k] < 0) continue;

                    for (int l = 0; l <= 2; l++) {
                        bool ok = 1;
                        ok &= b[i - 2] >= j + k + l;
                        if (!ok) continue;

                        dp[i + 1][l][j] = max(dp[i + 1][l][j], dp[i][j][k] + (b[i - 2] - j - k - l) / 3 + l);
                    }
                }
            }
        }
        cout << dp[m][0][0] << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}
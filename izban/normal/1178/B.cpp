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

    string s;
    while (cin >> s) {
        int n = s.length();

        vector<vector<ll>> dp(n + 1, vector<ll>(4));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 3; j++) {
                dp[i + 1][j] += dp[i][j];
            }
            if (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v') {
                dp[i + 1][1] += dp[i][0];
                dp[i + 1][3] += dp[i][2];
            }
            if (s[i] == 'o') {
                dp[i + 1][2] += dp[i][1];
            }
        }
        cout << dp[n][3] << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}
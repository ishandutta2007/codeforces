#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9 + 7;

const int N = 1.1e3;

int dp[N][N][2];

void add(int &x, int y) {
    x = (x + y) % MOD;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    string s;
    int k;
    while (cin >> s >> k) {
        int n = s.length();
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int f = 0; f < 2; f++) {
                    for (int c = 0; c < 2; c++) {
                        if (f == 0 && s[i] - '0' < c) continue;
                        int nf = f || s[i] - '0' > c;
                        add(dp[i + 1][j + c][nf], dp[i][j][f]);
                    }
                }
            }
        }

        vector<int> a(n + 1);
        a[0] = -2;
        a[1] = 0;
        for (int i = 2; i <= n; i++) {
            int cnt = 0;
            int x = i;
            while (x > 0) {
                cnt += x % 2;
                x /= 2;
            }
            a[i] = 1 + a[cnt];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (1 + a[i] == k) {
                add(ans, dp[n][i][0]);
                add(ans, dp[n][i][1]);
            }
        }
        if (k == 0) {
            ans = 1;
        }
        if (k == 1) {
            ans = (ans - 1 + MOD) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
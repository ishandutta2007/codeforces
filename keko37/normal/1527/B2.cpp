#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;

int t, n;
string s;
int dp[MAXN][MAXN][2][2];

int f (int a, int b, int mid, int flg) {
    if (a == 0 && b == 0 && mid == 1) return 0;
    if (dp[a][b][mid][flg] != -1e9) return dp[a][b][mid][flg];
    int res = -1e9;
    if (a >= 1) res = max(res, -f(a - 1, b + 1, mid, 0) - 1);
    if (b >= 1) res = max(res, -f(a, b - 1, mid, 0) - 1);
    if (b != 0 && flg == 0) {
        res = max(res, -f(a, b, mid, 1));
    }
    if (mid == 0) res = max(res, -f(a, b, 1, 0) - 1);
    return dp[a][b][mid][flg] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            for (int mid = 0; mid < 2; mid++) {
                dp[i][j][mid][0] = dp[i][j][mid][1] = -1e9;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int a = 0, b = 0;
        for (int i = 0; i < n - i - 1; i++) {
            if (s[i] == '0' && s[n - i - 1] == '0') {
                a++;
            } else if (s[i] != s[n - i - 1]) {
                b++;
            }
        }
        int val;
        if (n % 2 == 1 && s[n / 2] == '0') {
            val = f(a, b, 0, 0);
        } else {
            val = f(a, b, 1, 0);
        }
        if (val == 0) cout << "DRAW\n"; else if (val > 0) cout << "ALICE\n"; else cout << "BOB\n";
    }
    return 0;
}
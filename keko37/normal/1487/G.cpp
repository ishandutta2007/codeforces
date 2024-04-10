#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 405;
const int MOD = 998244353;

int n, sol;
int cnt[30];
int dp[MAXN][MAXN][3][3], prosli[MAXN][MAXN][3][3];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void calc () {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            prosli[0][0][x][y] = 1;
        }
    }
    for (int pos = 1; pos <= n; pos++) {
        for (int a = 0; a <= pos; a++) {
            for (int b = 0; a + b <= pos; b++) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int res = 0;
                        if (y != 0 || pos > n - 2) res = add(res, prosli[max(a - 1, 0)][b][0][x]);
                        if (y != 1 || pos > n - 2) res = add(res, prosli[a][max(b - 1, 0)][1][x]);
                        res = add(res, mul(prosli[a][b][2][x], 24 - (y == 2 && pos <= n - 2)));
                        dp[a][b][x][y] = res;
                    }
                }
            }
        }
        for (int a = 0; a <= pos; a++) {
            for (int b = 0; a + b <= pos; b++) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        prosli[a][b][x][y] = dp[a][b][x][y];
                    }
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < 26; i++) {
        cin >> cnt[i];
        cnt[i]++;
    }
    calc();
    sol = dp[0][0][0][0];
    for (int i = 0; i < 26; i++) {
        sol = sub(sol, dp[cnt[i]][0][0][0]);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            sol = add(sol, dp[cnt[i]][cnt[j]][0][0]);
        }
    }
    cout << sol;
    return 0;
}
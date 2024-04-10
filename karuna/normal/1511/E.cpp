#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 3e5 + 10;
const lint MOD = 998244353;

lint n, m, A[MAX], B[MAX], Dp[MAX]; 
string S[MAX];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string T; cin >> T; S[i] = "*" + T;
    }
    B[0] = A[1] = B[1] = 1;
    for (int i = 2; i < MAX; i++) {
        A[i] = B[i - 1]; B[i] = (2 * A[i - 1] + B[i - 1]) % MOD;
    }
    Dp[1] = 0; Dp[2] = 1;
    for (int i = 3; i < MAX; i++) Dp[i] = (4 * Dp[i - 2] + B[i - 1]) % MOD;
    lint ans = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i][j] == 'o') ++x;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1, s = 0; j <= m; j++) {
            if (S[i][j] == 'o') ++s;
            if (j == m || S[i][j] == '*') ans += Dp[s] * (A[x - s] + B[x - s]) % MOD, s = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1, s = 0; j <= n; j++) {
            if (S[j][i] == 'o') ++s;
            if (j == n || S[j][i] == '*') ans += Dp[s] * (A[x - s] + B[x - s]) % MOD, s = 0;
        }
    }
    cout << ans % MOD;
}
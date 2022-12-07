#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5005;
const int MOD = 1000000007;

int jump[N][N];
char tmp[N];
int tn;

void exkmp(char *str, int *jump, int n) {
    jump[1] = n;
    int k = 1;
    while (k + 1 <= n && str[k] == str[k + 1]) k++;
    jump[2] = k - 1;
    k = 2;
    for (int i = 3; i <= n; i++) {
        if (jump[i - k + 1] + i - 1 < jump[k] + k - 1) jump[i] = jump[i - k + 1];
        else {
            int j = max(0, jump[k] + k - 1 - i);
            while (i + j <= n && str[j + 1] == str[j + i]) j++;
            jump[i] = j;
            k = i;
        }
    }
}

int n;
int dp[N][N];
char str[N];

int get(int l, int r) {
    if (r + 1 > n || str[r + 1] == '0') return -1;
    int len = jump[l][r + 1 - l + 1];
    if (len >= r - l + 1) return r - l + 2;
    else {
        if (str[l + len] < str[r + len + 1]) return r - l + 1;
        else return r - l + 2;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        tn = 0;
        for (int j = i; j <= n; j++) {
            tmp[++tn] = str[j];
        }
        exkmp(tmp, jump[i], tn);
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i][j] == 0) continue;
            if (i + 1 <= n) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            int tmp = get(j, i);
            if (tmp != -1 && i + tmp <= n) dp[i + tmp][i + 1] = (dp[i + tmp][i + 1] + dp[i][j]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[n][i]) % MOD;
    printf("%d\n", ans);
    return 0;
}
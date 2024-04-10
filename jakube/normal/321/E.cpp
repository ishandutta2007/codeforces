#include <bits/stdc++.h>
using namespace std;

int prefix[4001][4001];
int dp[2][4001];
int xxx;

int sum(int i, int j) {
    return (prefix[j][j] - prefix[i-1][j] * 2 + prefix[i-1][i-1]);
}

void solve(int K, int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) >> 1;
    int opt = optl;
    dp[xxx][m] = dp[xxx^1][opt-1] + sum(opt, m);
    for (int i = optl+1; i <= min(optr, m); i++) {
        int f = dp[xxx^1][i-1] + sum(i, m);
        if (f < dp[xxx][m]) {
            opt = i;
            dp[xxx][m] = f;
        }
    }
    solve(K, l, m-1, optl, opt);
    solve(K, m+1, r, opt, optr);
}


int readInt () {
	char ch;
	ch = getchar();
	while (true) {
		if (ch >= '0' && ch <= '9') return ch - '0';
		ch = getchar();
	}
}

int main() {
    int inf = numeric_limits<int>::max() / 2;
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i+1][j+1] = readInt() + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[0][i] = inf;

    xxx = 0;
    for (int K = 1; K <= k; K++) {
        xxx ^= 1;
        dp[xxx][0] = inf;
        solve(K, 1, n, 1, n);
    }

    printf("%d\n", dp[xxx][n] / 2);
}
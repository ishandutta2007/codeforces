#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 210;
const lint MOD = 1e9 + 7, T = 5e8 + 4;

lint n, C[M][M], Sub[M][M], Dep[M][M], Par[M][M];
vector<int> G[M];

lint _pow(lint a, lint x = MOD - 2) {
    lint ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return ret;
}
void dfs(int p, int cur, int r) {
    Sub[r][cur] = 1;
    for (int x : G[cur]) if (p != x) {
        Dep[r][x] = Dep[r][cur] + 1; 
        Par[r][x] = cur;
        dfs(cur, x, r);
        Sub[r][cur] += Sub[r][x];
    }
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) * T % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        Dep[i][i] = -1; dfs(i, i, i);
    }
    lint ans = 0;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        ans = (ans + Sub[i][j]) % MOD;

        int c = 0;
        for (int k = j; Par[i][k] != i; k = Par[i][k]) {
            ans = (ans + C[Dep[i][j]][++c] * (Sub[i][Par[i][k]] - Sub[i][k]) % MOD) % MOD;
        }
    }
    cout << ans * _pow(n) % MOD;
}
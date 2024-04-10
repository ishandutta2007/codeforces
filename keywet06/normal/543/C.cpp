#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;
const int N = 20;

int dp[1 << N];
int Sum[N][26], Mas[N][26], Max[N][26];
int a[N][N];

std::string s[N];

int main() {
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int pos = 0; pos < m; ++pos) {
            char c = s[i][pos] - 'a';
            Sum[pos][c] += a[i][pos];
            Mas[pos][c] |= (1 << i);
            Max[pos][c] = max(Max[pos][c], a[i][pos]);
        }
    }
    int Tsk = (1 << n);
    for (int i = 0; i < Tsk; ++i) dp[i] = INF;
    dp[0] = 0;
    for (int pos = 0; pos < m; ++pos) {
        for (int mask = 0; mask < Tsk; ++mask) {
            if (dp[mask] == INF) continue;
            for (int i = 0; i < n; ++i) {
                int nmask = mask | (1 << i);
                int nval = dp[mask] + a[i][pos];
                if (dp[nmask] > nval) dp[nmask] = nval;
                int c = s[i][pos] - 'a';
                nmask = mask | Mas[pos][c];
                nval = dp[mask] + Sum[pos][c] - Max[pos][c];
                if (dp[nmask] > nval) dp[nmask] = nval;
            }
        }
    }
    std::cout << dp[Tsk - 1] << std::endl;
    return 0;
}
#include <bits/stdc++.h>

const int C = 19;
const int N = 1 << 17;

bool r[C][C][N], rem[N];

int n, m;
int A[N], P[C][C], c[C][N], pp[N], dp[N];

std::string S;

int main() {
    std::cin >> n >> m >> S;
    for (int i = 1; i <= n; ++i) A[i] = (S[i - 1] - 'a'), ++c[A[i]][i];
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) c[i][j] += c[i][j - 1];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> P[i][j];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (P[i][j] == 1) continue;
            int pres = -1;
            for (int k = 1; k <= n; ++k) {
                if (A[k] == j && pres != -1) {
                    int sums = 0;
                    for (int l = 0; l < m; ++l) {
                        int G = c[l][k - 1] - c[l][pres];
                        if (G >= 1) sums += (1 << l);
                    }
                    r[i][j][sums] = true;
                }
                if (A[k] == i) pres = k;
            }
            int cnt1 = 0;
            for (int k = 0; k < (1 << m); ++k) {
                if ((k & (1 << i)) == 0 && (k & (1 << j)) == 0) {
                    pp[cnt1] = k;
                    cnt1++;
                }
            }
            for (int k = 0; k < m; ++k) {
                if (k == i || k == j) continue;
                int s = (1 << k);
                for (int l = 0; l < cnt1; ++l) {
                    if (r[i][j][pp[l]] == true) r[i][j][pp[l] | s] = true;
                }
            }
            for (int k = 0; k < cnt1; ++k) {
                if (r[i][j][pp[k]] == true) rem[pp[k]] = true;
            }
        }
    }
    dp[0] = 1;
    int minx = (1 << 30);
    for (int i = 0; i < (1 << m); ++i) {
        if (dp[i] == 0) continue;
        int res = 0;
        for (int j = 0; j < m; ++j) {
            if ((i / (1 << j)) % 2 == 0) res += c[j][n];
        }
        minx = std::min(minx, res);
        for (int j = 0; j < m; ++j) {
            if ((i / (1 << j)) % 2 == 1) continue;
            if (rem[i + (1 << j)] == false) dp[i + (1 << j)] = 1;
        }
    }
    std::cout << minx << std::endl;
    return 0;
}
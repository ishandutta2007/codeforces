#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

int ile[507];
char s[507];
long long dp[507][507];
long long dwumian[507][507];
int N, mod;
bool byl[507][507];
std::vector<std::pair<int, int>> v;

void akt() {
    std::vector<std::pair<int, int>> st = std::move(v);
    for (auto const &it : st) {
        int i = it.first, w = it.second;
        if (byl[i][w]) continue;
        byl[i][w] = true;
        if (i != 0) {
            dp[i - 1][w] = (dp[i - 1][w] + dp[i][w] * i * w) % mod;
            v.push_back({i - 1, w});
        }
        if (i > 1 && w <= N - 2) {
            dp[i - 2][w + 2] = (dp[i - 2][w + 2] + dp[i][w] * dwumian[i][2]) % mod;
            v.push_back({i - 2, w + 2});
        }
        if (w >= 2) {
            dp[i][w - 2] = (dp[i][w - 2] + dp[i][w] * dwumian[w][2]) % mod;
            v.push_back({i, w - 2});
        }
    }
}

int main() {
    int M;
    scanf("%d%d%d", &N, &M, &mod);
    for (int i = 0; i < M; i++) {
        scanf("%s", s);
        for (int w = 0; w < N; w++) {
            if (s[w] == '1')
                ile[w]++;
        }
    }
    int wol = 0, poj = 0;
    for (int i = 0; i < N; i++)
        if (ile[i] == 0)
            wol++;
        else if (ile[i] == 1)
            poj++;
    v.push_back({wol, poj});
    dp[wol][poj] = 1;
    dwumian[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        dwumian[i][0] = 1;
        for (int w = 1; w <= i; w++)
            dwumian[i][w] = (dwumian[i - 1][w] + dwumian[i - 1][w - 1]) % mod;
    }
//    wypisz();
    for (int i = 0; i < N - M; i++) {
        akt();
//        wypisz();
    }
    printf("%I64d", dp[0][0]);
    return 0;
}
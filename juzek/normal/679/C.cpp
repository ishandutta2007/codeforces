#include <cstdio>
#include <algorithm>

int N;
char s[507][507];
int rX[] = {-1, 0, 1, 0};
int rY[] = {0, -1, 0, 1};
int spoj[507][507];
int rozm[1000007];
int akt[1000007];
int terRozm;
int wyn;

void dfs(int y, int x, int num) {
    spoj[y][x] = num;
    terRozm++;
    for (int i = 0; i < 4; i++) {
        int nx = x + rX[i], ny = y + rY[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
            if (s[ny][nx] == '.' && spoj[ny][nx] == 0)
                dfs(ny, nx, num);
        }
    }
}

void dolicz(int y1, int x1, int y2, int x2, bool kk = false) {
    for (int y = y1; y <= y2; y++) {
        if (y < 1 || y > N)
            continue;
        for (int x = x1; x <= x2; x++) {
            if (x < 1 || x > N)
                continue;
            if (s[y][x] == '.') {
                int sp = spoj[y][x];
                akt[sp]++;
                if (akt[sp] == 1)
                    wyn += rozm[sp];
            } else if (kk) {
                wyn++;
            }
        }
    }
}

void odejmij(int y1, int x1, int y2, int x2, bool kk = false) {
    for (int y = y1; y <= y2; y++) {
        if (y < 1 || y > N)
            continue;
        for (int x = x1; x <= x2; x++) {
            if (x < 1 || x > N)
                continue;
            if (s[y][x] == '.') {
                int sp = spoj[y][x];
                akt[sp]--;
                if (akt[sp] == 0)
                    wyn -= rozm[sp];
            } else if (kk) {
                wyn--;
            }
        }
    }
}

int main() {
    int K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%s", s[i] + 1);
    int ileSpoj = 0;
    for (int i = 1; i <= N; i++)
        for (int w = 1; w <= N; w++)
            if (s[i][w] == '.' && spoj[i][w] == 0) {
                terRozm = 0;
                dfs(i, w, ++ileSpoj);
                rozm[ileSpoj] = terRozm;
            }
    int maxi = 0;
    for (int i = 1; i <= N - K + 1; i++) {
        dolicz(i, 1, i + K - 1, K, true);
        dolicz(i - 1, 1, i - 1, K);
        dolicz(i + K, 1, i + K, K);
        dolicz(i, 0, i + K - 1, 0);
        dolicz(i, K + 1, i + K - 1, K + 1);
        maxi = std::max(wyn, maxi);
        for (int x = 2; x <= N + 2; x++) {
            odejmij(i, x - 2, i + K - 1, x - 2);
            odejmij(i, x - 1, i + K - 1, x - 1, true);
            dolicz(i, x - 1, i + K - 1, x - 1);

            odejmij(i, x + K - 1, i + K - 1, x + K - 1);
            dolicz(i, x + K - 1, i + K - 1, x + K - 1, true);
            dolicz(i, x + K, i + K - 1, x + K);

            odejmij(i - 1, x - 1, i - 1, x - 1);
            dolicz(i - 1, x + K - 1, i - 1, x + K - 1);

            odejmij(i + K, x - 1, i + K, x - 1);
            dolicz(i + K, x + K - 1, i + K, x + K - 1);

            maxi = std::max(wyn, maxi);
        }
    }
    printf("%d", maxi);
    return 0;
}
#include <cstdio>
#include <vector>
#include <queue>

int s[17];
char pl[1007][1007];
int odw[1007][1007];
int rX[] = {-1, 0, 1, 0};
int rY[] = {0, 1, 0, -1};
int wyn[17];

struct Info {
    int y, x, czas;
};

std::vector<Info> ogarnac[10];

int main() {
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 1; i <= P; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= N; i++)
        scanf("%s", pl[i] + 1);
    for (int i = 1; i <= N; i++)
        for (int w = 1; w <= M; w++)
            if (pl[i][w] >= '1' && pl[i][w] <= '9')
                ogarnac[pl[i][w] - '0'].push_back({i, w, 0});
    bool ok = true;
    int zeit = 1;
    while (ok) {
        ok = false;
        for (int gracz = 1; gracz <= P; gracz++) {
            char lit = (char) ('0' + gracz);
            zeit++;
            std::queue<Info> Q;
            for (auto it : ogarnac[gracz])
                Q.push(it);
            ogarnac[gracz].clear();
            while (!Q.empty()) {
                Info inf = Q.front();
                Q.pop();
                odw[inf.y][inf.x] = zeit;
                if (pl[inf.y][inf.x] != '.' && pl[inf.y][inf.x] != lit)
                    continue;
                if (inf.czas > s[gracz]) {
                    ogarnac[gracz].push_back(inf);
                    ogarnac[gracz].back().czas = 1;
                    continue;
                }
                ok = true;
                pl[inf.y][inf.x] = lit;
                for (int i = 0; i < 4; i++) {
                    int nY = inf.y + rY[i], nX = inf.x + rX[i];
                    if (nY >= 1 && nY <= N && nX >= 1 && nX <= M && pl[nY][nX] == '.' && odw[nY][nX] != zeit) {
                        Q.push({nY, nX, inf.czas + 1});
                        odw[nY][nX] = zeit;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
        for (int w = 1; w <= M; w++)
            if (pl[i][w] >= '1' && pl[i][w] <= '9')
                wyn[pl[i][w] - '0']++;
    for (int i = 1; i <= P; i++)
        printf("%d ", wyn[i]);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

char tab[1007][1007];

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
bool odw[1007][1007];
int kolor[1007][1007];
int N, M, T;
int moment[1007][1007];
int ziomy = 0;

void dfs(int y, int x, int k) {
    odw[y][x] = true;
    ziomy++;
    kolor[y][x] = k;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (tab[ny][nx] == tab[y][x] && !odw[ny][nx]) {
            dfs(ny, nx, k);
        }
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 1; i <= N; i++)
        scanf("%s", tab[i] + 1);
    int kolory = 0;
    queue<pair<int, int>> Q;
    memset(moment, 107, sizeof(moment));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= M; w++) {
            if (!odw[i][w]) {
                ziomy = 0;
                dfs(i, w, kolory++);
                if (ziomy != 1) {
                    Q.push({i, w});
                    moment[i][w] = 1;
                }
            } else {
                moment[i][w] = 1;
                Q.push({i, w});
            }
        }
    }
    while (!Q.empty()) {
        int y, x;
        y = Q.front().first, x = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny > 0 && ny <= N && nx > 0 && nx <= M) {
                if (moment[ny][nx] > moment[y][x] + 1) {
                    moment[ny][nx] = moment[y][x] + 1;
                    Q.push({ny, nx});
                }
            }
        }
    }
    while (T--) {
        int i, j;
        long long p;
        scanf("%d%d%lld", &i, &j, &p);
        if (moment[i][j] == moment[0][0]) {
            printf("%c\n", tab[i][j]);
        } else if (p < moment[i][j]) {
            printf("%c\n", tab[i][j]);
        } else {
            long long ileRazy = p - moment[i][j] + 1;
            if (ileRazy % 2 == 0)
                printf("%c\n", tab[i][j]);
            else
                printf("%c\n", tab[i][j] == '1' ? '0' : '1');
        }
    }
    return 0;
}
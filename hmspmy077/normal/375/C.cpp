#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>

const int N = 20;
const int INF = (int)1e9;

const int DELTA_X[4] = {-1, 0, 0, 1};
const int DELTA_Y[4] = {0, -1, 1, 0};

int n, m, t, value[N], id[N][N];
char type[8], map[N][N + 1];

int move[N][N][4], minimum[1 << 8][N][N];

struct State {
    int mask, x, y;

    State(int mask, int x, int y) : mask(mask), x(x), y(y) {
    }
};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%s", map[i]);
        for (int j = 0; j < m; ++ j) {
            if (isdigit(map[i][j])) {
                map[i][j] --;
            }
        }
    }
    t = 0;
    if (true) {
        int x;
        while (scanf("%d", &x) == 1) {
            value[t ++] = x;
        }
    }
    int o = 0;
    memset(id, -1, sizeof(id));
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (map[i][j] == 'S') {
                sx = i;
                sy = j;
                map[i][j] = '.';
            }
            if (isdigit(map[i][j]) || map[i][j] == 'B') {
                type[o] = map[i][j];
                id[i][j] = o ++;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            for (int k = 0; k < 4; ++ k) {
                int &mask = move[i][j][k];
                int x = i + DELTA_X[k];
                int y = j + DELTA_Y[k];
                if (0 <= x && x < n && 0 <= y && y < m && map[x][y] == '.') {
                    mask = 0;
                    if (y == j) {
                        for (int p = 0; p < n; ++ p) {
                            for (int q = 0; q < m; ++ q) {
                                if (id[p][q] != -1 && j > q && std::max(i, x) == p) {
                                    mask |= 1 << id[p][q];
                                }
                            }
                        }
                    }
                } else {
                    mask = -1;
                }
            }
        }
    }
    for (int mask = 0; mask < 1 << o; ++ mask) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                minimum[mask][i][j] = INF;
            }
        }
    }
    minimum[0][sx][sy] = 0;
    std::queue <State> queue;
    queue.push(State(0, sx, sy));
    while (!queue.empty()) {
        State now = queue.front();
        queue.pop();
        int mask = now.mask;
        int x = now.x;
        int y = now.y;
        for (int k = 0; k < 4; ++ k) {
            if (move[x][y][k] != -1) {
                int nmask = mask ^ move[x][y][k];
                int nx = x + DELTA_X[k];
                int ny = y + DELTA_Y[k];
                if (minimum[nmask][nx][ny] == INF) {
                    minimum[nmask][nx][ny] = minimum[mask][x][y] + 1;
                    queue.push(State(nmask, nx, ny));
                }
            }
        }
    }
    int result = 0;
    for (int mask = 0; mask < 1 << o; ++ mask) {
        if (minimum[mask][sx][sy] < INF) {
            int count = 0;
            bool valid = true;
            for (int i = 0; i < o; ++ i) {
                if (mask >> i & 1) {
                    if (type[i] == 'B') {
                        valid = false;
                    } else {
                        count += value[type[i] - '0'];
                    }
                }
            }
            if (valid) {
                result = std::max(result, count - minimum[mask][sx][sy]);
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
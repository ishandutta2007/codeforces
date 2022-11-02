#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const int N = 55;
const int M = 127;
const int X = N * N << 1;

bool valid[M];
bool good[N][N];

char s[N][N];

int n, m, k, sx, sy, ex, ey, op, cl;
int q[X];
int dis[N][N];

string out;

void bfs2() {
    string res = "";
    memset(good, false, sizeof(good));
    op = cl = 0, q[op++] = ex, q[op++] = ey, good[ex][ey] = true;
    char bes = 'S', prev = 'z';
    int d = dis[ex][ey];
    while (op != cl) {
        int x = q[cl++], y = q[cl++];
        if (dis[x][y] != d) {
            --d;
            if (bes != 'S') res += bes;
            bes = prev;
            prev = 'z';
        }
        if (x == sx && y == sy) break;
        if (s[x][y] != bes) continue;
        for (int i = 0; i < 4; ++i) {
            int xx = x - dx[i], yy = y - dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m &&
                dis[xx][yy] == dis[x][y] - 1 && !good[xx][yy]) {
                good[xx][yy] = true;
                q[op++] = xx, q[op++] = yy;
                if (s[xx][yy] < prev) prev = s[xx][yy];
            }
        }
    }
    if (out == "-1" || out.length() > res.length() ||
        out.length() == res.length() && out > res) {
        out = res;
    }
}
void bfs() {
    op = cl = 0, q[op++] = sx, q[op++] = sy;
    memset(dis, -1, sizeof(dis)), dis[sx][sy] = 0;
    while (op != cl) {
        int x = q[cl++], y = q[cl++];
        if (x == ex && y == ey) return bfs2();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                if (valid[s[xx][yy]] && dis[xx][yy] == -1) {
                    q[op++] = xx, q[op++] = yy;
                    dis[xx][yy] = dis[x][y] + 1;
                }
            }
        }
    }
}
void dfs(int i, char s) {
    if (i == k) return bfs();
    while (s <= 'z') valid[s] = true, dfs(i + 1, s + 1), valid[s] = false, ++s;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'T') {
                sx = i, sy = j;
            } else if (s[i][j] == 'S') {
                ex = i, ey = j;
            }
        }
    }
    valid['S'] = true;
    out = "-1";
    dfs(0, 'a');
    puts(out.c_str());
    return 0;
}
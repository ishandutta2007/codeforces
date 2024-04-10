#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w;
char g[1005][1005];
int d[3][1005][1005];
int proc[3][1005][1005];
int gd[3][3];

int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};

void go(int t) {
    deque<pair<int,int> > q;
    FO(i,0,3) gd[t][i] = 1e8;
    FO(y,0,h) FO(x,0,w) d[t][y][x] = 1e8;
    FO(y,0,h) FO(x,0,w) if (g[y][x] == t+'1') {
        d[t][y][x] = 0;
        q.push_back(make_pair(y,x));
    }
    while (!q.empty()) {
        auto p = q.front(); q.pop_front();
        int y, x;
        tie(y,x) = p;
        if (proc[t][y][x]) continue;
        proc[t][y][x] = true;

        //printf("t=%d, (%d,%d)\n", t, y, x);

        if ('1' <= g[y][x] && g[y][x] <= '3') {
            int ot = g[y][x]-'1';
            gd[t][ot] = min(gd[t][ot], d[t][y][x]);
        }
        FO(i,0,4) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] != '#') {
                int nd = d[t][y][x];
                if (g[ny][nx] == '.') nd++;
                if (nd < d[t][ny][nx]) {
                    d[t][ny][nx] = nd;
                    if (nd == d[t][y][x]) {
                        q.push_front(make_pair(ny,nx));
                    } else {
                        q.push_back(make_pair(ny,nx));
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &h, &w);
    FO(y,0,h) {
        scanf("%s", g[y]);
    }
    FO(i,0,3) go(i);
    int res = 1e8;
    FO(i,0,3) {
        int j = !i;
        int k = 2+1+0 - i - j;
        res = min(res, gd[j][i] + gd[i][k]);
    }
    FO(y,0,h) FO(x,0,w) if (g[y][x] == '.') {
        int s = 0;
        FO(i,0,3) s += d[i][y][x];
        s -= 2;
        res = min(res, s);
    }
    //printf("%d\n", gd[1][2]);
    if (res > 1e8-100) {
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }
}
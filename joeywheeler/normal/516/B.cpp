#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w;
int deg[2005][2005];
char g[2005][2005];
queue<pair<int,int> > q;

void rem(int y, int x) {
    FO(i,0,4) {
        int ny = y + (int[]){-1,0,1,0}[i];
        int nx = x + (int[]){0,-1,0,1}[i];
        if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] == '.') {
            deg[ny][nx]--;
            if (deg[ny][nx] == 1) q.push({ny,nx});
        }
    }
}

int main() {
    scanf("%d %d", &h, &w);
    FO(y,0,h) {
        scanf(" %s", g[y]);
    }
    FO(y,0,h) FO(x,0,w) if (g[y][x] == '.') {
        FO(i,0,4) {
            int ny = y + (int[]){-1,0,1,0}[i];
            int nx = x + (int[]){0,-1,0,1}[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] == '.') deg[y][x]++;
        }
    }
    FO(y,0,h) FO(x,0,w) if (deg[y][x] == 1) q.push({y,x});
    while (!q.empty()) {
        int y, x;
        tie(y,x) = q.front();
        q.pop();

        if (g[y][x] != '.') continue;
        bool found = false;
        FO(i,0,4) {
            int ny = y + (int[]){-1,0,1,0}[i];
            int nx = x + (int[]){0,-1,0,1}[i];
            //printf("(%d,%d) - (%d,%d)\n", y, x, ny, nx);
            if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] == '.') {
                if (i == 0) {
                    g[y][x] = 'v';
                    g[ny][nx] = '^';
                } else if (i==2) {
                    g[ny][nx] = 'v';
                    g[y][x] = '^';
                } else if (i == 1) {
                    g[ny][nx] = '<';
                    g[y][x] = '>';
                } else {
                    g[y][x] = '<';
                    g[ny][nx] = '>';
                }
                rem(y,x);
                rem(ny,nx);
                found = true;
                break;
            }
        }
        if (!found) goto fail;
    }

    FO(y,0,h) FO(x,0,w) if (g[y][x] == '.') goto fail;
    FO(y,0,h) printf("%s\n", g[y]);
    return 0;
fail:;
     printf("Not unique\n");
}
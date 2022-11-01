#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char g[505][505];
int nb[505][505];
int n, k;
int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};
vector<pair<int,int> > u[505*505];
int nu;
bool s[505][505];

int qb(int ys, int ye, int xs, int xe) {
    return nb[ye][xe] - nb[ye][xs] - nb[ys][xe] + nb[ys][xs];
}

void go(int y, int x, int ui) {
    u[ui].emplace_back(x,y);
    s[y][x] = true;
    FO(i,0,4) {
        int ny = y+dy[i], nx = x+dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < n && !s[ny][nx] && g[ny][nx] == '.') {
            go(ny, nx, ui);
        }
    }
}

int cv[505];
int ore;

void rst() {
    ore = 0;
}

void proc(int rs, int re, int vl) {
    rs = max(rs, ore);
    if (rs < re) {
        cv[rs] += vl;
        cv[re] -= vl;
        ore = re;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    FO(y,0,n) scanf(" %s", g[y]);
    FO(y,0,n) FO(x,0,n) {
        nb[y+1][x+1] = nb[y+1][x] + nb[y][x+1] - nb[y][x] +
            (g[y][x] == 'X');
    }

    FO(y,0,n) FO(x,0,n) if (g[y][x] == '.' && !s[y][x]) {
        go(y,x,nu);
        sort(u[nu].begin(), u[nu].end());
        nu++;
    }
    int bst = 0;
    FO(y,0,n-k+1) {
        FO(i,0,n) cv[i] = 0;
        FO(ui,0,nu) {
            rst();
            for (int i = 0; i < sz(u[ui]); ) {
                for (int j = i; j < sz(u[ui]) && u[ui][j].first == u[ui][i].first; j++) {
                    int x,yy; tie(x,yy) = u[ui][j];
                    int rs = -1, re = -1;
                    // x in [rs,re)
                    if (y <= yy && yy < y+k) {
                        rs = x-k;
                        re = x+2;
                        proc(rs, re, sz(u[ui]));
                    }
                }
                int j;
                for (j = i; j < sz(u[ui]) && u[ui][j].first == u[ui][i].first; j++) {
                    int x,yy; tie(x,yy) = u[ui][j];
                    int rs = -1, re = -1;
                    // x in [rs,re)
                    if (yy == y-1 || yy == y+k) {
                        rs = x-k+1;
                        re = x+1;
                        proc(rs, re, sz(u[ui]));
                    }
                }
                i = j;
            }
        }
        FO(i,1,n) cv[i] += cv[i-1];
        FO(i,0,n-k+1) {
            int ans = qb(y,y+k,i,i+k) + cv[i];
            //printf("%d,%d: %d\n", y, i, ans);
            //printf("%d\n", qb(y,y+k,i,i+k));
            bst = max(bst, ans);
        }
    }
    printf("%d\n", bst);
}
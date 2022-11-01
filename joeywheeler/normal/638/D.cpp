#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int dx[3] = {1,0,0};
int dy[3] = {0,1,0};
int dz[3] = {0,0,1};

char g[105][105][105];

bool cango(int x1, int y1, int z1, int x2, int y2, int z2) {
    if (x1 > x2 || y1 > y2 || z1 > z2) return false;
    if (g[x1][y1][z1] == '0') return false;
    if (x1 == x2 && y1 == y2 && z1 == z2) return true;
    FO(i,0,3) {
        if (cango(x1+dx[i],y1+dy[i],z1+dz[i],x2,y2,z2)) return true;
    }
    return false;
}

int a, b, c;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    FO(i,0,a) {
        FO(j,0,b) {
            scanf(" %s", g[i][j]);
        }
    }
    int res = 0;
    FO(i,0,a) FO(j,0,b) FO(k,0,c) if (g[i][j][k] == '1') {
        int f[3][3] = {};
        FO(s,0,3) {
            int pi = i-dx[s];
            int pj = j-dy[s];
            int pk = k-dz[s];
            FO(t,0,3) {
                int ni = i+dx[t];
                int nj = j+dy[t];
                int nk = k+dz[t];
                if (min({pi,pj,pk}) >= 0 && ni < a && nj < b && nk < c && g[pi][pj][pk] == '1' && g[ni][nj][nk] == '1') {
                    f[s][t] = cango(pi,pj,pk,ni,nj,nk) ? 1 : 0;
                } else f[s][t] = -1;
            }
        }
        g[i][j][k] = '0';
        int o[3][3];
        FO(s,0,3) {
            int pi = i-dx[s];
            int pj = j-dy[s];
            int pk = k-dz[s];
            FO(t,0,3) {
                int ni = i+dx[t];
                int nj = j+dy[t];
                int nk = k+dz[t];
                if (min({pi,pj,pk}) >= 0 && ni < a && nj < b && nk < c && g[pi][pj][pk] == '1' && g[ni][nj][nk] == '1') {
                    o[s][t] = cango(pi,pj,pk,ni,nj,nk) ? 1 : 0;
                } else o[s][t] = -1;
            }
        }
        g[i][j][k] = '1';

        bool cut = false;
        FO(s,0,3) FO(t,0,3) {
            if (f[s][t] != o[s][t]) cut = true;
        }
        res += cut;
    }
    printf("%d\n", res);
}
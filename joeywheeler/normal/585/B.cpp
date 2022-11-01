#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char g[705][3][105];
bool seen[705][3][105];
int n, k;

bool go(int t, int y, int x) {
    if (y < 0 || y >= 3) return false;
    if (x == n) return true;
    if (g[t][y][x] != '.') return false;
    if (seen[t][y][x]) return false;
    seen[t][y][x] = true;
    if (t % 6 == 0) return go(t+1, y, x+1);
    if (t % 6 == 1) return go(t+1, y-1, x) || go(t+1, y, x) || go(t+1, y+1, x);
    return go(t+1, y, x);
}

int main() {
    int T; scanf("%d", &T);
    FO(Z,0,T) {
        scanf("%d%d", &n, &k);
        FO(y,0,3) {
            FO(x,0,n) {
                scanf(" %c", &g[0][y][x]);
            }
        }
        FO(i,1,705) {
            FO(y,0,3) FO(x,0,n) {
                if (i%6 == 3 || i%6 == 4) {
                    g[i][y][x] = g[i-1][y][x+1];
                    if (x == n-1) g[i][y][x] = '.';
                } else g[i][y][x] = g[i-1][y][x];
                if (g[i][y][x] == 's') g[i][y][x] = '.';
            }
            //FO(y,0,3) printf("%s\n", g[i][y]);
            //printf("--\n");
        }
        memset(seen, 0, sizeof seen);
        FO(y,0,3) if (g[0][y][0] == 's') {
            g[0][y][0] = '.';
            if (go(0,y,0)) printf("YES\n");
            else printf("NO\n");
        }
    }
}
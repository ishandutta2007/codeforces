#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
char g[55][55];
bool hit[55][55];
char res[200][200];

int main() {
    scanf("%d", &n);
    FO(y,0,n) scanf(" %s", g[y]);
    for (int dx = -n+1; dx < n; dx++) {
        for (int dy = -n+1; dy < n; dy++) {
            bool allg = true;
            FO(y,0,n) if (allg) FO(x,0,n) if (g[y][x] == 'o') {
                int ny = y+dy, nx = x+dx;
                if (0 <= ny && ny < n && 0 <= nx && nx < n && g[ny][nx] == '.') {
                    allg = false;
                    break;
                }
            }
            if (allg) {
                res[n-1+dy][n-1+dx] = 'x';
                FO(y,0,n) FO(x,0,n) if (g[y][x] == 'o') {
                    int ny = y+dy, nx = x+dx;
                    if (0 <= ny && ny < n && 0 <= nx && nx < n) {
                        hit[ny][nx] = true;
                    }
                }
            }
        }
    }
    FO(y,0,n) FO(x,0,n) if (g[y][x] == 'x' && !hit[y][x]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    res[n-1][n-1] = 'o';
    FO(y,0,2*n-1) FO(x,0,2*n-1) if (res[y][x] == 0) res[y][x] = '.';
    FO(y,0,2*n-1) printf("%s\n", res[y]);
}
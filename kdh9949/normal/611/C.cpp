#include <cstdio>

char grid[511][511];

int w, h, q, row[501][501], col[501][501], onlyrow[501][501], onlycol[501][501], a, b, c, d;

int main(){
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; i++) scanf("%s", grid[i] + 1);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            row[i][j] = (grid[i][j] == '.' && grid[i + 1][j] == '.');
            col[i][j] = (grid[i][j] == '.' && grid[i][j + 1] == '.');
            onlyrow[i][j] = onlyrow[i - 1][j] + onlyrow[i][j - 1] - onlyrow[i - 1][j - 1] + row[i][j];
            onlycol[i][j] = onlycol[i - 1][j] + onlycol[i][j - 1] - onlycol[i - 1][j - 1] + col[i][j];
        }
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", onlyrow[c - 1][d] - onlyrow[a - 1][d] - onlyrow[c - 1][b - 1] + onlyrow[a - 1][b - 1] +
               onlycol[c][d - 1] - onlycol[a - 1][d - 1] - onlycol[c][b - 1] + onlycol[a - 1][b - 1]);
    }
}
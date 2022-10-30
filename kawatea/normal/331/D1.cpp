#include <cstdio>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    int n, b, q, i, j, k, l;
    int d[31][31];
    
    scanf("%d %d", &n, &b);
    
    for (i = 0; i <= b; i++) {
        for (j = 0; j <= b; j++) {
            d[i][j] = -1;
        }
    }
    
    for (i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        if (x1 == x2) {
            if (y1 < y2) {
                for (j = y1; j <= y2; j++) d[x1][j] = 0;
            } else {
                for (j = y2; j <= y1; j++) d[x1][j] = 2;
            }
        } else {
            if (x1 < x2) {
                for (j = x1; j <= x2; j++) d[j][y1] = 1;
            } else {
                for (j = x2; j <= x1; j++) d[j][y1] = 3;
            }
        }
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y, z, c = 0;
        long long t;
        int f[31][31][4];
        char s[2];
        
        scanf("%d %d %s %I64d", &x, &y, s, &t);
        
        if (s[0] == 'U') {
            z = 0;
        } else if (s[0] == 'R') {
            z = 1;
        } else if (s[0] == 'D') {
            z = 2;
        } else {
            z = 3;
        }
        
        for (j = 0; j <= b; j++) {
            for (k = 0; k <= b; k++) {
                for (l = 0; l < 4; l++) {
                    f[j][k][l] = -1;
                }
            }
        }
        
        f[x][y][z] = 0;
        
        while (t) {
            int nx, ny;
            
            if (d[x][y] != -1) z = d[x][y];
            
            nx = x + dx[z];
            ny = y + dy[z];
            
            if (nx < 0 || nx > b || ny < 0 || ny > b) break;
            
            c++;
            t--;
            
            if (f[nx][ny][z] != -1) t %= c - f[nx][ny][z];
            
            f[nx][ny][z] = c;
            
            x = nx;
            y = ny;
        }
        
        printf("%d %d\n", x, y);
    }
    
    return 0;
}
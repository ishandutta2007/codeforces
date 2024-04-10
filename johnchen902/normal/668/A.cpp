#include <cstdio>
#include <algorithm>
using namespace std;
int mat[100][100];
int orig[10000];
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i][j] = i * m + j;
    for(int qi = 0; qi < q; qi++) {
        int t;
        scanf("%d", &t);
        switch(t) {
        case 1: {
            int r;
            scanf("%d", &r);
            r--;
            std::rotate(mat[r], mat[r] + 1, mat[r] + m);
            break;
        }
        case 2: {
            int c;
            scanf("%d", &c);
            c--;
            int mat0c = mat[0][c];
            for(int i = 0; i + 1 < n; i++)
                mat[i][c] = mat[i + 1][c];
            mat[n - 1][c] = mat0c;
            break;
        }
        case 3: {
            int r, c, x;
            scanf("%d %d %d", &r, &c, &x);
            r--, c--;
            orig[mat[r][c]] = x;
            break;
        }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            printf("%d%c", orig[i * m + j], j == m - 1 ? '\n' : ' ');
}
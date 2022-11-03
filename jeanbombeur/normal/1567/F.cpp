#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  Right on time

const int MAX_ROWS = (500);

int Move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

char Grid[MAX_ROWS][MAX_ROWS];

int Deg[MAX_ROWS][MAX_ROWS];

int Ans[MAX_ROWS][MAX_ROWS];

int nbRows, nbColumns;

bool Valid(int row, int col) {
    return (row >= 0 && col >= 0 && row < nbRows && col < nbColumns);
}

void Dfs(int row, int col, int val) {
    // printf("%lld %lld %lld\n", row, col, val);
    if (Grid[row][col] == '.')
    {
        Ans[row][col] = val;
        for (int i = 0; i < 4; i ++)
        {
            int nvrow = row + Move[i][0], nvcol = col + Move[i][1];
            if (Valid(nvrow, nvcol) && Grid[nvrow][nvcol] == 'X' && Ans[nvrow][nvcol] == 0)
                Dfs(nvrow, nvcol, val ^ 5);
        }
    }
    else
    {
        Ans[row][col] = -1;
        int nvval = val;
        for (int i = 0; i < 4; i ++)
        {
            int nvrow = row + Move[i][0], nvcol = col + Move[i][1];
            if (Deg[row][col] == 2 && Grid[nvrow][nvcol] == '.' && Ans[nvrow][nvcol] == 0)
                Dfs(nvrow, nvcol, val);
            if (Deg[row][col] == 4 && Ans[nvrow][nvcol] == (nvval ^ 5))
                nvval ^= 5;
            nvval ^= 5;
        }
        if (Deg[row][col] == 4)
        {
            for (int i = 0; i < 4; i ++)
            {
                int nvrow = row + Move[i][0], nvcol = col + Move[i][1];
                if (Ans[nvrow][nvcol] == 0)
                    Dfs(nvrow, nvcol, nvval);
                nvval ^= 5;
            }
        }
    }
    return;
}

void Solve() {
    scanf("%lld %lld", &nbRows, &nbColumns);
    for (int i = 0; i < nbRows; i ++)
    {
        scanf("%s", Grid[i]);
    }
    for (int i = 0; i < nbRows; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            if (Grid[i][j] == 'X')
            {
                int deg = 0;
                for (int k = 0; k < 4; k ++)
                {
                    if (Grid[i + Move[k][0]][j + Move[k][1]] == '.')
                        deg ++;
                }
                if (deg & 1)
                {
                    printf("NO\n");
                    return;
                }
                Deg[i][j] = deg;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < nbRows; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            if (Grid[i][j] == '.' && Ans[i][j] == 0)
                Dfs(i, j, 1);
        }
    }
    for (int i = 0; i < nbRows; i ++)
    {
        for (int j = 0; j < nbColumns; j ++)
        {
            if (Grid[i][j] == 'X')
            {
                Ans[i][j] = 0;
                for (int k = 0; k < 4; k ++)
                {
                    if (Grid[i + Move[k][0]][j + Move[k][1]] == '.')
                        Ans[i][j] += Ans[i + Move[k][0]][j + Move[k][1]];
                }
            }
            printf("%lld ", Ans[i][j]);
        }
        printf("\n");
    }
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}
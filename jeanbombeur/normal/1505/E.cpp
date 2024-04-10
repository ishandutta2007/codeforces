#include <iostream>
#include <cstdio>
using namespace std;

//  <|_|>

//  xiao xiao

const int MAX_ROWS = 5;

char Grid[MAX_ROWS][MAX_ROWS];

int nbLines, nbColumns;

void Solve() {
    scanf("%d %d", &nbLines, &nbColumns);
    for (int i = 0; i < nbLines; i ++)
    {
        scanf("%s", Grid[i]);
    }
    int lig = 0, col = 0;
    int ans = Grid[lig][col] == '*';
    while (lig < nbLines - 1 || col < nbColumns - 1)
    {
        bool t = false;
        for (int d = 1; d < nbLines + nbColumns; d ++)
        {
            for (int l = 0; l <= d; l ++)
            {
                if (!t && lig + l < nbLines && col + d - l < nbColumns && Grid[lig + l][col + d - l] == '*')
                    lig += l, col += d - l, ans ++, t = true;
            }
        }
        if (!t)
            lig = nbLines - 1, col = nbColumns - 1;
    }
    printf("%d\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
        Solve();
    return 0;
}
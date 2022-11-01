#include <cstdio>
#include <memory.h>
using namespace std;

bool achievable[100][8][8];
char field[8][9];


int main(void) {
    for (int i = 0; i < 8; i++)
        scanf("%s", field[i]);
    int mx, my, ax, ay;
    mx = my = ax = ay = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] == 'M')
                mx = i, my = j;
            if (field[i][j] == 'A')
                ax = i, ay = j;
        }
    }
    memset(achievable, 0, sizeof(achievable));
    achievable[0][mx][my] = true;
    const int DXY[][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {0, 0}};
    for (int t = 0; t < 99; t++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (!achievable[t][i][j] || field[i][j] == 'S')
                    continue;
                for (int k = 0; k < 9; k++) {
                    int ni = i + DXY[k][0];
                    int nj = j + DXY[k][1];
                    if (ni < 0 || nj < 0 || ni >= 8 || nj >= 8) continue;
                    if (field[ni][nj] == 'S')
                        continue;
                    achievable[t+1][ni][nj] = true;
                    if (ni == ax && nj == ay) {
                        printf("WIN\n");
                        return 0;
                    }
                }
            }
        }
        for (int i = 7; i > 0; i--) {
            for (int j = 0; j < 8; j++) {
                field[i][j] = field[i-1][j];
            }
        }
        for (int j = 0; j < 8; j++)
            field[0][j] = '.';
    }
    printf("LOSE\n");
    return 0;
}
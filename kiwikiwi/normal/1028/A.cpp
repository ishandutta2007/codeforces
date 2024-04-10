#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
char ch[200][200];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch[i] + 1);
    }
    int lx = n + 1, rx = 0, ly = m + 1, ry = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ch[i][j] == 'B') {
                lx = min(lx, i);
                rx = max(rx, i);
                ly = min(ly, j);
                ry = max(ry, j);
            }
        }
    }
    printf("%d %d\n", (lx + rx) / 2, (ly + ry) / 2);
}
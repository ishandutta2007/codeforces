#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5;
char M[MAXN][MAXN + 1];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", M[i]);
        int minx = n, miny = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (M[i][j] == 'R') {
                    minx = min(minx, i);
                    miny = min(miny, j);
                }
        puts(minx < n && miny < m && M[minx][miny] == 'R' ? "YES" : "NO");
    }
    return 0;
}
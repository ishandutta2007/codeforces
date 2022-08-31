#include <bits/stdc++.h>
using namespace std;
const int N = 111;

char grid[N][N];
int r, c;
bool valid() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '*') {
                int ct = grid[i][j] == '.' ? 0 : grid[i][j] - '0';
                assert(0 <= ct && ct <= 8);
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (0 <= ni && ni < r) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int nj = j + dj;
                            if (0 <= nj && nj < c && grid[ni][nj] == '*') {
                                if (!ct--) return false;
                            }
                        }
                    }
                }
                if (ct) return false;
            }
        }
    }
    return true;
}
int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
    }
    puts(valid() ? "YES" : "NO");
}
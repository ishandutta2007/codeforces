#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {1, 1, -1, -1, 1, -1, -1, 1};

int n;
char str[N][N];

int main() {
    scanf("%d", &n);
    int l1, r1, l2, r2;
    l1 = INF, r1 = INF, l2 = -INF, r2 = -INF;
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i][j] != '0') {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= n | y < 0 || y >= n) continue;
                    if (str[x][y] != '0') cnt++;
                }
                if (str[i][j] - '0' != cnt) {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}
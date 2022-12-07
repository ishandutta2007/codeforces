#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 105;
const int v[4] = {0, 3, 1, 2};
const int v2[4] = {1, 0, 2, 3};

int ans[N][4];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int r = n;

    int cnt = 0;
    for (int j = 0; j < r; j++) {
        if (cnt == m) break;
        for (int i = 0; i < 2; i++) {
            int vv = v[i];
            ans[j][vv] = ++cnt;
            if (cnt == m) break;
        }
    }
    for (int j = 0; j < r; j++) {
        if (cnt == m) break;
        for (int i = 2; i < 4; i++) {
            int vv = v[i];
            ans[j][vv] = ++cnt;
            if (cnt == m) break;
        }
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < 4; j++) {
            if (ans[i][v2[j]] == 0) continue;
            printf("%d ", ans[i][v2[j]]);
        }
    printf("\n");
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 605;
int q, h, w;
int a[N][N];

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &h, &w);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                scanf("%d", &a[i][j]);
        int ans = 0;
        for (int i = 0; i < w; i++)
            ans += abs(a[(h - 1) / 2][i] - a[(h - 1) / 2 + 1][i]);
        printf("%s\n", ans > 10000 ? "YES" : "NO");
    }
    return 0;
}
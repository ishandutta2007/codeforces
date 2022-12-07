#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 15;
int n, t;
int a[N][N];

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= t; i++) {
        a[1][1] += 2048;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (a[i][j] > 2048) {
                    int yu = a[i][j] - 2048;
                    a[i][j] -= yu;
                    a[i + 1][j] += yu / 2;
                    a[i + 1][j + 1] += yu / 2;
                }
            }
        }
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (a[i][j] != 2048) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) break;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (a[i][j] == 2048) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
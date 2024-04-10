#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 5000;

int n, m, length[N], order[2][N];
char map[N][N + 1];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%s", map[i]);
    }
    memset(length, 0, sizeof(length));
    for (int i = 0; i < n; ++ i) {
        order[0][i] = i;
    }
    int result = 0;
    for (int j = 0; j < m; ++ j) {
        int head = 0;
        int tail = n;
        for (int k = n - 1; k >= 0; -- k) {
            int i = order[j & 1][k];
            if (map[i][j] == '1') {
                length[i] ++;
                order[j + 1 & 1][-- tail] = i;
            } else {
                length[i] = 0;
                order[j + 1 & 1][head ++] = i;
            }
        }
        for (int k = n - 1; k >= 0; -- k) {
            result = std::max(result, length[order[j + 1 & 1][k]] * (n - k));
        }
    }
    printf("%d\n", result);
    return 0;
}
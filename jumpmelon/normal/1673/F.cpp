#include <bits/stdc++.h>

using namespace std;

int G[32];

int key(int x, int y) {
    int t = 0;
    x = G[x];
    y = G[y];
    for (int i = 0; i < 5; i++)
        t |= ((x >> i & 1) << (2 * i)) | ((y >> i & 1) << (2 * i + 1));
    return t;
}

int main() {
    G[0] = 0;
    for (int k = 2; k <= 32; k <<= 1) {
        for (int i = 0; i < k / 2; i++)
            G[k - i - 1] = (k / 2) | G[i];
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++)
            printf("%d ", key(i, j - 1) ^ key(i, j));
        putchar('\n');
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", key(i - 1, j) ^ key(i, j));
        putchar('\n');
    }
    fflush(stdout);
    int x = key(0, 0);
    while (k--) {
        int v;
        scanf("%d", &v);
        x ^= v;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (key(i, j) == x) {
                    printf("%d %d\n", i + 1, j + 1);
                }
        fflush(stdout);
    }
    return 0;
}
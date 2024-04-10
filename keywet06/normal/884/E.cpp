#include <bits/stdc++.h>

const int N = 20005;
const int M = N << 1;

char x[N];

int y[M], z[M], Next[M];

int find(int k) {
    if (k == Next[k]) {
        return k;
    } else {
        return Next[k] = find(Next[k]);
    }
}

void process(int k) {
    int t;
    if ('0' <= x[k] && x[k] <= '9') {
        t = x[k] - '0';
    } else {
        t = x[k] - 'A' + 10;
    }
    z[4 * k] = (t % 2), t /= 2;
    z[4 * k - 1] = (t % 2), t /= 2;
    z[4 * k - 2] = (t % 2), t /= 2;
    z[4 * k - 3] = (t % 2);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    for (int i = 1; i <= a; ++i) {
        scanf("%s", x + 1);
        for (int j = 1; j <= b / 4; ++j) process(j);
        for (int j = 1; j <= b; ++j) Next[(i % 2) * b + j] = 0;
        for (int j = 1; j <= b; ++j) {
            if (z[j] == 1) {
                Next[(i % 2) * b + j] = (i % 2) * b + j;
                if (z[j - 1] == 1) {
                    int s = find((i % 2) * b + j - 1);
                    int t = find((i % 2) * b + j);
                    Next[s] = t;
                }
                if (y[j] == 1) {
                    int s = find((1 - (i % 2)) * b + j);
                    int t = find((i % 2) * b + j);
                    Next[s] = t;
                }
            }
        }
        for (int j = 1; j <= b; ++j) {
            if (y[j] == 1) {
                int s = (1 - (i % 2)) * b + j;
                if (s == find(s)) ++ans;
            }
        }
        for (int j = 1; j <= b; ++j) y[j] = z[j];
    }
    for (int j = 1; j <= b; ++j) {
        if (y[j] == 1) {
            int s = (a % 2) * b + j;
            if (s == find(s)) ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
#include <cstdio>

bool p[1000007];

int main() {
    p[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (!p[i]) {
            for (int w = i + i; w <= 1000000; w += i) {
                p[w] = true;
            }
        }
    }
    int N;
    scanf("%d", &N);
    for (int i = 1;; i++) {
        if (p[i * N + 1]) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
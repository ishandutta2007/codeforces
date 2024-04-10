#include <cstdio>

int ile[100007];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a;
    int zost = N;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &a);
        ile[a]++;
        if (ile[a] == 1)
            zost--;
        if (zost == 0) {
            printf("1");
            zost = N;
            for (int w = 1; w <= N; w++) {
                ile[w]--;
                if (ile[w] != 0)
                    zost--;
            }
        } else {
            printf("0");
        }
    }
    return 0;
}
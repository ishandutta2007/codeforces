#include <cstdio>

int N, M, K;

int main() {
    scanf ("%d %d %d", &N, &M, &K);
    if (K == 1) {
        if (N == M + 1) {
            printf ("3\n");
            printf ("%d %d %d", 1, N, N + M);
            return 0;
        } 
        if (N == 2) {
            printf ("4\n");
            printf ("1 2 3 4\n");
            return 0;
        }
    }
    if (N != M) {
        printf ("%d\n", 2*K);
        for (int i = 0; i < K; i++) {
            printf ("1 ");
        }
        printf ("%d ", N);
        for (int i = 0; i < K - 1; i++) {
            printf ("%d ", N + 1);
        }
    } else {
        printf ("%d\n", 2*K + 1);
        for (int i = 0; i < K; i++) {
            printf ("1 ");
        }
        printf ("%d ", N);
        for (int i = 0; i < K - 1; i++) {
            printf ("%d ", N + 1);
        }
        if (K == 1) {
            printf ("%d ", N + M - 1);
        } else {
            printf ("%d ", N + M);
        }
    }
    return 0;
}
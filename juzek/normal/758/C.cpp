#include <cstdio>
#include <algorithm>
#include <iostream>

char pos[6];
int wyn['Z'];

int main() {
    int N, M, X, Y;
    long long K;
    scanf("%d%d%I64d%d%d", &N, &M, &K, &Y, &X);
    long long j = N != 1 ? (2 * N * M) - 2 * M : M;
    long long ile = K / j;
    long long r = K % j;
    long long q = r;
    long long ileM = 0;
    if (q != 0) {
        for (int i = 1; i <= N; i++) {
            for (int w = 1; w <= M; w++) {
                if (i == Y && w == X) {
                    ileM++;
                }
                q--;
                if (q == 0)
                    i = w = 1337;
            }
        }
        if (q != 0) {
            for (int i = N - 1; i >= 1; i--) {
                for (int w = 1; w <= M; w++) {
                    if (i == Y && w == X)
                        ileM++;
                    q--;
                    if (q == 0) {
                        i = 0;
                        break;
                    }
                }
            }
        }
    }
    if (N == 1 || N == 2) {
        printf("%I64d %I64d %I64d", ile + (r != 0), ile, ile + ileM);
    } else {
        printf("%I64d %I64d %I64d", ile * 2 + int(r > M || (r > 0 && ile == 0)) + int(r > N * M), ile + (r >= N * M), ((Y == 1 || Y == N) ? ile + ileM : ile * 2 + ileM));
    }
    return 0;
}
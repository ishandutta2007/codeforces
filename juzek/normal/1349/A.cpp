#include <bits/stdc++.h>

int jest[200007];
bool prime[200007];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        jest[a]++;
    }
    long long odp = 1;
    for (int i = 2; i <= 200000; i++) {
        if (!prime[i]) {
            int mini1 = 1337133713, mini2 = 1337133713;
            int bylo = 0;
            for (int w = i; w <= 200000; w += i) {
                prime[w] = true;
                if (jest[w]) {
                    bylo += jest[w];
                    int razy = 0;
                    int q = w;
                    while (q % i == 0 && razy <= mini2) {
                        q /= i;
                        razy++;
                    }
                    if (jest[w] == 1) {
                        if (mini1 >= razy) {
                            mini2 = mini1;
                            mini1 = razy;
                        } else if (mini2 >= razy) {
                            mini2 = razy;
                        }
                    } else {
                        if (mini1 >= razy) {
                            mini2 = mini1;
                            mini1 = razy;
                        } else if (mini2 >= razy) {
                            mini2 = razy;
                        }
                        if (mini1 >= razy) {
                            mini2 = mini1;
                            mini1 = razy;
                        } else if (mini2 >= razy) {
                            mini2 = razy;
                        }
                    }
                }
            }
            if (bylo == N - 1) {
                mini2 = mini1;
                mini1 = 0;
            } else if (bylo < N - 1) {
                continue;
            }
            for (int z = 1; z <= mini2; z++)
                odp *= i;
        }
    }
    printf("%lld", odp);
    return 0;
}
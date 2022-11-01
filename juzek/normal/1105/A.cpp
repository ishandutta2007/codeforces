#include <cstdio>
#include <algorithm>

int tab[1000007];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
    }
    int mini = 1337133713, tt = -1;
    for (int i = 1; i <= 100; i++) {
        int sum = 0;
        for (int w = 1; w <= N; w++)
            sum += std::min(std::min(std::abs(i - 1 - tab[w]), std::abs(i - tab[w])), std::abs(i + 1 - tab[w]));
        if (mini > sum) {
            mini = sum;
            tt = i;
        }
    }
    printf("%d %d\n",tt, mini);
    return 0;
}
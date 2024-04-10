#include <cstdio>
#include <algorithm>

int tab[107];

bool sr(int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += tab[i];
    }
    double a = sum / (double) N;
    if (a >= 4.5)
        return true;
    return false;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
    }
    std::sort(tab, tab + N);
    if (sr(N)) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < N; i++) {
        tab[i] = 5;
        if (sr(N)) {
            printf("%d", i + 1);
            return 0;
        }
    }
    return 0;
}
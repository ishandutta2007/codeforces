#include <cstdio>
#include <algorithm>
#include <climits>

long long tab[5007];
long long suf[5007];
int sufPos[5007];

long long sum(int a, int b) {
    return tab[b - 1] - tab[a - 1];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &tab[i]);
        tab[i] += tab[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        long long maxi = LLONG_MIN;
        int maxiPos = -1;
        for (int w = i; w <= N + 1; w++) {
            if (maxi < sum(i, w) - sum(w, N + 1)) {
                maxi = sum(i, w) - sum(w, N + 1);
                maxiPos = w;
            }
        }
        suf[i] = maxi;
        sufPos[i] = maxiPos;
    }
    long long maxi = LLONG_MIN;
    int a = -1, b = -1, c = -1;
    for (int i = 1; i <= N; i++)
        for (int w = i; w <= N; w++) {
            if (maxi < sum(1, i) - sum(i, w) + suf[w]) {
                maxi = sum(1, i) - sum(i, w) + suf[w];
                a = i, b = w, c = sufPos[w];
            }
        }
    printf("%d %d %d", a - 1, b - 1, c - 1);
    return 0;
}
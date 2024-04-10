#include <cstdio>
#include <algorithm>

int tab[1000007];
int ile[1000007];
int maxi = 0;

void przelicz(int x, int y, int W, int H) {
    for (int i = 1; i <= W; i++) {
        for (int w = 1; w <= H; w++) {
            ile[std::abs(i - x) + std::abs(w - y)]++;
        }
    }
    bool k = true;
    for (int i = 0; i <= maxi; i++) {
        if (ile[i] != tab[i])
            k = false;
        ile[i] = 0;
    }
    if (k) {
        printf("%d %d\n%d %d", W, H, x, y);
        exit(0);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int brak = 0;
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        tab[a]++;
        maxi = std::max(maxi, a);
    }
    for (int i = 1; i <= N; i++) {
        if (tab[i] != i * 4) {
            brak = i;
            break;
        }
    }
    if (brak == 0) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        if (N % i != 0)
            continue;
        int W = i, H = N / i;
        int y = brak;
        int q = H - y;
        int x = maxi - std::max(y - 1, q) + 1;
        if (x <= 0)
            continue;
        przelicz(x, y, W, H);
    }
    printf("-1");
    return 0;
}
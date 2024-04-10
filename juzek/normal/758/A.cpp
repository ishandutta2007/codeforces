#include <cstdio>
#include <algorithm>

int tab[107];

int main() {
    int N;
    scanf("%d", &N);
    int maxi = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
        maxi = std::max(maxi, tab[i]);
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        ret += maxi - tab[i];
    }
    printf("%d", ret);
    return 0;
}
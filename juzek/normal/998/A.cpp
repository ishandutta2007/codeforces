#include <cstdio>

int tab[17];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &tab[i]);
    if (N == 1)
        printf("-1");
    else if (N == 2) {
        if (tab[0] == tab[1])
            printf("-1");
        else
            printf("1\n1");
    } else {
        int mini = 1337133713;
        int num = -1;
        for (int i = 0; i < N; i++) {
            if (tab[i] < mini) {
                mini = tab[i];
                num = i;
            }
        }
        printf("1\n%d", num + 1);
    }
    return 0;
}
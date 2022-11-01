#include <cstdio>
#include <cstring>

char s[10007];

int main() {
    scanf("%s", s + 1);
    int N = (int) strlen(s + 1);
    bool spoko = false;
    for (int i = 2; i <= N / 2; i++) {
        if (s[i] != s[i - 1]) {
            spoko = true;
            break;
        }
    }
    if (!spoko) {
        printf("Impossible");
        return 0;
    }
    for (int i = 1; i <= N; i++)
        s[i + N] = s[i];
    for (int i = 2; i <= N; i++) {
        bool kk = true;
        bool rozne = false;
        for (int w = 0; w < N; w++) {
            if (s[i + w] != s[i + N - w - 1]) {
                kk = false;
                break;
            }
            if (s[i + w] != s[w + 1])
                rozne = true;
        }
        if (kk && rozne) {
            printf("1");
            return 0;
        }
    }
    printf("2");
    return 0;
}
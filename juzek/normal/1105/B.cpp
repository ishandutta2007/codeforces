#include <cstdio>
#include <algorithm>

char s[1000007];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    scanf("%s", s + 1);
    int maxPoz = 0;
    for (char ter = 'a'; ter <= 'z'; ter++) {
        int ile = 0;
        int wybr = 0;
        for (int i = 1; i <= N; i++) {
            if (s[i] == ter)
                ile++;
            else
                ile = 0;
            if (ile == K) {
                wybr++;
                ile = 0;
            }
        }
        maxPoz = std::max(maxPoz, wybr);
    }
    printf("%d", maxPoz);
    return 0;
}
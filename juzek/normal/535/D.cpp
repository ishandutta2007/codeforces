#include <cstdio>
#include <cstring>

bool ok[1000007];
char s[1000007];
int pre[1000007];

int main() {
    int R, M;
    scanf("%d%d", &R, &M);
    scanf("%s", s);
    int N = (int) strlen(s);
    for (int i = 1; i < N; i++) {
        int a = pre[i - 1];
        while (a > 0 && s[a] != s[i])
            a = pre[a - 1];
        pre[i] = a + (s[a] == s[i]);
    }
    int ter = N;
    while (ter != 0) {
        ok[ter] = true;
        ter = pre[ter - 1];
    }
    int las = -N + 1;
    int a;
    int ile = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &a);
        if (a - las >= N) {
            ile += a - las - N;
        } else {
            if (!ok[N - (a - las)]) {
                printf("0");
                return 0;
            }
        }
        las = a;
    }
    ile += R - las - N + 1;
    long long wyn = 1;
    for (int i = 0; i < ile; i++) {
        wyn *= 26;
        wyn %= 1000000007;
    }
    printf("%lld", wyn);
    return 0;
}
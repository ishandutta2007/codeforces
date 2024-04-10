#include <cstdio>
#include <cstdlib>

char s[1000007];
char wyn[1000007];
int mojmax[1000007], mojmin[1000007];

int min = 0, max = 0;
int N, K;

void maksymalizuj(int i, bool rowne) {
    wyn[i] = s[i];
    if (s[i] == 'W') {
        min++, max++;
        if (max > K || (rowne && max == K))
            max--;
    } else if (s[i] == 'L') {
        min--, max--;
        if (min < -K || (rowne && min == -K))
            min++;
    } else if (s[i] == 'D') {

    } else {
        min--, max++;
        if (max > K || (rowne && max == K))
            max--;
        if (min < -K || (rowne && min == -K))
            min++;
    }
    mojmax[i] = max, mojmin[i] = min;
    if (max < min) {
        printf("NO");
        exit(0);
    }
}

int przywroc(int i, int war) {
    if (s[i] == 'W')
        return war - 1;
    else if (s[i] == 'L')
        return war + 1;
    else if (s[i] == 'D')
        return war;
    if (mojmin[i - 1] <= war - 1 && war - 1 <= mojmax[i - 1]) {
        s[i] = 'W';
        return war - 1;
    }
    if (mojmin[i - 1] <= war + 1 && war + 1 <= mojmax[i - 1]) {
        s[i] = 'L';
        return war + 1;
    }
    s[i] = 'D';
    return war;
}

int main() {
    scanf("%d%d", &N, &K);
    scanf("%s", s + 1);
    for (int i = 1; i <= N - 1; i++)
        maksymalizuj(i, true);
    maksymalizuj(N, false);
    if (max == K) {
        int war = K;
        for (int i = N; i >= 1; i--)
            war = przywroc(i, war);
        printf("%s", s + 1);
    } else if (min == -K) {
        int war = -K;
        for (int i = N; i >= 1; i--)
            war = przywroc(i, war);
        printf("%s", s + 1);
    } else {
        printf("NO");
        return 0;
    }
    return 0;
}
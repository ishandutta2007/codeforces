#include <cstdio>
#include <algorithm>
#include <climits>

char s[1000007];

int main() {
    int N;
    long long x, y;
    scanf("%d%I64d%I64d", &N, &x, &y);
    scanf("%s", s);
    int ile = 0;
    if (s[0] == '0')
        ile = 1;
    for (int i = 1; i < N; i++) {
        if (s[i] != s[i - 1] && s[i] == '0')
            ile++;
    }
    if (ile == 0) {
        printf("0");
        return 0;
    }
    long long wyn = LLONG_MAX;
    for (int i = 0; i < ile; i++) {
        wyn = std::min(wyn, x * i + y * (ile - i));
    }
    printf("%I64d", wyn);
    return 0;
}
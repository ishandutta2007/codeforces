#include <cstdio>
#include <cstring>
#include <algorithm>

char s[300007];

int main() {
    scanf("%s", s + 1);
    int N = (int) strlen(s + 1);
    long long wyn = 0;
    for (int i = 1; i <= N; i++) {
        int mini = i + 8;
        int dk = std::min(i + 8, N + 1);
        for (int w = i + 2; w < dk; w++) {
            for (int k = 1; w - 2 * k >= i; k++)
                if (s[w] == s[w - k] && s[w - k] == s[w - 2 * k]) {
                    mini = w;
                    break;
                }
            if (mini == w)
                break;
        }
        if (mini > N)
            break;
        wyn += N - mini + 1;
    }
    printf("%lld", wyn);
    return 0;
}
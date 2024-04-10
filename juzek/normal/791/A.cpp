#include <cstdio>

int main() {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    int count = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        count++;
    }
    printf("%d", count);
    return 0;
}
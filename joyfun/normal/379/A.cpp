#include <stdio.h>
#include <string.h>

int a, b;
int sum = 0, yu = 0;
int main() {
    scanf("%d%d", &a, &b);
    while (a) {
        sum += a;
        yu += a;
        a = yu / b;
        yu %= b;
    }
    printf("%d\n", sum);
    return 0;
}
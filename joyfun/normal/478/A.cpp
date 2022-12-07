#include <cstdio>
#include <cstring>

int c, sum = 0;
int main() {
    for (int i = 0; i < 5; i++) {
        scanf("%d", &c);
        sum += c;
    }
    if (sum == 0 || sum % 5) printf("-1\n");
    else printf("%d\n", sum / 5);
    return 0;
}
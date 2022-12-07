#include <cstdio>
#include <cstring>

int n, h, a;

int main() {
    int cnt = 0;
    scanf("%d%d", &n, &h);
    while (n--) {
        scanf("%d", &a);
        if (a > h) cnt+=2;
        else cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
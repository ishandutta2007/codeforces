#include <cstdio>
#include <algorithm>

int main() {
    int a, b, c, n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    int s = n - a - b + c;
    if (c > std::min(a, b))
        printf("-1");
    else if (a > n || b > n)
        printf("-1");
    else if (s <= 0)
        printf("-1");
    else
        printf("%d\n", s);
    return 0;
}
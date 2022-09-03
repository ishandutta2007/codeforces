#include <cstdio>

char a[101], b[101];

int main() {
    int i, n;
    scanf("%s%s", a, b);
    for (n = 0; a[n]; n++);
    for (i = 0; i < n; i++) if (a[i] != b[n - i - 1]) {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}
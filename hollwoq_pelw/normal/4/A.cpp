#include<stdio.h>

int main() {
    int n; scanf("%d", &n);
    if (n > 2 && n % 2 == 0)
        puts("YES");
    else
        puts("NO");
}
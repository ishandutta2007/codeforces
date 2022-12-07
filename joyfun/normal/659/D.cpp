#include <cstdio>

int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%*d%*d");
    printf("%d\n", (n - 4) / 2);
    return 0; 
}
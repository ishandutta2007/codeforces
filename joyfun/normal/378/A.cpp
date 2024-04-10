#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a, b;

int main() {
    int ans1 = 0, ans2 = 0, ans3 = 0;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= 6; i ++) {
        if (abs(a - i) < abs(b - i)) ans1++;
        if (abs(a - i) == abs(b - i)) ans2++;
        if (abs(a - i) > abs(b - i)) ans3++;
    }
    printf("%d %d %d\n", ans1, ans2, ans3);
    return 0;
}
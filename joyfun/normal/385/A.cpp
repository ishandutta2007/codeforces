#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, c, num[105], i;

int main() {
    int ans = 0;
    scanf("%d%d", &n, &c);
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < n - 1; i++)
        if (num[i] - num[i + 1] > ans)
            ans = num[i] - num[i + 1];
    if (ans - c < 0) printf("0\n");
    else printf("%d\n", ans - c);
    return 0;
}
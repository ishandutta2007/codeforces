#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, k, num, i;

int main() {
    scanf("%d%d", &n, &k);
    int ans = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (5 - num >= k) ans++;
    }
    printf("%d\n", ans / 3);
    return 0;
}
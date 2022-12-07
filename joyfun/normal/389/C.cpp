#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

int n, x[105], i, j, ans = 0, blo[105];

int find(int xx) {
    for (int i = 0; i < ans; i++)
        if (xx >= blo[i])
            return i;
    return ans++;
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    for (i = 0; i < n; i++) {
        blo[find(x[i])]++;
    }
    printf("%d\n", ans);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 105;
int n, visx[N], visy[N];

int main() {
    scanf("%d", &n);
    int x, y, xn = 0, yn = 0;
    while (n--) {
        scanf("%d%d", &x, &y);
        if (!visx[x]) {
            xn++;
            visx[x] = 1;
        }
        if (!visy[y]) {
            yn++;
            visy[y] = 1;
        }
    }
    int ans = (xn < yn ? xn : yn);
    printf("%d\n", ans);
    return 0;
}
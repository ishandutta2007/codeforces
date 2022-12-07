#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int x1, y1, x2, y2;
    int ans = 0;
    while (n--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ans += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    printf("%d\n", ans);
    return 0;
}
#include <cstdio>
using namespace std;
int main() {
    int n, d, h;
    scanf("%d %d %d", &n, &d, &h);
    if((d == 1 && n >= 3) || (h * 2 < d)) {
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= h; i++)
        printf("%d %d\n", i, i + 1);
    for(int i = h + 1; i <= d; i++)
        printf("%d %d\n", i == h + 1 ? 1 : i, i + 1);
    int center = 1 + h - d / 2;
    for(int i = d + 2; i <= n; i++)
        printf("%d %d\n", center, i);
}
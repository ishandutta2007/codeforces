#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, d, h;

int main() {
    scanf("%d%d%d", &n, &d, &h);
    if (d == 1 && n != 2) printf("-1\n");
    else if (h * 2 < d) printf("-1\n");
    else {
        int pre = 1, cnt = 2;
        for (int i = 0; i < d - h; i++) {
            printf("%d %d\n", pre, cnt);
            pre = cnt++;
        }
        pre = 1;
        for (int i = 0; i < h - 1; i++) {
            printf("%d %d\n", pre, cnt);
            pre = cnt++;
        }
        while (cnt <= n) printf("%d %d\n", pre, cnt++);
    }
    return 0;
}
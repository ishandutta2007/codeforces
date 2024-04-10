#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int r1, c1, r2, c2;
int ans1, ans2, ans3;

int fuck(int r, int c) {
    if (r % 2 == c % 2)
    return 1;
    return 0;
}

int main() {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    ans1 = ans2 = ans3 = 0;
    if (r1 == r2 && c1 != c2)
    ans1 = 1;
    if (r1 != r2 && c1 == c2)
    ans1 = 1;
    if (r1 != r2 && c1 != c2)
    ans1 = 2;
    if (r1 - c1 == r2 - c2 && r1 + c1 != r2 + c2)
    ans2 = 1;
    if (r1 - c1 != r2 - c2 && r1 + c1 == r2 + c2)
    ans2 = 1;
    if (r1 - c1 != r2 - c2 && r1 + c1 != r2 + c2)
    ans2 = 2;
    if (fuck(r1, c1) != fuck(r2, c2)) {
    ans2 = 0;
    }
    ans3 = max(abs(r1 - r2), abs(c1 - c2));
    printf("%d %d %d\n", ans1, ans2, ans3);
    return 0;
}
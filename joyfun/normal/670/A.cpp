#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int tmp = n / 7 * 2;
    n %= 7;
    int ans1 = tmp, ans2 = tmp;
    if (n > 5) ans1 += n - 5;
    n = min(n, 2);
    ans2 += n;
    printf("%d %d\n", ans1, ans2);
    return 0;
}
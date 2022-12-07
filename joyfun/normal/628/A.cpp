#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, b, p;

int main() {
    scanf("%d%d%d", &n, &b, &p);
    int ans1 = 0, ans2 = n * p;
    while (n > 1) {
        int cnt = n / 2;
        ans1 += cnt * (2 * b + 1);
        n = (n + 1) / 2;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
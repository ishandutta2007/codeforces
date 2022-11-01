#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000];

int solve(int last, int cur) {
    int ans = 9999;
    for (int k = 1; k <= 1000; k *= 10) {
        int base = cur / (k * 10) * (k * 10) + cur % k;
        for (int i = 0; i < 10; i++) {
            int val = base + k * i;
            if (val >= last)
                ans = min(ans, val);
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    a[0] = solve(1000, a[0]);
    for (int i = 1; i < n; i++)
        a[i] = solve(a[i - 1], a[i]);

    if (a[n - 1] <= 2011) {
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i]);
    } else {
        puts("No solution");
    }
}
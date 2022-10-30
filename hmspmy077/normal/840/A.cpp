#include <algorithm>
#include <cstdio>
#include <utility>

const int N = 200000;

int a[N], ans[N];
std::pair<int, int> b[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }
    std::sort(b, b + n);
    for (int i = 0; i < n; ++ i) {
        ans[b[i].second] = a[n - 1 - i];
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
}
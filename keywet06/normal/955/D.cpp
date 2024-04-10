#include <bits/stdc++.h>

const int N = 500000;

char s[N + 5], t[N + 5];

int n, m, k, nx[N + 5], a[N + 5], b[N + 5];

void cal(int* a) {
    int i, j;
    for (i = 2, j = 0; i <= m && i <= k; nx[i++] = j) {
        while (j && t[j + 1] != t[i]) j = nx[j];
        if (t[j + 1] == t[i]) ++j;
    }
    for (i = 1, j = 0; i <= n; ++i) {
        while (j && (j == k || t[j + 1] != s[i])) j = nx[j];
        if (t[j + 1] == s[i]) ++j;
        if (j == m) {
            if (i < 2 * k) {
                printf("Yes\n1 %d\n", k + 1);
            } else {
                printf("Yes\n%d %d\n", i - k - k + 1, i - k + 1);
            }
            exit(0);
        }
        if (i - k + 1 > 0) a[j] = std::min(a[j], i);
    }
    for (i = m; i; --i) a[nx[i]] = std::min(a[nx[i]], a[i]);
}

int main() {
    scanf("%d %d %d\n%s\n%s", &n, &m, &k, s + 1, t + 1);
    memset(a, 40, sizeof(a));
    cal(a);
    for (int i = 1; i < n + 1 - i; ++i) std::swap(s[i], s[n + 1 - i]);
    for (int i = 1; i < m + 1 - i; ++i) std::swap(t[i], t[m + 1 - i]);
    memset(b, 40, sizeof(b));
    cal(b);
    for (int i = 0; i <= m; ++i) {
        if (a[i] <= n && b[m - i] <= n && a[i] < n - b[m - i] + 1) {
            return printf("Yes\n%d %d\n", a[i] - k + 1, n - b[m - i] + 1), 0;
        }
    }
    puts("No");
    return 0;
}
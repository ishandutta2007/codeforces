#include <bits/stdc++.h>
using namespace std;

#define N 311111

int a[N];
int best[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        best[n - 1] = max(best[n - 1], a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        // force max(i, i + 1)
        int j = abs(i - (n - 1 - i - 1));
        best[j] = max(best[j], max(a[i], a[i + 1]));
    }
    for (int i = 1; i < n - 1; i++) {
        // force max(min(i - 1, i), min(i, i + 1))
        int j = abs(i - 1 - (n - 1 - i - 1));
        best[j] = max(best[j], max(min(a[i - 1], a[i]), min(a[i], a[i + 1])));
    }
    for (int i = 2; i < n; i++) {
        best[i] = max(best[i], best[i - 2]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", best[i], " \n"[i == n - 1]);
    }
}
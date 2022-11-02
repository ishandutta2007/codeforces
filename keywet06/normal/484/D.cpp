#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

const int N = 1500005;

int n, ru, rd;
int w[N];

int64 d[N];

int main() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) scanf("%d", &w[i]);
    for (i = 2; i <= n; ++i) {
        if (w[i - 1] < w[i]) ru = i - 1;
        if (w[i - 1] > w[i]) rd = i - 1;
        d[i] = max(d[ru] + w[ru + 1] - w[i], d[rd] + w[i] - w[rd + 1]);
        if (ru != i - 1) d[i] = max(d[i], d[ru + 1] + w[ru + 2] - w[i]);
        if (rd != i - 1) d[i] = max(d[i], d[rd + 1] + w[i] - w[rd + 2]);
    }
    printf("%lld\n", d[n]);
    return 0;
}
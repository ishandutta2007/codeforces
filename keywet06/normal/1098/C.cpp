#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 100005;

int64 s;
int64 a[N];
int p[N];
int deg[N];

int64 getMin(int64 n, int64 k) {
    int64 res = 1;
    int64 m = 1;
    int64 h = 1;
    --n;
    while (n > 0) {
        m *= k;
        m = min(m, n);
        ++h;
        res += h * m;
        n -= m;
    }
    return res;
}

int main() {
    int64 n;
    scanf("%lld%lld", &n, &s);
    if (s > n * (n + 1) / 2) {
        printf("No\n");
        return 0;
    }
    if (s < 2 * n - 1) {
        printf("No\n");
        return 0;
    }
    int k = 1;
    while (getMin(n, k) > s) ++k;
    for (int i = 1; i <= n; ++i) a[i] = 1;
    s = n * (n + 1) / 2 - s;
    int pos = 2;
    for (int i = n; s > 0; --i) {
        while (a[pos] / k >= a[pos - 1]) ++pos;
        if (i - pos <= s) {
            s -= i - pos;
            ++a[pos];
            --a[i];
            continue;
        }
        ++a[i - s];
        --a[i];
        break;
    }
    int l = 0, r = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0) break;
        int nl = r;
        int nr = nl + a[i];
        for (int v = nl; v < nr; ++v) {
            if (deg[l] == k) ++l;
            p[v] = l;
            ++deg[l];
        }
        l = nl;
        r = nr;
    }
    printf("Yes\n");
    for (int i = 1; i < n; ++i) printf("%d ", p[i] + 1);
    printf("\n");

    return 0;
}
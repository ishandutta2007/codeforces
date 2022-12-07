#include <stdio.h>
#include <string.h>

const int N = 200005;
__int64 n, i, j;
__int64 a[N];

int main() {
    __int64 ans = 0;
    scanf("%I64d", &n);
    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    i = 0;
    __int64 s1 = 0;
    while (i < n) {
        s1 = 0;
        while (a[i] == -1 && i < n) {
            s1++;
            i++;
        }
        __int64 s = i;
        if (i < n)
            i++;
        while (a[i] == -1 && i < n) {
            i++;
        }
        if (i == n) {
            ans++;
            break;
        }
        __int64 e = i, d;
        if ((a[e] - a[s]) % (e - s) == 0) {
            d = (a[e] - a[s]) / (e - s);
        }
        else {
            ans++;
            continue;
        }
        if (d > 0 && s1 > (a[s] - 1) / d) {
            ans++;
            i = e;
            continue;
        }
        __int64 sum = a[s];
        for (j = s + 1; j < n; j++) {
            sum += d;
            if (sum < 1) {
                i = j;
                ans++;
                break;
            }
            if (a[j] != -1 && sum != a[j]) {
                i = j;
                ans++;
                break;
            }
        }
        if (j == n) {
            i = n;
            ans++;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
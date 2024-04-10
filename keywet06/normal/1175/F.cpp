#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

mt19937 rnd(time(NULL));

int n;
int a[N];

long long hsh[N], h[N], sumhsh[N];

int calc() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) h[i] = h[i - 1] ^ hsh[a[i]];
    for (int i = 1, j = 1; i <= n; ++i) {
        if (a[i] == 1) {
            j = 1;
        } else {
            j = max(j, a[i]);
            ans += (j <= i && (h[i] ^ h[i - j]) == sumhsh[j]);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) hsh[i] = rnd();
    for (int i = 1; i <= n; ++i) sumhsh[i] = sumhsh[i - 1] ^ hsh[i];
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    ans += calc();
    reverse(a + 1, a + n + 1);
    ans += calc();
    for (int i = 1; i <= n; ++i) ans += (a[i] == 1);
    printf("%d\n", ans);
    return 0;
}
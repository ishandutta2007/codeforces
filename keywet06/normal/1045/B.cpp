#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 600600;
int n, m, ans;
int a[N], s[N], z[N], f[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n] = a[0] + m;
    for (int i = 0; i < n; i++) s[i] = a[i + 1] - a[i];
    s[n] = -1;
    for (int i = 0; i < n; i++) s[2 * n - i] = s[i];
    for (int i = 2 * n + 1; i <= 3 * n; i++) s[i] = s[i - n];
    int l = 0, r = 0;
    for (int i = 1; i <= 3 * n; i++) {
        if (i < r) z[i] = z[i - l];
        while (i + z[i] <= 3 * n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        if (z[i] < n) continue;
        f[ans++] = ((ll)a[0] + a[2 * n - i + 1]) % m;
    }
    sort(f, f + ans);
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++) printf("%d ", f[i]);
    if (ans > 0) printf("\n");
    return 0;
}